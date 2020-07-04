//
//  StreamStopParser.cpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 02.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#include "StreamStopParser.hpp"

namespace guide::interaction::input {

StreamStopParser::StreamStopParser()
{}

StreamStopParser& StreamStopParser::GetInstance()
{
    static StreamStopParser instance; 
    return instance;
}

std::shared_ptr<route::Stop> StreamStopParser::Parse(std::istream& in)
{
    std::string name, der;
    double lat, lon;
    in >> std::ws;
    std::getline(in, name, ':');
    in >> lat >> der >> lon;
    
    auto stopPtr = std::make_shared<route::Stop>(name, route::GeoPoint{ lat, lon });
    
#ifdef LOG_DEBUG
    std::cerr << "LOG: Parsed " << *stopPtr << std::endl;
#endif
    
    return stopPtr;
}

}
