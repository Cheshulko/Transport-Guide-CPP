//
//  JStopCrossingRoutesParser.cpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 05.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#include "JStopCrossingRoutesParser.hpp"

namespace guide::interaction::input::json {

JStopCrossingRoutesParser::JStopCrossingRoutesParser()
{}

JStopCrossingRoutesParser& JStopCrossingRoutesParser::GetInstance()
{
    static JStopCrossingRoutesParser instance;
    return instance;
}

std::shared_ptr<request::data::StopCrossingRoutesRequestData> JStopCrossingRoutesParser::Parse(const serialization::json::Node& node)
{
    const auto& nodeMap = node.AsMap();
    
    const auto& name = nodeMap.at("name").AsString();
    const auto& id = static_cast<size_t>(nodeMap.at("id").AsDouble());
    
    return std::make_shared<request::data::StopCrossingRoutesRequestData>(name);
}

}
