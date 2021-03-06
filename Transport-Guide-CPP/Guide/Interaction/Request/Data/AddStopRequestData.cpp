//
//  AddStopRequestData.cpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 05.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#include "AddStopRequestData.hpp"

namespace guide::interaction::request::data {

AddStopRequestData::AddStopRequestData(const std::string& name, const route::GeoPoint& geoPoint, const std::vector<NeighborDistance>& neighborStopsDistance)
    : name_(name)
    , geoPoint_(geoPoint)
    , neighborStopsDistance_(neighborStopsDistance)
{}

const std::string& AddStopRequestData::GetStopName() const
{
    return name_;
}

const route::GeoPoint& AddStopRequestData::GetGeoPoint() const
{
    return geoPoint_;
}

const std::vector<AddStopRequestData::NeighborDistance>& AddStopRequestData::GetNeighborStopsDistance() const
{
    return neighborStopsDistance_;
}

}
