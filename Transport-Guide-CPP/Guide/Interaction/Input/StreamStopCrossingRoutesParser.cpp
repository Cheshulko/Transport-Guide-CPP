//
//  StreamStopCrossingRoutesParser.cpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 05.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#include "StreamStopCrossingRoutesParser.hpp"

namespace guide::interaction::input {

StreamStopCrossingRoutesParser::StreamStopCrossingRoutesParser()
{}

StreamStopCrossingRoutesParser& StreamStopCrossingRoutesParser::GetInstance()
{
    static StreamStopCrossingRoutesParser instance;
    return instance;
}

std::shared_ptr<request::data::StopCrossingRoutesRequestData> StreamStopCrossingRoutesParser::Parse(std::istream& in)
{
    std::string name;
    in >> std::ws;
    std::getline(in, name);
    
    return std::make_shared<request::data::StopCrossingRoutesRequestData>(name);
}

}
