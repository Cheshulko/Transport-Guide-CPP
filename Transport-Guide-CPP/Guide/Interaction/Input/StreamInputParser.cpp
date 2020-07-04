//
//  StreamInputParser.cpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 02.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#include "StreamInputParser.hpp"
#include "CircleRoute.hpp"
#include "LinearRoute.hpp"

#include "StreamStopParser.hpp"
#include "StreamRouteParser.hpp"
#include "StreamRouteInfoParser.hpp"

#include "AddStopRequest.hpp"
#include "AddRouteRequest.hpp"
#include "RouteInfoRequest.hpp"

#include <sstream>

namespace guide::interaction::input {

StreamInputParser::StreamInputParser(std::istream& in)
    : in_(in)
{}

std::vector<std::shared_ptr<interaction::Request>> StreamInputParser::Parse()
{
    std::vector<std::shared_ptr<interaction::Request>> requests;
    
    size_t requestsCnt = 0;
    in_ >> requestsCnt;
    in_.get();
    
#ifdef LOG_DEBUG
    std::cerr << "LOG: requestsCnt=" << requestsCnt << std::endl;
#endif
    
    std::cerr << requestsCnt << "\n";
    while(requestsCnt-->0)
    {
        std::string request_str;
        getline(in_, request_str);
        std::stringstream stream;
        stream << request_str;
        
        std::cerr << request_str << "\n";
        
        std::string type;
        if(stream >> type)
        {
            if (type == "Stop") {
                auto stopParsedPtr = StreamStopParser::GetInstance().Parse(stream);
                requests.push_back(std::make_shared<interaction::AddStopRequest>(stopParsedPtr));
            } else if (type == "Bus") {
                auto routeParsedPtr = StreamRouteParser::GetInstance().Parse(stream);
                requests.push_back(std::make_shared<interaction::AddRouteRequest>(routeParsedPtr));
            } else {
                throw std::runtime_error("No such type");
            }
        }
    }
    
    in_ >> requestsCnt;
    in_.get();
    
    std::cerr << requestsCnt << "\n";
    
#ifdef LOG_DEBUG
    std::cerr << "LOG: requestsCnt=" << requestsCnt << std::endl;
#endif
    
    while(requestsCnt-->0)
    {
        std::string request_str;
        getline(in_, request_str);
        std::stringstream stream;
        stream << request_str;
        
        std::cerr << request_str << "\n";
        
        std::string type;
        if(stream >> type)
        {
            if (type == "Bus") {
                auto routeInfoParsedPtr = StreamRouteInfoParser::GetInstance().Parse(stream);
                requests.push_back(std::make_shared<interaction::RouteInfoRequest>(routeInfoParsedPtr));
            } else {
                throw std::runtime_error("No such type");
            }
        }
    }
    
    return requests;
}

}
