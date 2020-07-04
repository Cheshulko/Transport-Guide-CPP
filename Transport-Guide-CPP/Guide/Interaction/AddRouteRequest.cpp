//
//  AddRouteRequest.cpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 02.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#include "AddRouteRequest.hpp"
#include "EmptyResponse.hpp"

#include "Stop.hpp"
#include "LinearRoute.hpp"
#include "CircleRoute.hpp"
#include <vector>

namespace guide::interaction {

AddRouteRequest::AddRouteRequest(std::shared_ptr<route::Route> route)
    : Request(Request::Type::AddStop)
    , route_(std::move(route))
{}

std::shared_ptr<output::Response> AddRouteRequest::PerformOn(route::RoutesMap& routesMap) const
{
    if (auto routeWeakOpt = routesMap.FindRoute(route_->GetNumber()); routeWeakOpt.has_value()) {
        
    } else {
        std::vector<std::shared_ptr<route::Stop>> stops;
        
        for (auto& stop: route_->GetUniqueStops()) {
            routesMap.AddStop(stop);
        }
        
        for (auto& stop: route_->GetRouteStops()) {
            auto stopPtr = routesMap.FindStop(stop.lock()).value().lock();
            assert(stopPtr != nullptr);
            stops.push_back(stopPtr);
        }

        switch (route_->GetRouteType()) {
            case route::Route::Type::Linear:
                routesMap.AddRoute(std::make_shared<route::LinearRoute>(route_->GetNumber(), std::move(stops)));
                break;
            case route::Route::Type::Circle:
                routesMap.AddRoute(std::make_shared<route::CircleRoute>(route_->GetNumber(), std::move(stops)));
                break;
            default:
                break;
        }
    }

    return std::make_shared<output::EmptyResponse>();
}

}
