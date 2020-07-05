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
#include "AddStopRequestData.hpp"

namespace guide::interaction::request {

class AddStopRequest: public Request
{
public:
    explicit AddStopRequest(std::shared_ptr<data::AddStopRequestData> addStopRequestData);
    
    virtual std::shared_ptr<response::Response> PerformOn(route::RoutesMap& routesMap) const override;
    
private:
    std::shared_ptr<data::AddStopRequestData> addStopRequestData_;
};

}

#endif /* AddStopRequest_hpp */
