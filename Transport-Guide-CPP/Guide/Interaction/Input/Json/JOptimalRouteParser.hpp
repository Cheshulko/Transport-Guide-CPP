//
//  JOptimalRouteParser.hpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 11.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#ifndef JOptimalRouteParser_hpp
#define JOptimalRouteParser_hpp

#include "OptimalRouteRequestData.hpp"
#include "Json.hpp"

#include <iostream>
#include <memory>

namespace guide::interaction::input::json {

class JOptimalRouteParser
{
public:
    static JOptimalRouteParser& GetInstance();
    std::shared_ptr<request::data::OptimalRouteRequestData> Parse(const serialization::json::Node& node);

private:
    JOptimalRouteParser();

public:
    JOptimalRouteParser(JOptimalRouteParser const&) = delete;
    void operator=(JOptimalRouteParser const&)      = delete;
};

}

#endif /* JOptimalRouteParser_hpp */
