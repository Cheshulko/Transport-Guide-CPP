//
//  Writer.hpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 03.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#ifndef Writer_h
#define Writer_h

#include "Response.hpp"

#include <memory>

namespace guide::interaction::response {
    class RouteInfoResponse;
    class StopCrossingRoutesResponse;
    class ErrorResponse;
    class OptimalRouteResponse;
}

namespace guide::interaction::output {

class Writer
{
public:
    virtual void WriteRouteInfoResponse(const response::RouteInfoResponse& routeInfoResponse) = 0;
    virtual void WriteStopCrossingRoutesResponse(const response::StopCrossingRoutesResponse& stopCrossingRoutesResponse) = 0;
    virtual void WriteOptimalRouteResponse(const response::OptimalRouteResponse& optimalRouteResponse) = 0;
    virtual void WriteErrorResponse(const response::ErrorResponse& errorResponse) = 0;
};

}

#endif /* Writer_h */
