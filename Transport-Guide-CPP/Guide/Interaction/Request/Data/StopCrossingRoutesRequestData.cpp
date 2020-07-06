//
//  StopCrossingRoutesReqeustData.cpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 05.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#include "StopCrossingRoutesRequestData.hpp"

namespace guide::interaction::request::data {

StopCrossingRoutesRequestData::StopCrossingRoutesRequestData(const std::string& stopName, std::optional<size_t> id)
    : stopName_(stopName)
    , id_(id)
{}

const std::string& StopCrossingRoutesRequestData::GetStopName() const
{
    return stopName_;
}

std::optional<size_t> StopCrossingRoutesRequestData::GetStopId() const
{
    return id_;
}

}
