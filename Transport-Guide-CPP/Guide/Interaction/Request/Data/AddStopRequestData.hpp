//
//  AddStopRequestData.hpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 05.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#ifndef AddStopRequestData_hpp
#define AddStopRequestData_hpp

#include "GeoPoint.hpp"

#include <string>
#include <utility>
#include <vector>

namespace guide::interaction::request::data {

class AddStopRequestData
{
public:
    using NeighborDistance = std::pair<size_t, std::string>;
    
public:
    AddStopRequestData(const std::string& name, const route::GeoPoint& geoPoint, const std::vector<NeighborDistance>& neighborsDistance);
    
    const std::string& GetStopName() const;
    const route::GeoPoint& GetGeoPoint() const;
    const std::vector<NeighborDistance>& GetNeighborStopsDistance() const;
    
private:
    std::string name_;
    route::GeoPoint geoPoint_;
    
    std::vector<NeighborDistance> neighborStopsDistance_;
};

}

#endif /* AddStopRequestData_hpp */
