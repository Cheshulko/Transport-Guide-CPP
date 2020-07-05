//
//  StreamInputParser.hpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 02.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#ifndef StreamInputParser_hpp
#define StreamInputParser_hpp

#include "InputParser.hpp"
#include "Request.hpp"

#include <iostream>

namespace guide::interaction::input {

class StreamInputParser: public InputParser
{
public:
    explicit StreamInputParser(std::istream& in = std::cin);
    
    virtual std::vector<std::shared_ptr<interaction::request::Request>> Parse() override;
    
private:
    std::istream& in_;
};

}

#endif /* StreamInputParser_hpp */
