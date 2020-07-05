//
//  JRouteInfoParser.hpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 03.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#ifndef JRouteInfoParser_hpp
#define JRouteInfoParser_hpp

#include "RouteInfoRequestData.hpp"
#include "Json.hpp"

#include <iostream>
#include <memory>

namespace guide::interaction::input::json {

class JRouteInfoParser
{
public:
    static JRouteInfoParser& GetInstance();
    std::shared_ptr<request::data::RouteInfoRequestData> Parse(const serialization::json::Node& node);

private:
    JRouteInfoParser();

public:
    JRouteInfoParser(JRouteInfoParser const&) = delete;
    void operator=(JRouteInfoParser const&)   = delete;
};

}

#endif /* JRouteInfoParser_hpp */
