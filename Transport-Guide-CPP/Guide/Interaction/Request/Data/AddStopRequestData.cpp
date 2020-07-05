//
//  AddStopRequestData.cpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 05.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#include "AddStopRequestData.hpp"

namespace guide::interaction::request::data {

AddStopRequestData::AddStopRequestData(const std::string& name, const route::GeoPoint& geoPoint)
    : name_(name)
    , geoPoint_(geoPoint)
{}

const std::string& AddStopRequestData::GetStopName() const
{
    return name_;
}

const route::GeoPoint& AddStopRequestData::GetGeoPoint() const
{
    return geoPoint_;
}

}
