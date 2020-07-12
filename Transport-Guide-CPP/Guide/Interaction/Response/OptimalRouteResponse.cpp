//
//  OptimalRouteResponse.cpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 12.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#include "OptimalRouteResponse.hpp"

namespace guide::interaction::response {

OptimalRouteResponse::OptimalRouteResponse(const data::OptimalRouteResponseData& optimalRouteResponseData)
    : optimalRouteResponseData_(optimalRouteResponseData)
{}

const data::OptimalRouteResponseData& OptimalRouteResponse::GetOptimalRouteResponseData() const
{
    return optimalRouteResponseData_;
}

void OptimalRouteResponse::WriteOuptut(output::Writer& writer) const
{
    writer.WriteOptimalRouteResponse(*this);
}

}
