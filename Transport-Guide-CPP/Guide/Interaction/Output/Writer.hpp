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

namespace guide::interaction::output {
    class RouteInfoResponse;
}

namespace guide::interaction::output {

class Writer
{
public:
    virtual void WriteRouteInfoResponse(const RouteInfoResponse& routeInfoResponse) = 0;
};

}

#endif /* Writer_h */
