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

namespace guide::interaction::request::data {

class StopCrossingRoutesRequestData
{
public:
    explicit StopCrossingRoutesRequestData(const std::string& stopName);
    
    const std::string& GetStopName() const;
    
private:
    std::string stopName_;
};

}

#endif /* StopCrossingRoutesReqeustData_hpp */
