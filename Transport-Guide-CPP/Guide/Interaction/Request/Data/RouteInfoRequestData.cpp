//
//  RouteInfo.cpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 03.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#include "RouteInfoRequestData.hpp"

namespace guide::interaction::request::data {

RouteInfoRequestData::RouteInfoRequestData(const std::string& name, std::optional<size_t> id)
    : name_(name)
    , id_(id)
{}

const std::string& RouteInfoRequestData::GetRouteName() const
{
    return name_;
}

std::optional<size_t> RouteInfoRequestData::GetRouteId() const
{
    return id_;
}

}
