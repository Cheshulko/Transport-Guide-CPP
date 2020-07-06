//
//  StopCrossingRoutesRequest.cpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 05.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#include "StopCrossingRoutesRequest.hpp"
#include "StopCrossingRoutesResponse.hpp"
#include "StopCrossingRoutesResponseData.hpp"

#include "NoStopException.hpp"

#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <algorithm>

#include <set>

namespace guide::interaction::request {

StopCrossingRoutesRequest::StopCrossingRoutesRequest(std::shared_ptr<data::StopCrossingRoutesRequestData> stopCrossing)
    : Request(Request::Type::StopCrossing)
    , stopCrossing_(std::move(stopCrossing))
{}

std::shared_ptr<response::Response> StopCrossingRoutesRequest::PerformOn(route::RoutesMap& routesMap) const
{
    if (auto stopWeakOpt = routesMap.FindStop(stopCrossing_->GetStopName()); stopWeakOpt.has_value()) {
        auto routePtr = stopWeakOpt.value().lock();
        assert(routePtr != nullptr);
        
        const auto& crossingRoutes = routePtr->GetCrossingRoutes();
        
        std::set<std::string> crossingRoutesNames_S;
        std::transform(crossingRoutes.cbegin(), crossingRoutes.cend(), std::inserter(crossingRoutesNames_S, crossingRoutesNames_S.begin()), [this](auto& crossingRouteWeak) {

            if (auto crossingRoute = crossingRouteWeak.lock(); crossingRoute != nullptr) {
                return crossingRoute->GetName();
            } else {
                // TODO: Exception for this case
                throw std::runtime_error("Error while getting crossing route for stop `"
                                         + stopCrossing_->GetStopName() + "`");
            }
        });
        
        return std::make_shared<response::StopCrossingRoutesResponse>( response::data::StopCrossingRoutesResponseData { stopCrossing_->GetStopName(), std::vector<std::string>(crossingRoutesNames_S.begin(), crossingRoutesNames_S.end()),
            stopCrossing_->GetStopId()
        });
    } else {
        throw exception::NoStopException("Stop " + stopCrossing_->GetStopName() + ": not found");
    }
}

}
