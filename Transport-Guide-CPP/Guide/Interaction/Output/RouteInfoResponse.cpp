//
//  RouteInfoResponse.cpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 03.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#include "RouteInfoResponse.hpp"

namespace guide::interaction::output {

RouteInfoResponse::RouteInfoResponse(const data::RouteInfoResponseData& routeInfoResponseData)
    : routeInfoResponseData_(routeInfoResponseData)
{}

const data::RouteInfoResponseData& RouteInfoResponse::GetRouteInfoResponseData() const
{
    return routeInfoResponseData_;
}

void RouteInfoResponse::WriteOuptut(Writer& writer) const
{
    writer.WriteRouteInfoResponse(*this);
}

}
