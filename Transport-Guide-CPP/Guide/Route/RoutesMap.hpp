//
//  RoutesMap.hpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 02.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#ifndef RoutesMap_hpp
#define RoutesMap_hpp

#include "Route.hpp"
#include "Stop.hpp"

#include <optional>
#include <set>

namespace guide::route {

class RoutesMap
{
public:
    RoutesMap();
    RoutesMap(std::vector<std::shared_ptr<Route>> routes, std::vector<std::shared_ptr<Stop>> stops);
    
    bool AddStop(std::shared_ptr<Stop> stop);
    bool AddRoute(std::shared_ptr<Route> route);
    
    std::optional<std::weak_ptr<Stop>> FindStop(const std::string& name) const;
    std::optional<std::weak_ptr<Stop>> FindStop(std::shared_ptr<Stop> stop) const;
    std::optional<std::weak_ptr<Route>> FindRoute(const std::string& name) const;
    
private:
    std::set<std::shared_ptr<Route>, Route::SharedComparator> routes_;
    std::set<std::shared_ptr<Stop>, Stop::SharedComparator> stops_;
};

}

#endif /* RoutesMap_hpp */
