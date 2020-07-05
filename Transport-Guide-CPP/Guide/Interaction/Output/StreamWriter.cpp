//
//  StreamWriter.cpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 03.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#include "StreamWriter.hpp"
#include "RouteInfoResponse.hpp"

#include <iostream>
#include <iomanip>

namespace guide::interaction::output {

StreamWriter::StreamWriter(std::ostream& os)
    : os_(os)
{}

void StreamWriter::WriteRouteInfoResponse(const response::RouteInfoResponse& routeInfoResponse)
{
    const auto& routeInfoResponseData = routeInfoResponse.GetRouteInfoResponseData();
    std::cout << "Bus " << routeInfoResponseData.GetRouteNumber()    << ": "
                        << routeInfoResponseData.GetStopsCnt()       << " stops on route, "
                        << routeInfoResponseData.GetUniqueStopsCnt() << " unique stops, "
                        << std::setprecision(6)
                        << routeInfoResponseData.GetRouteLength()    << " route length" << std::endl;
}

}
