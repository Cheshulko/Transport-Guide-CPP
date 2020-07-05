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
    const auto& neighborStopsDistances = addStopRequestData_->GetNeighborStopsDistance();
    
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
    
    auto stopWeakOpt = routesMap.FindStop(stopName);
    assert(stopWeakOpt.has_value());
    
    auto stopPtr = stopWeakOpt.value().lock();
    assert(stopPtr != nullptr);
    
    for (const auto& [distance, neighborStopName]: neighborStopsDistances) {
        
        // Add neighbor if it is not already
        if (auto neighborStopWeakOpt = routesMap.FindStop(neighborStopName); neighborStopWeakOpt.has_value()) {
        } else {
            routesMap.AddStop(std::make_shared<route::Stop>(neighborStopName));
        }
        
        auto neighborStopWeakOpt = routesMap.FindStop(neighborStopName);
        assert(neighborStopWeakOpt.has_value());
        
        auto neighborStopPtr = neighborStopWeakOpt.value().lock();
        assert(neighborStopPtr != nullptr);
        
        if (!stopPtr->AddNeighborStopsDistance(neighborStopPtr, distance)) {
            stopPtr->UpdateNeighborStopsDistance(neighborStopPtr, distance);
        }
        
        neighborStopPtr->AddNeighborStopsDistance(stopPtr, distance);
    }
    
    return std::make_shared<response::EmptyResponse>();
}

}
