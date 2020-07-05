//
//  AddStopRequest.cpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 02.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#include "AddStopRequest.hpp"
#include "EmptyResponse.hpp"
#include "Stop.hpp"

#include <memory>

namespace guide::interaction::request {

AddStopRequest::AddStopRequest(std::shared_ptr<data::AddStopRequestData> addStopRequestData)
    : Request(Request::Type::AddStop)
    , addStopRequestData_(std::move(addStopRequestData))
{}

std::shared_ptr<response::Response> AddStopRequest::PerformOn(route::RoutesMap& routesMap) const
{
    const auto& stopName = addStopRequestData_->GetStopName();
    const auto& geoPoint = addStopRequestData_->GetGeoPoint();
    
    if (auto stopWeakOpt = routesMap.FindStop(stopName); stopWeakOpt.has_value()) {
        if (auto stopFound = stopWeakOpt.value().lock(); stopFound != nullptr)
        {
            if (!stopFound->IsComplete()) {
                stopFound->SetGeoPoint(geoPoint);
            }

        }
    } else {
        routesMap.AddStop(std::make_shared<route::Stop>(stopName, geoPoint));
    }
    
    return std::make_shared<response::EmptyResponse>();
}

}
