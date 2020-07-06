//
//  StopCrossingRoutesResponseData.cpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 05.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#include "StopCrossingRoutesResponseData.hpp"

namespace guide::interaction::response::data {

StopCrossingRoutesResponseData::StopCrossingRoutesResponseData(const std::string& stopName, const std::vector<std::string>& crossingRoutesNames,
                                                               std::optional<size_t> id)
    : stopName_(stopName)
    , crossingRoutesNames_(crossingRoutesNames)
    , id_(id)
{}

const std::string& StopCrossingRoutesResponseData::GetStopName() const
{
    return stopName_;
}

const std::vector<std::string>& StopCrossingRoutesResponseData::GetCrossingRoutesNames() const
{
    return crossingRoutesNames_;
}

std::optional<size_t> StopCrossingRoutesResponseData::GetStopId() const
{
    return id_;
}

}
