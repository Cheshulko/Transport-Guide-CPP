//
//  JRouteParser.cpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 02.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#include "JRouteParser.hpp"

#include "Stop.hpp"
#include "CircleRoute.hpp"
#include "LinearRoute.hpp"

#include <iostream>
#include <algorithm>

namespace guide::interaction::input::json {

JRouteParser::JRouteParser()
{}

JRouteParser& JRouteParser::GetInstance()
{
    static JRouteParser instance;
    return instance;
}

std::shared_ptr<route::Route> JRouteParser::Parse(const serialization::json::Node& node)
{
    const auto& nodeMap = node.AsMap();
    
    std::string name = nodeMap.at("name").AsString();
    
    const auto& stopsStr = nodeMap.at("stops").AsArray();
    std::vector<std::shared_ptr<route::Stop>> stops;
    
    for (const auto& stopStr: stopsStr) {
        auto&& stop = std::make_shared<route::Stop>(stopStr.AsString());
        stops.push_back(stop);
    }
    
    auto isCircle = nodeMap.at("is_roundtrip").AsBool();
    std::shared_ptr<route::Route> route;
    
    if (isCircle) {
        stops.back() = stops.front();
        route = std::make_shared<route::CircleRoute>(name, stops);
    } else {
        std::vector<std::shared_ptr<route::Stop>> linearStops;
        linearStops.reserve(2 * stops.size() - 1);
        std::copy(stops.begin(), stops.end(), std::back_inserter(linearStops));
        std::reverse_copy(stops.begin(), std::prev(stops.end()), std::back_inserter(linearStops));

        route = std::make_shared<route::LinearRoute>(name, linearStops);
    }
    
#ifdef LOG_DEBUG
    std::cerr << "LOG: Parsed " << *route << std::endl;
#endif
                
    return route;
}

}
