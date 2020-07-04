//
//  NoRouteException.hpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 03.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#ifndef NoRouteException_hpp
#define NoRouteException_hpp

#include "GuideException.hpp"

namespace guide::exception {

class NoRouteException: public GuideException
{
public:
    explicit NoRouteException(const std::string& message)
        : GuideException(message) {}
};

}

#endif /* NoRouteException_hpp */
