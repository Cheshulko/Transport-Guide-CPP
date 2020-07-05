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

namespace guide::interaction::request::data {

class RouteInfoRequestData
{
public:
    explicit RouteInfoRequestData(const std::string& number);
    
    const std::string& GetRouteNumber() const;
    
private:
    std::string number_;
};

}

#endif /* RouteInfo_hpp */
