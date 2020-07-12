//
//  OptimalRouteRequest.cpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 11.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#include "OptimalRouteRequest.hpp"

#include "OptimalRouteResponse.hpp"
#include "OptimalRouteResponseData.hpp"

#include "ErrorResponse.hpp"
#include "ErrorResponseData.hpp"

#include <cassert>
#include <iostream>

namespace guide::interaction::request {

OptimalRouteRequest::OptimalRouteRequest(std::shared_ptr<data::OptimalRouteRequestData> optimalRouteRequestData)
    : Request(Request::Type::OptimalRoute)
    , optimalRouteRequestData_(optimalRouteRequestData)
{}

std::shared_ptr<response::Response> OptimalRouteRequest::PerformOn(route::RoutesMap& routesMap) const
{
    auto fromStopOpt = routesMap.FindStop(optimalRouteRequestData_->GetFromStopName());
    auto toStopOpt = routesMap.FindStop(optimalRouteRequestData_->GetToStopName());
    
    assert(fromStopOpt.has_value());
    assert(toStopOpt.has_value());
    
    auto fromStop = fromStopOpt.value().lock();
    auto toStop = toStopOpt.value().lock();
    
    assert(fromStop != nullptr);
    assert(toStop != nullptr);
    
    response::data::OptimalRouteResponseData optimalRouteResponseData { optimalRouteRequestData_->GetId() };
    
    const auto& optimalRouteInfoOpt = routesMap.GetOptimalRoute(fromStop, toStop);
    
    if (optimalRouteInfoOpt.has_value()) {
        auto optimalRouteInfo = optimalRouteInfoOpt.value();
        
        for (const auto& [
            fromStopWeak,
            toStopWeak,
            routeTime,
            routeWeak,
            stopsCnt
        ] : optimalRouteInfo) {
            auto fromStop = fromStopWeak.lock();
            auto toStop   = toStopWeak.lock();
            auto route    = routeWeak.lock();
            
            assert(fromStop != nullptr);
            assert(toStop   != nullptr);
            assert(route    != nullptr);
            
            optimalRouteResponseData.AddItem(
                  std::make_shared<response::data::OptimalRouteResponseData::WaitItem>(
                       routesMap.GetSettings().GetBusWaitTime(),
                       fromStop->GetName(),
                       1
                  )
            );
            optimalRouteResponseData.AddItem(
                  std::make_shared<response::data::OptimalRouteResponseData::BusItem>(
                       routeTime - routesMap.GetSettings().GetBusWaitTime(),
                       route->GetName(),
                       stopsCnt
                  )
            );
        }
    } else {
        return std::make_shared<response::ErrorResponse>( response::data::ErrorResponseData {
            std::string{ "not found" },
            optimalRouteRequestData_->GetId()
        });
    }
    return std::make_shared<response::OptimalRouteResponse>(optimalRouteResponseData);
}

}
