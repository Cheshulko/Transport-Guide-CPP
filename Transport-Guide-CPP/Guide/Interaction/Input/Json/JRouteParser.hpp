//
//  JRouteParser.hpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 02.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#ifndef JRouteParser_hpp
#define JRouteParser_hpp

#include "Route.hpp"
#include "Json.hpp"

#include <iostream>
#include <memory>

namespace guide::interaction::input::json {

class JRouteParser
{
public:
    static JRouteParser& GetInstance();
    std::shared_ptr<route::Route> Parse(const serialization::json::Node& node);

private:
    JRouteParser();

public:
    JRouteParser(JRouteParser const&)   = delete;
    void operator=(JRouteParser const&) = delete;
};

}

#endif /* JRouteParser_hpp */
