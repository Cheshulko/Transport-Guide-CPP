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

namespace guide::interaction::response::data {

class StopCrossingRoutesResponseData
{
public:
    StopCrossingRoutesResponseData(const std::string& stopName, const std::vector<std::string>& crossingRoutesNames);
    
    const std::string& GetStopName() const;
    const std::vector<std::string>& GetCrossingRoutesNames() const;
    
private:
    std::string stopName_;
    std::vector<std::string> crossingRoutesNames_;
};

}

#endif /* StopCrossingRoutesResponseData_hpp */
