//
//  BusInfoRequest.hpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 02.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#ifndef BusInfoRequest_hpp
#define BusInfoRequest_hpp

#include "Request.hpp"

namespace guide::interaction {

class RouteInfoRequest: public Request
{
public:
    virtual void Perform(const route::RoutesMap& routesMap) const override;
};

}

#endif /* BusInfoRequest_hpp */
