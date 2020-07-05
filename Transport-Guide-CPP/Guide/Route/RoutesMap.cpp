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

namespace guide::route {

RoutesMap::RoutesMap()
{}

RoutesMap::RoutesMap(std::vector<std::shared_ptr<Route>> routes, std::vector<std::shared_ptr<Stop>> stops)
{
    routes_.insert(routes.begin(), routes.end());
    stops_.insert(stops.begin(), stops.end());
}

bool RoutesMap::AddStop(std::shared_ptr<Stop> stop)
{
    auto [_, ok] = stops_.insert(stop);
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

}
