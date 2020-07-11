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
    
    const auto& optimalRouteInfo = routesMap.GetOptimalRoute(fromStop, toStop);
    
    std::cout << "ID="<< optimalRouteRequestData_->GetId().value() << std::endl;
    
    for (const auto& [
        fromStopWeak,
        toStopWeak,
        routeTime,
        routeWeak
    ] : optimalRouteInfo) {
        auto fromStop = fromStopWeak.lock();
        auto toStop   = toStopWeak.lock();
        auto route    = routeWeak.lock();
        
        assert(fromStop != nullptr);
        assert(toStop   != nullptr);
        assert(route    != nullptr);
        
        std::cout << fromStop->GetName() << "->" << toStop->GetName() << " t:" << routeTime << " on " << route->GetName() << std::endl;
        
    }
    
    std::cout << std::endl;
    
    return std::make_shared<response::OptimalRouteResponse>(optimalRouteRequestData_->GetId());
}

}
