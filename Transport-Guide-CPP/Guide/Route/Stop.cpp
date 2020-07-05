//
//  Stop.cpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 02.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#include "Stop.hpp"

namespace guide::route {

Stop::Stop(std::string name, const GeoPoint& geoPoint)
    : name_(std::move(name))
    , geoPoint_(geoPoint)
    , completion_(Stop::Completion::Complete)
{}

Stop::Stop(std::string name)
    : name_(std::move(name))
    , completion_(Stop::Completion::Nocoord)
{}

void Stop::SetGeoPoint(const GeoPoint& geoPoint)
{
    this->geoPoint_ = geoPoint;
    this->completion_ = Stop::Completion::Complete;
}

bool Stop::AddCrossingRoute(std::weak_ptr<Route> route)
{
    crossingRoutes_.push_back(route);
    return true;
}

bool Stop::AddNeighborStopsDistance(std::weak_ptr<Stop> stop, size_t distance)
{
    auto [_, ok] = neighborStopsDistances_.insert({ stop, distance });
    return ok;
}

bool Stop::UpdateNeighborStopsDistance(std::weak_ptr<Stop> stop, size_t distance)
{
    if (auto stopPtr = neighborStopsDistances_.find(stop); stopPtr != neighborStopsDistances_.end()) {
        stopPtr->second = distance;
        return true;
    }
    return false;
}

std::optional<size_t> Stop::FindNeighborStopDistance(std::shared_ptr<Stop> stop) const
{
    if (auto stopPtr = neighborStopsDistances_.find(stop); stopPtr != neighborStopsDistances_.end()) {
        return stopPtr->second;
    }
    return std::nullopt;
}

const std::string& Stop::GetName() const
{
    return name_;
}

std::optional<GeoPoint> Stop::GetGeoPoint() const
{
    return geoPoint_;
}

const std::vector<std::weak_ptr<Route>>& Stop::GetCrossingRoutes() const
{
    return crossingRoutes_;
}

const std::map<std::weak_ptr<Stop>, size_t, Stop::WeakComparator>& Stop::GetNeighborStopsDistances() const
{
    return neighborStopsDistances_;
}

bool Stop::IsComplete() const
{
    return this->completion_ == Stop::Completion::Complete;
}

bool Stop::operator==(const Stop& rhs) const
{
    return this->name_ == rhs.GetName();
}

bool Stop::operator<(const Stop& rhs) const
{
    return std::lexicographical_compare(
        this->GetName().cbegin(), this->GetName().cend(),
        rhs.GetName().cbegin(), rhs.GetName().cend());
}

std::ostream& operator<<(std::ostream& os, const Stop& stop)
{
    os << std::string{ "`Stop`(" } << stop.GetName();
    
    if (auto geoPointOpt = stop.GetGeoPoint(); geoPointOpt.has_value()) {
        os << std::string{ ", " } << std::to_string(geoPointOpt.value().GetLatitude());
        os << std::string{ ", " } << std::to_string(geoPointOpt.value().GetLongitude());
    }
    
    os << std::string{ ")" };

    return os;
}

}
