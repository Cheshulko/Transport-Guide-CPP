//
//  RouteInfoResponseData.hpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 03.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#ifndef RouteInfoResponseData_hpp
#define RouteInfoResponseData_hpp

#include <cstddef>
#include <string>

namespace guide::interaction::data {

class RouteInfoResponseData
{
public:
    RouteInfoResponseData(const std::string& number, std::size_t stopsCnt,
                          std::size_t uniqueStopsCnt, double routeLength);
    
    const std::string& GetRouteNumber() const;
    std::size_t GetStopsCnt() const;
    std::size_t GetUniqueStopsCnt() const;
    double GetRouteLength() const;
    
private:
    std::string number_;
    std::size_t stopsCnt_;
    std::size_t uniqueStopsCnt_;
    double routeLength_;
};

}

#endif /* RouteInfoResponseData_hpp */
