//
//  StreamStopParser.cpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 02.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#include "StreamStopParser.hpp"

#include <string>

namespace guide::interaction::input {

StreamStopParser::StreamStopParser()
{}

StreamStopParser& StreamStopParser::GetInstance()
{
    static StreamStopParser instance; 
    return instance;
}

std::shared_ptr<request::data::AddStopRequestData> StreamStopParser::Parse(std::istream& in)
{
    std::string name;
    std::vector<request::data::AddStopRequestData::NeighborDistance> neighborsDistance;
    
    std::string der;
    double lat, lon;
    in >> std::ws;
    std::getline(in, name, ':');
    in >> lat >> der >> lon;
    
    std::getline(in, der);
    
    const std::string delimiter = ", ";
    const std::string toDelimiter = "m to ";
    
    if (der.find(delimiter) != der.npos) {
        size_t last = 0;
        size_t next = 0;
        while ((next = der.find(delimiter, last)) != std::string::npos) {
            const auto neighborStr = der.substr(last, next - last);
            if (!neighborStr.empty()) {
                const auto toPos = neighborStr.find(toDelimiter);
                const auto toStopDelta = toPos + toDelimiter.size();
                
                const auto distance = std::stoul(neighborStr.substr(0, toPos));
                const auto toStopName = neighborStr.substr(toStopDelta, neighborStr.size() - toStopDelta);
                
                neighborsDistance.push_back(request::data::AddStopRequestData::NeighborDistance { distance, toStopName });
            }
            last = next + delimiter.size();
        }
        const auto neighborStr = der.substr(last);
        const auto toPos = neighborStr.find(toDelimiter);
        const auto toStopDelta = toPos + toDelimiter.size();
        
        const auto distance = std::stoul(neighborStr.substr(0, toPos));
        const auto toStopName = neighborStr.substr(toStopDelta, neighborStr.size() - toStopDelta);
        
        neighborsDistance.push_back(request::data::AddStopRequestData::NeighborDistance { distance, toStopName });
    }
    
    // TODO: 
    auto addStopRequestDataPtr = std::make_shared<request::data::AddStopRequestData>(
        name, route::GeoPoint{ lat, lon }, neighborsDistance
    );
    
//#ifdef LOG_DEBUG
//    std::cerr << "LOG: Parsed " << *stopPtr << std::endl;
//#endif
    
    return addStopRequestDataPtr;
}

}
