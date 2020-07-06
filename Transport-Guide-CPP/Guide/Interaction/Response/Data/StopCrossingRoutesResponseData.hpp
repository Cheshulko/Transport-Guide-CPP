//
//  StopCrossingRoutesResponseData.hpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 05.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#ifndef StopCrossingRoutesResponseData_hpp
#define StopCrossingRoutesResponseData_hpp

#include <cstddef>
#include <string>
#include <vector>
#include <optional>

namespace guide::interaction::response::data {

class StopCrossingRoutesResponseData
{
public:
    StopCrossingRoutesResponseData(const std::string& stopName, const std::vector<std::string>& crossingRoutesNames,
                                   std::optional<size_t> id = std::nullopt);
    
    const std::string& GetStopName() const;
    const std::vector<std::string>& GetCrossingRoutesNames() const;
    
    std::optional<size_t> GetStopId() const;
    
private:
    std::string stopName_;
    std::vector<std::string> crossingRoutesNames_;
    
    std::optional<size_t> id_;
};

}

#endif /* StopCrossingRoutesResponseData_hpp */
