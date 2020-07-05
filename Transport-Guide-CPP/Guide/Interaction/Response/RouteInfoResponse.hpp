//
//  RouteInfoResponse.hpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 03.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#ifndef RouteInfoResponse_hpp
#define RouteInfoResponse_hpp

#include "Writer.hpp"
#include "RouteInfoResponseData.hpp"

namespace guide::interaction::response {

class RouteInfoResponse: public Response
{
public:
    explicit RouteInfoResponse(const data::RouteInfoResponseData& routeInfoResponseData);
    
    const data::RouteInfoResponseData& GetRouteInfoResponseData() const;
    
    virtual void WriteOuptut(output::Writer& writer) const override;

private:
    data::RouteInfoResponseData routeInfoResponseData_;
};

}

#endif /* RouteInfoResponse_hpp */
