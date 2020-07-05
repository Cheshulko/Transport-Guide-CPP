//
//  Parser.hpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 02.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#ifndef Parser_hpp
#define Parser_hpp

#include "Route.hpp"
#include "Stop.hpp"
#include "Request.hpp"

namespace guide::interaction::input {

class Parser
{
public:
    virtual std::vector<std::shared_ptr<interaction::request::Request>> Parse() = 0;

    virtual ~Parser() { /* None */ }
};

}

#endif /* Parser_hpp */
