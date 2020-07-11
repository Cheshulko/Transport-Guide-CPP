//
//  JOptimalRouteParser.cpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 11.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#include "JOptimalRouteParser.hpp"

namespace guide::interaction::input::json {

JOptimalRouteParser::JOptimalRouteParser()
{}

JOptimalRouteParser& JOptimalRouteParser::GetInstance()
{
    static JOptimalRouteParser instance;
    return instance;
}

std::shared_ptr<request::data::OptimalRouteRequestData> JOptimalRouteParser::Parse(const serialization::json::Node& node)
{
    const auto& nodeMap = node.AsMap();
    
    const auto& from = nodeMap.at("from").AsString();
    const auto& to = nodeMap.at("to").AsString();
    const auto& id = nodeMap.at("id").AsInt();
    
    return std::make_shared<request::data::OptimalRouteRequestData>(from, to, id);
}

}
