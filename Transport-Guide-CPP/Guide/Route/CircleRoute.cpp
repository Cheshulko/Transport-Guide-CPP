//
//  CircleRoute.cpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 02.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#include "CircleRoute.hpp"

#include <cassert>
#include <algorithm>

namespace guide::route {

CircleRoute::CircleRoute(const std::string& name, const std::vector<std::shared_ptr<Stop>>& stops)
    : Route(Route::Type::Circle)
    , name_(name)
{
    uniqueStops_.insert(stops.cbegin(), stops.cend());
    std::transform(stops.cbegin(), stops.cend(), std::back_inserter(stops_), [this](auto& stop) {
        return *uniqueStops_.find(stop);
    });
}

CircleRoute::CircleRoute(const std::string& name)
    : Route(Route::Type::Circle)
    , name_(name)
{}

CircleRoute::~CircleRoute()
{}

const std::string& CircleRoute::GetName() const
{
    return name_;
}

const std::vector<std::weak_ptr<Stop>>& CircleRoute::GetRouteStops() const
{
    return stops_;
}

std::vector<std::shared_ptr<Stop>> CircleRoute::GetUniqueStops() const
{
    return std::vector<std::shared_ptr<Stop>>(uniqueStops_.begin(), uniqueStops_.end());
}

double CircleRoute::GetDistance() const
{
    double routeLength = 0.0;
    for (auto it = stops_.cbegin(); it != stops_.cend(); ++it) {
        if (auto nextTo = std::next(it); nextTo != stops_.cend()) {
            auto geoCurOpt = (*it).lock()->GetGeoPoint();
            auto geoNextOpt = (*nextTo).lock()->GetGeoPoint();
            
            assert(geoCurOpt.has_value());
            assert(geoNextOpt.has_value());
            
            routeLength += geoCurOpt.value().DistanceTo(geoNextOpt.value());
        }
    }
    
    return routeLength;
}

bool CircleRoute::Contains(const Stop& stop) const
{
    throw std::logic_error("Unimplemented");
}

}
