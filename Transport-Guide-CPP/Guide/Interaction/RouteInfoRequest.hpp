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
#include "RouteInfoRequestData.hpp"

namespace guide::interaction {

class RouteInfoRequest: public Request
{
public:
    RouteInfoRequest(std::shared_ptr<data::RouteInfoRequestData> routeInfo);
    
    virtual std::shared_ptr<output::Response> PerformOn(route::RoutesMap& routesMap) const override;
    
private:
    std::shared_ptr<data::RouteInfoRequestData> routeInfo_;
};

}

#endif /* BusInfoRequest_hpp */
