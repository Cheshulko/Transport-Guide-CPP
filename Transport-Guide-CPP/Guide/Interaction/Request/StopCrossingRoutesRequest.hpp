//
//  StopCrossingRoutesRequest.hpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 05.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#ifndef StopCrossingRoutesRequest_hpp
#define StopCrossingRoutesRequest_hpp

#include "Request.hpp"
#include "StopCrossingRoutesRequestData.hpp"

namespace guide::interaction::request {

class StopCrossingRoutesRequest: public Request
{
public:
    StopCrossingRoutesRequest(std::shared_ptr<data::StopCrossingRoutesRequestData> stopCrossing);
    
    virtual std::shared_ptr<response::Response> PerformOn(route::RoutesMap& routesMap) const override;
    
private:
    std::shared_ptr<data::StopCrossingRoutesRequestData> stopCrossing_;
};

}

#endif /* StopCrossingRoutesRequest_hpp */
