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
#include <optional>

namespace guide::interaction::response::data {

class RouteInfoResponseData
{
public:
    RouteInfoResponseData(const std::string& number, std::size_t stopsCnt,
                          std::size_t uniqueStopsCnt,
                          double routeLength, double routePracticalLength,
                          std::optional<size_t> id = std::nullopt);
    
    const std::string& GetRouteNumber() const;
    std::size_t GetStopsCnt() const;
    std::size_t GetUniqueStopsCnt() const;
    
    double GetRouteLength() const;
    double GetRoutePracticalLength() const;
    
    std::optional<size_t> GetRouteId() const;
    
private:
    std::string number_;
    std::size_t stopsCnt_;
    std::size_t uniqueStopsCnt_;
    
    double routeLength_;
    double routePracticalLength_;
    
    std::optional<size_t> id_;
};

}

#endif /* RouteInfoResponseData_hpp */
