//
//  RouteInfoParser.cpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 03.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#include "JRouteInfoParser.hpp"

namespace guide::interaction::input::json {

JRouteInfoParser::JRouteInfoParser()
{}

JRouteInfoParser& JRouteInfoParser::GetInstance()
{
    static JRouteInfoParser instance;
    return instance;
}

std::shared_ptr<request::data::RouteInfoRequestData> JRouteInfoParser::Parse(const serialization::json::Node& node)
{
    const auto& nodeMap = node.AsMap();
    
    const auto& name = nodeMap.at("name").AsString();
    const auto& id = static_cast<size_t>(nodeMap.at("id").AsDouble());
    
    return std::make_shared<request::data::RouteInfoRequestData>(name, id);
}

}
