//
//  StopCrossingRoutesResponse.cpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 05.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#include "StopCrossingRoutesResponse.hpp"

namespace guide::interaction::response {

StopCrossingRoutesResponse::StopCrossingRoutesResponse(const data::StopCrossingRoutesResponseData& crossingRoutesResponseData)
    : crossingRoutesResponseData_(crossingRoutesResponseData)
{}

const data::StopCrossingRoutesResponseData& StopCrossingRoutesResponse::GetStopCrossingRoutesResponseData() const
{
    return crossingRoutesResponseData_;
}

void StopCrossingRoutesResponse::WriteOuptut(output::Writer& writer) const
{
    writer.WriteStopCrossingRoutesResponse(*this);
}

}
