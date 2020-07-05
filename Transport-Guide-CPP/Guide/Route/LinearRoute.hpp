//
//  LinearRoute.hpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 02.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#ifndef LinearRoute_hpp
#define LinearRoute_hpp

#include "Route.hpp"

#include <set>

namespace guide::route {

class LinearRoute: public Route
{
public:
    LinearRoute(const std::string& name, const std::vector<std::shared_ptr<Stop>>& stops);
    explicit LinearRoute(const std::string& name);
    ~LinearRoute();
    
    virtual const std::string& GetName() const override;
    virtual const std::vector<std::weak_ptr<Stop>>& GetRouteStops() const override;
    virtual std::vector<std::shared_ptr<Stop>> GetUniqueStops() const override;
    
    virtual double GetDistance() const override;
    virtual double GetPracticalDistance() const override;
    
    virtual bool Contains(const Stop& stop) const override;
    
private:
    std::string name_;
    std::vector<std::weak_ptr<Stop>> stops_;
    std::set<std::shared_ptr<Stop>, Stop::SharedComparator> uniqueStops_;
};

}

#endif /* LinearRoute_hpp */
