//
//  BusInfoRequest.cpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 02.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#include "RouteInfoRequest.hpp"
#include "RouteInfoResponse.hpp"
#include "RouteInfoResponseData.hpp"

#include "NoRouteException.hpp"

#include <iostream>
#include <cassert>

namespace guide::interaction::request {

RouteInfoRequest::RouteInfoRequest(std::shared_ptr<data::RouteInfoRequestData> routeInfo)
    : Request(Request::Type::AddStop)
    , routeInfo_(std::move(routeInfo))
{}

std::shared_ptr<response::Response> RouteInfoRequest::PerformOn(route::RoutesMap& routesMap) const
{
    if (auto routeWeakOpt = routesMap.FindRoute(routeInfo_->GetRouteName()); routeWeakOpt.has_value()) {
        auto routePtr = routeWeakOpt.value().lock();
        assert(routePtr != nullptr);
        const auto name = routePtr->GetName();
        const auto stopsCnt = routePtr->GetRouteStops().size();
        const auto uniqueStopsCnt = routePtr->GetUniqueStops().size();
        const auto routeLength = routePtr->GetDistance();
        const auto practicalLength = routePtr->GetPracticalDistance();
        
        return std::make_shared<response::RouteInfoResponse>( response::data::RouteInfoResponseData {
            name, stopsCnt, uniqueStopsCnt, routeLength, practicalLength
        });
    } else {
        throw exception::NoRouteException("Bus " + routeInfo_->GetRouteName() + ": not found");
    }
}

}
