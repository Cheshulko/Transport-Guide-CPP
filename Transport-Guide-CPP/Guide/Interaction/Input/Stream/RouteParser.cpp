//
//  RouteParser.cpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 02.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#include "RouteParser.hpp"

#include "Stop.hpp"
#include "CircleRoute.hpp"
#include "LinearRoute.hpp"

#include <iostream>
#include <algorithm>

namespace guide::interaction::input::stream {

RouteParser::RouteParser()
{}

RouteParser& RouteParser::GetInstance()
{
    static RouteParser instance;
    return instance;
}

std::shared_ptr<route::Route> RouteParser::Parse(std::istream& in)
{
    std::vector<std::shared_ptr<route::Stop>> stops;
    route::Route::Type routeType = route::Route::Type::Unknown;
    
    std::string number;
    in >> std::ws;
    std::getline(in, number, ':');
    
    std::string str;
    in >> std::ws;
    std::getline(in, str);
    
    for (auto [delimiter, type]: {
        std::pair{std::string{" > "}, route::Route::Type::Circle},
        std::pair{std::string{" - "}, route::Route::Type::Linear} })
    {
        if (str.find(delimiter) != str.npos) {
            routeType = type;
            size_t last = 0;
            size_t next = 0;
            while ((next = str.find(delimiter, last)) != std::string::npos) {
                auto&& stop = std::make_shared<route::Stop>(str.substr(last, next - last));
                stops.push_back(stop);
                last = next + delimiter.size();
            }
            auto&& stop = std::make_shared<route::Stop>(str.substr(last));
            stops.push_back(stop);
        }
    }
    
    std::shared_ptr<route::Route> route;
    
    switch (routeType) {
        case route::Route::Type::Circle: {
            stops.back() = stops.front();
            route = std::make_shared<route::CircleRoute>(number, stops);
            break;
        }
        case route::Route::Type::Linear: {
            
            // Fcking iterator invalidation
            // std::reverse_copy(stops.begin(), std::prev(stops.end()), std::back_inserter(stops));
            
            std::vector<std::shared_ptr<route::Stop>> linearStops;
            linearStops.reserve(2 * stops.size() - 1);
            std::copy(stops.begin(), stops.end(), std::back_inserter(linearStops));
            std::reverse_copy(stops.begin(), std::prev(stops.end()), std::back_inserter(linearStops));

            route = std::make_shared<route::LinearRoute>(number, linearStops);
            break;
        }
        default: /* route::Route::Type::Unknown */ {
            
            // TODO: Route with 1 stop? WTF
            auto&& stop = std::make_shared<route::Stop>(str);
            stops.push_back(stop);
            route = std::make_shared<route::LinearRoute>(number, stops);
            break;
        }
    }
    
#ifdef LOG_DEBUG
    std::cerr << "LOG: Parsed " << *route << std::endl;
#endif
                
    return route;
}

}
