//
//  NoStopException.hpp
//  Transport-Guide-CPP
//
//  Created by Mykyta Cheshulko on 05.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#ifndef NoStopException_hpp
#define NoStopException_hpp

#include "GuideException.hpp"

namespace guide::exception {

class NoStopException: public GuideException
{
public:
    explicit NoStopException(const std::string& message)
        : GuideException(message) {}
};

}

#endif /* NoStopException_hpp */
