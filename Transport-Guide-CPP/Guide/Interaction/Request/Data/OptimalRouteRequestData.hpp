//
//  OptimalRouteRequestData.hpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 11.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#ifndef OptimalRouteRequestData_hpp
#define OptimalRouteRequestData_hpp

#include <cstddef>
#include <string>
#include <optional>

namespace guide::interaction::request::data {

class OptimalRouteRequestData
{
public:
    OptimalRouteRequestData(const std::string& fromStopName, const std::string& toStopName, std::optional<size_t> id = std::nullopt);
    
    const std::string& GetFromStopName() const;
    const std::string& GetToStopName() const;
    std::optional<size_t> GetId() const;
    
private:
    std::string fromStopName_;
    std::string toStopName_;
    std::optional<size_t> id_;
};

}

#endif /* OptimalRouteRequestData_hpp */
