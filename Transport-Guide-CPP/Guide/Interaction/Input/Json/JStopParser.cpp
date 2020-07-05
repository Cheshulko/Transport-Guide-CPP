//
//  JStopParser.cpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 02.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#include "JStopParser.hpp"

#include <string>

namespace guide::interaction::input::json {

JStopParser::JStopParser()
{}

JStopParser& JStopParser::GetInstance()
{
    static JStopParser instance;
    return instance;
}

std::shared_ptr<request::data::AddStopRequestData> JStopParser::Parse(const serialization::json::Node& node)
{
    const auto& nodeMap = node.AsMap();
    
    std::string name = nodeMap.at("name").AsString();
    std::vector<request::data::AddStopRequestData::NeighborDistance> neighborsDistance;
    
    const auto& roadDistances = nodeMap.at("road_distances").AsMap();
    
    for (const auto& roadDistance: roadDistances) {
        neighborsDistance.emplace_back(
            static_cast<size_t>(roadDistance.second.AsDouble()),
            roadDistance.first
        );
    }
    
    const auto& latitude = nodeMap.at("latitude").AsDouble();
    const auto& longitude = nodeMap.at("longitude").AsDouble();
    
    auto addStopRequestDataPtr = std::make_shared<request::data::AddStopRequestData>(
        name, route::GeoPoint{ latitude, longitude }, neighborsDistance
    );
    
    return addStopRequestDataPtr;
}

}
