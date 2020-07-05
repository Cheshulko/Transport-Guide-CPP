//
//  RouteInfo.cpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 03.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#include "RouteInfoRequestData.hpp"

namespace guide::interaction::request::data {

RouteInfoRequestData::RouteInfoRequestData(const std::string& number)
    : number_(number)
{}

const std::string& RouteInfoRequestData::GetRouteNumber() const
{
    return number_;
}

}
