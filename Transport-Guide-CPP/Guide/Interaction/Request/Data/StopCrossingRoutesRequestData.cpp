//
//  StopCrossingRoutesReqeustData.cpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 05.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#include "StopCrossingRoutesRequestData.hpp"

namespace guide::interaction::request::data {

StopCrossingRoutesRequestData::StopCrossingRoutesRequestData(const std::string& stopName)
    : stopName_(stopName)
{}

const std::string& StopCrossingRoutesRequestData::GetStopName() const
{
    return stopName_;
}

}
