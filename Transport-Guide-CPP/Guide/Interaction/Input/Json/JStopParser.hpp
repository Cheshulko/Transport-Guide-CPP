//
//  JStopParser.hpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 02.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#ifndef JStopParser_hpp
#define JStopParser_hpp

#include "AddStopRequestData.hpp"
#include "Json.hpp"

#include <iostream>
#include <memory>

namespace guide::interaction::input::json {

class JStopParser
{
public:
    static JStopParser& GetInstance();
    std::shared_ptr<request::data::AddStopRequestData> Parse(const serialization::json::Node& node);

private:
    JStopParser();

public:
    JStopParser(JStopParser const&)    = delete;
    void operator=(JStopParser const&) = delete;
};

}

#endif /* JStopParser_hpp */
