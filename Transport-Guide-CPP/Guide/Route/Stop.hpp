//
//  Stop.hpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 02.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#ifndef Stop_hpp
#define Stop_hpp

#include "GeoPoint.hpp"
#include "Route.hpp"

#include <string>
#include <optional>
#include <memory>
#include <cassert>
#include <iostream>
#include <vector>
#include <map>

namespace guide::route {
    class Route;
}

namespace guide::route {

class Stop
{
public:
    enum class Completion: size_t
    {
        Complete,
        Nocoord
    };
    
    struct SharedComparator
    {
        bool operator()(
            const std::shared_ptr<Stop>& a,
            const std::shared_ptr<Stop>& b) const
        {
            return *a < *b;
        }
    };
    
    struct WeakComparator
    {
        bool operator()(
            const std::weak_ptr<Stop>& a,
            const std::weak_ptr<Stop>& b) const
        {
            assert(a.lock() != nullptr);
            assert(b.lock() != nullptr);
            return *a.lock() < *b.lock();
        }
    };
    
public:
    explicit Stop(std::string name);
    Stop(std::string name, const GeoPoint& geoPoint);
    
    void SetGeoPoint(const GeoPoint& geoPoint);
    
    bool AddCrossingRoute(std::weak_ptr<Route> route);
    bool AddNeighborStopsDistance(std::weak_ptr<Stop> stop, size_t distance);
    
    bool UpdateNeighborStopsDistance(std::weak_ptr<Stop> stop, size_t distance);
    
    std::optional<size_t> FindNeighborStopDistance(std::shared_ptr<Stop> stop) const;
    
    const std::string& GetName() const;
    std::optional<GeoPoint> GetGeoPoint() const;
    const std::vector<std::weak_ptr<Route>>& GetCrossingRoutes() const;
    const std::map<std::weak_ptr<Stop>, size_t, Stop::WeakComparator>& GetNeighborStopsDistances() const;
    
    bool IsComplete() const;
    
    bool operator==(const Stop& rhs) const;
    bool operator<(const Stop& rhs) const;
    
private:
    std::string name_;
    std::optional<GeoPoint> geoPoint_;
    Completion completion_;
    
    std::vector<std::weak_ptr<Route>> crossingRoutes_;
    std::map<std::weak_ptr<Stop>, size_t, Stop::WeakComparator> neighborStopsDistances_;
};

std::ostream& operator<<(std::ostream& os, const Stop& stop);

}
#endif /* Stop_hpp */
