//
//  OptimalRouteResponseData.cpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 12.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#include "OptimalRouteResponseData.hpp"

namespace guide::interaction::response::data {

OptimalRouteResponseData::WaitItem::WaitItem(double time, const std::string& name, size_t count)
    : type_(OptimalRouteResponseData::Item::Type::Wait)
    , time_(time)
    , name_(name)
    , count_(count)
{}

OptimalRouteResponseData::Item::Type OptimalRouteResponseData::WaitItem::GetType() const
{
    return type_;
}

double OptimalRouteResponseData::WaitItem::GetTime() const
{
    return time_;
}

const std::string& OptimalRouteResponseData::WaitItem::GetName() const
{
    return name_;
}

size_t OptimalRouteResponseData::WaitItem::GetCount() const
{
    return count_;
}

OptimalRouteResponseData::BusItem::BusItem(double time, const std::string& name, size_t count)
    : type_(OptimalRouteResponseData::Item::Type::Bus)
    , time_(time)
    , name_(name)
    , count_(count)
{}

OptimalRouteResponseData::Item::Type OptimalRouteResponseData::BusItem::GetType() const
{
    return type_;
}

double OptimalRouteResponseData::BusItem::GetTime() const
{
    return time_;
}

const std::string& OptimalRouteResponseData::BusItem::GetName() const
{
    return name_;
}

size_t OptimalRouteResponseData::BusItem::GetCount() const
{
    return count_;
}


OptimalRouteResponseData::OptimalRouteResponseData(std::optional<size_t> id)
    : id_(id)
    , time_(0)
{}

void OptimalRouteResponseData::AddItem(std::shared_ptr<OptimalRouteResponseData::Item> item)
{
    items_.push_back(item);
    time_ += item->GetTime();
}

double OptimalRouteResponseData::GetTime() const
{
    return time_;
}

const std::vector<std::shared_ptr<OptimalRouteResponseData::Item>>& OptimalRouteResponseData::GetItems() const
{
    return items_;
}

std::optional<size_t> OptimalRouteResponseData::GetRequestId() const
{
    return id_;
}

}
