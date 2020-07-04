//
//  InputParser.hpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 02.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#ifndef InputParser_hpp
#define InputParser_hpp

#include "Route.hpp"
#include "Stop.hpp"
#include "Request.hpp"

namespace guide::interaction::input {

class InputParser
{
public:
    virtual std::vector<std::shared_ptr<interaction::Request>> Parse() = 0;

    virtual ~InputParser() { /* None */ }
};

}

#endif /* InputParser_hpp */
