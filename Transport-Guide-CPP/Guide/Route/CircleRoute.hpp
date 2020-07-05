//
//  CircleRoute.hpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 02.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#ifndef CircleRoute_hpp
#define CircleRoute_hpp

#include "Route.hpp"

#include <set>

namespace guide::route {

class CircleRoute: public Route
{
public:
    CircleRoute(const std::string& number, const std::vector<std::shared_ptr<Stop>>& stops);
    CircleRoute(const std::string& number);
    ~CircleRoute();
    
    virtual const std::string& GetNumber() const override;
    virtual const std::vector<std::weak_ptr<Stop>>& GetRouteStops() const override;
    virtual std::vector<std::shared_ptr<Stop>> GetUniqueStops() const override;
    virtual double GetDistance() const override;
    virtual bool Contains(const Stop& stop) const override;
    
private:
    std::string number_;
    std::vector<std::weak_ptr<Stop>> stops_;
    std::set<std::shared_ptr<Stop>, Stop::SharedComparator> uniqueStops_;
};

}

#endif /* CircleRoute_hpp */