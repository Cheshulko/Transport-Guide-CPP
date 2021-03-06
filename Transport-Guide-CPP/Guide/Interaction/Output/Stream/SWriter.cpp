//
//  SWriter.cpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 03.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#include "SWriter.hpp"
#include "RouteInfoResponse.hpp"
#include "StopCrossingRoutesResponse.hpp"
#include "OptimalRouteResponse.hpp"
#include "ErrorResponse.hpp"

#include <iostream>
#include <iomanip>

namespace guide::interaction::output::stream {

SWriter::SWriter(std::ostream& os)
    : os_(os)
{}

void SWriter::WriteRouteInfoResponse(const response::RouteInfoResponse& routeInfoResponse)
{
    const auto& routeInfoResponseData = routeInfoResponse.GetRouteInfoResponseData();
    os_ << "Bus " << routeInfoResponseData.GetRouteNumber()    << ": "
                  << routeInfoResponseData.GetStopsCnt()       << " stops on route, "
                  << routeInfoResponseData.GetUniqueStopsCnt() << " unique stops, "
                  << std::setprecision(6)
                  << routeInfoResponseData.GetRoutePracticalLength() << " route length, ";
    
    const double curvature = routeInfoResponseData.GetRoutePracticalLength() / routeInfoResponseData.GetRouteLength();
    
              os_ << std::setprecision(7)
                  << curvature << " curvature" << std::endl;
}

void SWriter::WriteStopCrossingRoutesResponse(const response::StopCrossingRoutesResponse& stopCrossingRoutesResponse)
{
    const auto& crossingRoutesResponseData = stopCrossingRoutesResponse.GetStopCrossingRoutesResponseData();
    os_ << "Stop " << crossingRoutesResponseData.GetStopName() << ":";
    
    const auto& crossingRoutesNames = crossingRoutesResponseData.GetCrossingRoutesNames();
    if (crossingRoutesNames.size() == 0) {
        os_  << " no buses" << std::endl;
        
    } else {
        os_  << " buses";
        for (const auto& crossingRouteName: crossingRoutesNames) {
            os_ << " " << crossingRouteName;
        }
        os_ << std::endl;
    }
}

void SWriter::WriteOptimalRouteResponse(const response::OptimalRouteResponse& optimalRouteResponse)
{
    throw std::logic_error("Unimplemented");
}

void SWriter::WriteErrorResponse(const response::ErrorResponse& errorResponse)
{
    throw std::logic_error("Unimplemented");
}

}
