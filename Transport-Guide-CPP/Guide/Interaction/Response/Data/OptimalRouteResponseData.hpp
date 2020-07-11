//
//  OptimalRouteResponseData.hpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 12.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#ifndef OptimalRouteResponseData_hpp
#define OptimalRouteResponseData_hpp

#include <cstddef>
#include <string>
#include <optional>

namespace guide::interaction::response::data {

class OptimalRouteResponseData
{
public:
    OptimalRouteResponseData(std::optional<size_t> id = std::nullopt);
    
    std::optional<size_t> GetRequestId() const;
    
private:
    std::optional<size_t> id_;
};

}

#endif /* OptimalRouteResponseData_hpp */
