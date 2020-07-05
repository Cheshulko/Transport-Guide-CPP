//
//  AddStopRequest.hpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 02.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#ifndef AddStopRequest_hpp
#define AddStopRequest_hpp

#include "Request.hpp"
#include "Stop.hpp"

namespace guide::interaction::request {

class AddStopRequest: public Request
{
public:
    AddStopRequest(std::shared_ptr<route::Stop> stop);
    
    virtual std::shared_ptr<response::Response> PerformOn(route::RoutesMap& routesMap) const override;
    
private:
    std::shared_ptr<route::Stop> stop_;
};

}

#endif /* AddStopRequest_hpp */
