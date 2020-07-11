//
//  OptimalRouteRequestData.cpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 11.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#include "OptimalRouteRequestData.hpp"

namespace guide::interaction::request::data {

OptimalRouteRequestData::OptimalRouteRequestData(const std::string& fromStopName, const std::string& toStopName, std::optional<size_t> id)
    : fromStopName_(fromStopName)
    , toStopName_(toStopName)
    , id_(id)
{}

const std::string& OptimalRouteRequestData::GetFromStopName() const
{
    return fromStopName_;
}

const std::string& OptimalRouteRequestData::GetToStopName() const
{
    return toStopName_;
}

std::optional<size_t> OptimalRouteRequestData::GetId() const
{
    return id_;
}

}
