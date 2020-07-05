//
//  RouteInfo.hpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 03.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#ifndef RouteInfo_hpp
#define RouteInfo_hpp

#include <cstddef>
#include <string>
#include <optional>

namespace guide::interaction::request::data {

class RouteInfoRequestData
{
public:
    explicit RouteInfoRequestData(const std::string& name, std::optional<size_t> id = std::nullopt);
    
    const std::string& GetRouteName() const;
    std::optional<size_t> GetRouteId() const;
    
private:
    std::string name_;
    std::optional<size_t> id_;
};

}

#endif /* RouteInfo_hpp */
