//
//  OptimalRouteResponse.hpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 12.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#ifndef OptimalRouteResponse_hpp
#define OptimalRouteResponse_hpp

#include "Writer.hpp"
#include "OptimalRouteResponseData.hpp"

namespace guide::interaction::response {

class OptimalRouteResponse: public Response
{
public:
    explicit OptimalRouteResponse(const data::OptimalRouteResponseData& optimalRouteResponseData);
    
    const data::OptimalRouteResponseData& GetOptimalRouteResponseData() const;
    
    virtual void WriteOuptut(output::Writer& writer) const override;

private:
    data::OptimalRouteResponseData optimalRouteResponseData_;
};

}

#endif /* OptimalRouteResponse_hpp */
