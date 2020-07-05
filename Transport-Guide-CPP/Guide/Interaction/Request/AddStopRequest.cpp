//
//  AddStopRequest.cpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 02.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#include "AddStopRequest.hpp"
#include "EmptyResponse.hpp"

namespace guide::interaction::request {

AddStopRequest::AddStopRequest(std::shared_ptr<route::Stop> stop)
    : Request(Request::Type::AddStop)
    , stop_(std::move(stop))
{}

std::shared_ptr<response::Response> AddStopRequest::PerformOn(route::RoutesMap& routesMap) const
{
    if (auto stopWeakOpt = routesMap.FindStop(stop_); stopWeakOpt.has_value()) {
        if (auto stopFound = stopWeakOpt.value().lock();
            !stopFound->IsComplete())
        {
            if (auto geoPointOpt = stop_->GetGeoPoint(); geoPointOpt.has_value()) {
                stopFound->SetGeoPoint(stop_->GetGeoPoint().value());
            }
        }
    } else {
        routesMap.AddStop(stop_);
    }
    
    return std::make_shared<response::EmptyResponse>();
}

}
