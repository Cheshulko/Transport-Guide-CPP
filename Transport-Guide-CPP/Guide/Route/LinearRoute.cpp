//
//  LinearRoute.cpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 02.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#include "LinearRoute.hpp"

#include <numeric>
#include <cassert>
#include <algorithm>

namespace guide::route {

LinearRoute::LinearRoute(const std::string& number, const std::vector<std::shared_ptr<Stop>>& stops)
    : Route(Route::Type::Linear)
    , number_(number)
{
    uniqueStops_.insert(stops.cbegin(), stops.cend());
    std::transform(stops.cbegin(), stops.cend(), std::back_inserter(stops_), [this](auto& stop) {
        return *uniqueStops_.find(stop);
    });
}

LinearRoute::LinearRoute(const std::string& number)
    : Route(Route::Type::Linear)
    , number_(number)
{}

LinearRoute::~LinearRoute()
{}

const std::string& LinearRoute::GetNumber() const
{
    return number_;
}

const std::vector<std::weak_ptr<Stop>>& LinearRoute::GetRouteStops() const
{
    return stops_;
}

std::vector<std::shared_ptr<Stop>> LinearRoute::GetUniqueStops() const
{
    return std::vector<std::shared_ptr<Stop>>(uniqueStops_.begin(), uniqueStops_.end());
}

double LinearRoute::GetDistance() const
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

bool LinearRoute::Contains(const Stop& stop) const
{
    throw std::logic_error("Unimplemented");
}

}
