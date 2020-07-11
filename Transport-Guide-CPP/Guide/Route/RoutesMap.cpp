//
//  RoutesMap.cpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 02.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//
#include "RoutesMap.hpp"

#include <iostream>
#include <memory>
#include <algorithm>
#include <cassert>

namespace guide::route {

RoutesMap::Settings::Settings(size_t busWaitTime, size_t busVelocity)
    : busWaitTime_(busWaitTime)
    , busVelocity_(busVelocity)
{}

size_t RoutesMap::Settings::GetBusWaitTime() const
{
    return busWaitTime_;
}

size_t RoutesMap::Settings::GetBusVelocity() const
{
    return busVelocity_;
}

RoutesMap::RoutesMap()
{}

RoutesMap::RoutesMap(std::vector<std::shared_ptr<Route>> routes, std::vector<std::shared_ptr<Stop>> stops)
{
    routes_.insert(routes.begin(), routes.end());
    stops_.insert(stops.begin(), stops.end());
}

bool RoutesMap::AddStop(std::shared_ptr<Stop> stop)
{
    auto [it, ok] = stops_.insert(stop);
    if (ok) {
        stopsId_[*it] = stopsId_.size();
        idStops_.push_back(*it);
    }
    return ok;
}

bool RoutesMap::AddRoute(std::shared_ptr<Route> route)
{
    auto [_, ok] = routes_.insert(route);
    return ok;
}

std::optional<std::weak_ptr<Stop>> RoutesMap::FindStop(const std::string& name) const
{
    return FindStop(std::make_shared<Stop>(name));
}

std::optional<std::weak_ptr<Stop>> RoutesMap::FindStop(std::shared_ptr<Stop> stop) const
{
    if (auto ptr = stops_.find(stop); ptr != stops_.end()) {
        return *ptr;
    }
    return std::nullopt;
}

std::optional<std::weak_ptr<Route>> RoutesMap::FindRoute(const std::string& name) const
{
    // TODO: Optimize using set-vector
    auto ptr = std::find_if(routes_.cbegin(), routes_.cend(), [&name](const auto& route) {
        return route->GetName() == name;
    });
    if (ptr != routes_.end())
    {
        return *ptr;
    }
    
    return std::nullopt;
}

void RoutesMap::SetSettings(std::shared_ptr<Settings> settings)
{
    settings_ = settings;
}

size_t RoutesMap::GetStopsCount() const
{
    return stops_.size();
}

std::optional<size_t> RoutesMap::GetStopId(std::shared_ptr<Stop> stop) const
{
    auto it = stopsId_.find(stop);
    if (it == stopsId_.end()) {
        return std::nullopt;
    } else {
        return it->second;
    }
}

std::optional<std::weak_ptr<Stop>> RoutesMap::GetStop(size_t stopId) const
{
    if (stopId < idStops_.size()) {
        return idStops_.at(stopId);
    } else {
        return std::nullopt;
    }
}

std::optional<std::weak_ptr<Route>> RoutesMap::GetRoute(size_t routeId) const
{
    if (routeId < idRoutes_.size()) {
        return idRoutes_.at(routeId);
    } else {
        return std::nullopt;
    }
}

std::vector<std::tuple<
    std::weak_ptr<Stop>, /* From stop     */
    std::weak_ptr<Stop>, /* To stop       */
    double,              /* Time, minutes */
    std::weak_ptr<Route> /* Using route   */
>> RoutesMap::GetOptimalRoute(std::shared_ptr<Stop> fromStop, std::shared_ptr<Stop> toStop)
{
    std::vector<std::tuple<
        std::weak_ptr<Stop>,
        std::weak_ptr<Stop>,
        double,
        std::weak_ptr<Route>
    >> result;
    
    const auto fromStopId = GetStopId(fromStop);
    const auto toStopId   = GetStopId(toStop);
    
    assert(fromStopId.has_value());
    assert(toStopId.has_value());
    
    auto routeInfoOpt = router_->BuildRoute(fromStopId.value(), toStopId.value());
    if (routeInfoOpt.has_value()) {
        const auto& routeInfo = routeInfoOpt.value();
        
        for (size_t edgeIndex = 0; edgeIndex < routeInfo.edge_count; ++edgeIndex) {
            auto edgeId = router_->GetRouteEdge(routeInfo.id, edgeIndex);
            const auto& edge = graph_->GetEdge(edgeId);
            
            auto stopEdgeFrom = GetStop(edge.from);
            auto stopEdgeTo   = GetStop(edge.to);
            auto route        = GetRoute(edgeId);
            
            assert(stopEdgeFrom.has_value());
            assert(stopEdgeTo.has_value());
            assert(route.has_value());
            
            result.emplace_back(
                stopEdgeFrom.value(),
                stopEdgeTo.value(),
                edge.weight,
                GetRoute(edgeId).value()
            );
        }
    } else {
        // TODO: Handle this case
        throw std::runtime_error("No route");
    }
    
    return result;
}

void RoutesMap::BuildGraph()
{
    graph_.reset();
    graph_ = std::make_unique<structure::graph::DirectedWeightedGraph<double>>(GetStopsCount());
    
    for (const auto& route: routes_) {
        const auto& routeStops = route->GetRouteStops();
        const auto routeStopsCnt = routeStops.size();
        
        for (size_t from_ind = 0; from_ind < routeStopsCnt; ++from_ind) {
            
            auto fromStopPtr = routeStops[from_ind].lock();
            assert(fromStopPtr != nullptr);
            const auto fromStopId = GetStopId(fromStopPtr);
            assert(fromStopId.has_value());
            
            for (size_t to_ind = from_ind + 1; to_ind < routeStopsCnt; ++to_ind) {
                auto toStopPtr = routeStops[to_ind].lock();
                assert(toStopPtr != nullptr);
                const auto toStopId = GetStopId(toStopPtr);
                assert(toStopId.has_value());
                
                const auto distanse = route->GetPracticalDistanceBetweenStops(fromStopPtr, toStopPtr);
                
                auto edgeId = graph_->AddEdge({
                    .from = fromStopId.value(),
                    .to = toStopId.value(),
                    .weight = 0.06 * distanse / settings_->GetBusVelocity() + settings_->GetBusWaitTime()
                });
                
                assert(edgeId == idRoutes_.size());
                idRoutes_.push_back(route);
            }
        }
        
        router_.reset();
        router_ = std::make_unique<structure::graph::Router<double>>(*graph_);
    }
}

}
