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

namespace guide::interaction::request::data {

class AddStopRequestData
{
public:
    AddStopRequestData(const std::string& name, const route::GeoPoint& geoPoint);
    
    const std::string& GetStopName() const;
    const route::GeoPoint& GetGeoPoint() const;
    
private:
    std::string name_;
    route::GeoPoint geoPoint_;
};

}

#endif /* AddStopRequestData_hpp */
