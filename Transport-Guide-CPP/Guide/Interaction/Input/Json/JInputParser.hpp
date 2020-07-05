//
//  JInputParser.hpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 02.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#ifndef JInputParser_hpp
#define JInputParser_hpp

#include "Parser.hpp"
#include "Request.hpp"

#include <iostream>

namespace guide::interaction::input::json {

class JInputParser: public Parser
{
public:
    explicit JInputParser(std::istream& in = std::cin);
    
    virtual std::vector<std::shared_ptr<interaction::request::Request>> Parse() override;
    
private:
    std::istream& in_;
};

}

#endif /* JInputParser_hpp */
