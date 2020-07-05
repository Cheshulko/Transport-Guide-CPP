//
//  AddRouteRequest.hpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 02.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#ifndef AddRouteRequest_hpp
#define AddRouteRequest_hpp

#include "Request.hpp"
#include "Route.hpp"

namespace guide::interaction::request {

class AddRouteRequest: public Request
{
public:
    AddRouteRequest(std::shared_ptr<route::Route> route);
    
    virtual std::shared_ptr<response::Response> PerformOn(route::RoutesMap& routesMap) const override;
    
private:
    std::shared_ptr<route::Route> route_;
};

}

#endif /* AddRouteRequest_hpp */
