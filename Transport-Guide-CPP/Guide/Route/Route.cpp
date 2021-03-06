//
//  Route.cpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 02.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#include "Route.hpp"

#include <cassert>
#include <limits>

namespace guide::route {

Route::Route(Route::Type type)
    : type_(type)
{}

double Route::GetDistance() const
{
    double routeLength = 0.0;
    const auto& stops = GetRouteStops();
    
    for (auto it = stops.cbegin(); it != stops.cend(); ++it) {
        if (auto nextTo = std::next(it); nextTo != stops.cend()) {
            auto geoCurOpt = (*it).lock()->GetGeoPoint();
            auto geoNextOpt = (*nextTo).lock()->GetGeoPoint();
            
            assert(geoCurOpt.has_value());
            assert(geoNextOpt.has_value());
            
            routeLength += geoCurOpt.value().DistanceTo(geoNextOpt.value());
        }
    }
    
    return routeLength;
}

double Route::GetPracticalDistance() const
{
    double routePracticalLength = 0.0;
    const auto& stops = GetRouteStops();
    
    for (auto it = stops.cbegin(); it != stops.cend(); ++it) {
        if (auto nextTo = std::next(it); nextTo != stops.cend()) {
            auto neighborStopDistanceOpt = (*it).lock()->FindNeighborStopDistance((*nextTo).lock());
            
            assert(neighborStopDistanceOpt.has_value());
            
            routePracticalLength += neighborStopDistanceOpt.value();
        }
    }
    
    return routePracticalLength;
}

std::pair<size_t, double> Route::GetPracticalDistanceBetweenStops(std::shared_ptr<Stop> from, std::shared_ptr<Stop> to) const
{
    double routePracticalLength = 0.0;
    size_t cnt = 0;
    
    const auto& stops = GetRouteStops();
    
    auto it = stops.cbegin();
    while(it != stops.cend() && (*it).lock() != from) {
        ++it;
    }
    
    std::pair<size_t, double> res = { 0, std::numeric_limits<double>::max() };
    
    for (; it != stops.cend() && std::next(it) != stops.cend(); ++it) {
        if (auto nextTo = std::next(it); nextTo != stops.cend()) {
            
            if ((*nextTo).lock() == from) {
                routePracticalLength = 0;
                cnt = 0;
            } else {
                auto neighborStopDistanceOpt = (*it).lock()->FindNeighborStopDistance((*nextTo).lock());
                
                assert(neighborStopDistanceOpt.has_value());
                
                routePracticalLength += neighborStopDistanceOpt.value();
                ++cnt;
            }
            
            if ((*nextTo).lock() == to) {
                if (res.second > routePracticalLength) {
                    res = {cnt, routePracticalLength};
                }
            }
        }
    }
    
    return res;
}

bool Route::operator==(const Route& rhs) const
{
    return this->GetName() == rhs.GetName();
}

bool Route::operator<(const Route& rhs) const
{
    return std::lexicographical_compare(
        this->GetName().cbegin(), this->GetName().cend(),
        rhs.GetName().cbegin(), rhs.GetName().cend());
}

std::ostream& operator<<(std::ostream& os, const Route::Type& routeType)
{
    switch (routeType) {
        case Route::Type::Linear:  os << std::string{ "Linear" }; break;
        case Route::Type::Circle:  os << std::string{ "Circle" }; break;
        case Route::Type::Unknown: os << std::string{ "Unknown" }; break;
    }
    
    return os;
}

std::ostream& operator<<(std::ostream& os, const Route& route)
{
    os << std::string{ "`Route`(" }
       << route.GetName()
       << std::string{ " " } << route.GetRouteType()
       << std::string { " : \n" };
    
    for(const auto& stop: route.GetRouteStops()) {
        os << std::string(4, ' ') << *stop.lock() << std::string { "\n" };
    }
    
    os << std::string{ ")" };
    
    return os;
}

}
