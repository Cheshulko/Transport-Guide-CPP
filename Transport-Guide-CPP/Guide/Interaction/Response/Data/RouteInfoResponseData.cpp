//
//  RouteInfoResponseData.cpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 03.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#include "RouteInfoResponseData.hpp"

namespace guide::interaction::response::data {

RouteInfoResponseData::RouteInfoResponseData(const std::string& number, std::size_t stopsCnt,
                                             std::size_t uniqueStopsCnt, double routeLength)
    : number_(number)
    , stopsCnt_(stopsCnt)
    , uniqueStopsCnt_(uniqueStopsCnt)
    , routeLength_(routeLength)
{}

const std::string& RouteInfoResponseData::GetRouteNumber() const
{
    return number_;
}

std::size_t RouteInfoResponseData::GetStopsCnt() const
{
    return stopsCnt_;
}

std::size_t RouteInfoResponseData::GetUniqueStopsCnt() const
{
    return uniqueStopsCnt_;
}

double RouteInfoResponseData::GetRouteLength() const
{
    return routeLength_;
}

}
