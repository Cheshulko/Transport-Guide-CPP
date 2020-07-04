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

#include <string>
#include <optional>
#include <memory>
#include <cassert>
#include <iostream>

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
    Stop(std::string name, const GeoPoint& geoPoint);
    explicit Stop(std::string name);
    
    void SetGeoPoint(const GeoPoint& geoPoint);
    
    const std::string& GetName() const;
    std::optional<GeoPoint> GetGeoPoint() const;
    
    bool IsComplete() const;
    
    bool operator==(const Stop& rhs) const;
    bool operator<(const Stop& rhs) const;
    
private:
    std::string name_;
    std::optional<GeoPoint> geoPoint_;
    Completion completion_;
};

std::ostream& operator<<(std::ostream& os, const Stop& stop);

}
#endif /* Stop_hpp */
