//
//  StopCrossingRoutesReqeustData.hpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 05.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#ifndef StopCrossingRoutesReqeustData_hpp
#define StopCrossingRoutesReqeustData_hpp

#include <cstddef>
#include <string>
#include <optional>

namespace guide::interaction::request::data {

class StopCrossingRoutesRequestData
{
public:
    explicit StopCrossingRoutesRequestData(const std::string& stopName, std::optional<size_t> id = std::nullopt);
    
    const std::string& GetStopName() const;
    std::optional<size_t> GetStopId() const;
    
private:
    std::string stopName_;
    std::optional<size_t> id_;
};

}

#endif /* StopCrossingRoutesReqeustData_hpp */
