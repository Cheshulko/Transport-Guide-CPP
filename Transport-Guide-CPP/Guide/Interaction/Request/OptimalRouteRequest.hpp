//
//  OptimalRouteRequest.hpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 11.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#ifndef OptimalRouteRequest_hpp
#define OptimalRouteRequest_hpp

#include "Request.hpp"
#include "OptimalRouteRequestData.hpp"

namespace guide::interaction::request {

class OptimalRouteRequest: public Request
{
public:
    explicit OptimalRouteRequest(std::shared_ptr<data::OptimalRouteRequestData> optimalRouteRequestData);
    
    virtual std::shared_ptr<response::Response> PerformOn(route::RoutesMap& routesMap) const override;
    
private:
    std::shared_ptr<data::OptimalRouteRequestData> optimalRouteRequestData_;
};

}

#endif /* OptimalRouteRequest_hpp */
