//
//  OptimalRouteResponseData.cpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 12.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#include "OptimalRouteResponseData.hpp"

namespace guide::interaction::response::data {

OptimalRouteResponseData::OptimalRouteResponseData(std::optional<size_t> id)
    : id_(id)
{}

std::optional<size_t> OptimalRouteResponseData::GetRequestId() const
{
    return id_;
}

}
