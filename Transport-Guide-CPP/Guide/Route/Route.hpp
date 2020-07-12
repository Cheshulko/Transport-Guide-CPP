//
//  Route.hpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 02.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#ifndef Route_h
#define Route_h

#include "Stop.hpp"

#include <vector>
#include <iostream>
#include <memory>
#include <utility>

namespace guide::route {
    class Stop;
}

namespace guide::route {

class Route
{
public:
    enum class Type: size_t
    {
        Linear,
        Circle,
        Unknown = 255
    };
    
    struct SharedComparator
    {
        bool operator()(
            const std::shared_ptr<Route>& a,
            const std::shared_ptr<Route>& b) const
        {
            return *a < *b;
        }
    };
    
public:
    Route(Route::Type type);
    
    virtual const std::string& GetName() const = 0;
    virtual const std::vector<std::weak_ptr<Stop>>& GetRouteStops() const = 0;
    virtual std::vector<std::shared_ptr<Stop>> GetUniqueStops() const = 0;
    
    virtual double GetDistance() const;
    virtual double GetPracticalDistance() const;
    virtual std::pair<size_t, double> GetPracticalDistanceBetweenStops(std::shared_ptr<Stop> from, std::shared_ptr<Stop> to) const;
    
    virtual bool Contains(const Stop& stop) const = 0;
    
    inline virtual Route::Type GetRouteType() const { return type_; }
    
    bool operator==(const Route& rhs) const;
    bool operator<(const Route& rhs) const;
     
    virtual ~Route() { /* None */};
    
private:
    const Route::Type type_;
};

std::ostream& operator<<(std::ostream& os, const Route::Type& routeType);
std::ostream& operator<<(std::ostream& os, const Route& route);

}

#endif /* Route_h */
