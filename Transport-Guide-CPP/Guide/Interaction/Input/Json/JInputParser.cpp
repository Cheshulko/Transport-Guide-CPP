//
//  InputParser.cpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 02.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#include "JInputParser.hpp"
#include "CircleRoute.hpp"
#include "LinearRoute.hpp"

#include "JStopParser.hpp"
#include "JRouteParser.hpp"
#include "JRouteInfoParser.hpp"
#include "JStopCrossingRoutesParser.hpp"
#include "JOptimalRouteParser.hpp"

#include "AddStopRequest.hpp"
#include "AddRouteRequest.hpp"
#include "RouteInfoRequest.hpp"
#include "StopCrossingRoutesRequest.hpp"
#include "OptimalRouteRequest.hpp"

#include "Json.hpp"

#include <sstream>

namespace guide::interaction::input::json {

JInputParser::JInputParser(std::istream& in)
    : in_(in)
{}

bool JInputParser::Parse()
{
    serialization::json::Document document = serialization::json::Document::Load(in_);
    serialization::json::Node root = document.GetRoot();

    const auto& rootMap = root.AsMap();
    
    const auto& routing_settings = rootMap.at("routing_settings").AsMap();
    const auto& base_requests = rootMap.at("base_requests").AsArray();
    const auto& stat_requests = rootMap.at("stat_requests").AsArray();
    
    routeMapSettings_ = std::make_shared<route::RoutesMap::Settings>(
        routing_settings.at("bus_wait_time").AsInt(),
        routing_settings.at("bus_velocity").AsInt()
    );
    
    for (const auto& request: base_requests) {
        const auto& requestMap = request.AsMap();
        if (requestMap.at("type").AsString() == "Stop") {
            auto stopParsedPtr = JStopParser::GetInstance().Parse(request);
            baseRequests_.push_back(std::make_shared<interaction::request::AddStopRequest>(stopParsedPtr));
        } else if (requestMap.at("type").AsString() == "Bus") {
            auto routeParsedPtr = JRouteParser::GetInstance().Parse(request);
            baseRequests_.push_back(std::make_shared<interaction::request::AddRouteRequest>(routeParsedPtr));
        } else {
            throw std::runtime_error("No such type");
        }
    }
    
    for (const auto& request: stat_requests) {
        const auto& requestMap = request.AsMap();
        if (requestMap.at("type").AsString() == "Stop") {
            auto stopCrossingRoutesParsedPtr = JStopCrossingRoutesParser::GetInstance().Parse(request);
            statRequests_.push_back(std::make_shared<interaction::request::StopCrossingRoutesRequest>(stopCrossingRoutesParsedPtr));
        } else if (requestMap.at("type").AsString() == "Bus") {
            auto routeInfoParsedPtr = JRouteInfoParser::GetInstance().Parse(request);
            statRequests_.push_back(std::make_shared<interaction::request::RouteInfoRequest>(routeInfoParsedPtr));
        } else if (requestMap.at("type").AsString() == "Route") {
            auto optimalRouteParsedPtr = JOptimalRouteParser::GetInstance().Parse(request);
            statRequests_.push_back(std::make_shared<interaction::request::OptimalRouteRequest>(optimalRouteParsedPtr));
        } else {
            throw std::runtime_error("No such type");
        }
    }
    
    return true;
}

std::vector<std::shared_ptr<interaction::request::Request>> JInputParser::GetBaseRequests() const
{
    return baseRequests_;
}

std::vector<std::shared_ptr<interaction::request::Request>> JInputParser::GetStatRequests() const
{
    return statRequests_;
}

std::shared_ptr<route::RoutesMap::Settings> JInputParser::GetRouteMapSettings() const
{
    return routeMapSettings_;
}

}
