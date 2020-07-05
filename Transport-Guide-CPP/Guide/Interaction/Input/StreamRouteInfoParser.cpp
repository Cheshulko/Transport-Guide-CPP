//
//  StreamRouteInfoParser.cpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 03.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#include "StreamRouteInfoParser.hpp"

namespace guide::interaction::input {

StreamRouteInfoParser::StreamRouteInfoParser()
{}

StreamRouteInfoParser& StreamRouteInfoParser::GetInstance()
{
    static StreamRouteInfoParser instance;
    return instance;
}

std::shared_ptr<request::data::RouteInfoRequestData> StreamRouteInfoParser::Parse(std::istream& in)
{
    std::string name;
    in >> std::ws;
    std::getline(in, name);
    
    return std::make_shared<request::data::RouteInfoRequestData>(name);
}

}
