//
//  StreamRouteInfoParser.hpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 03.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#ifndef StreamRouteInfoParser_hpp
#define StreamRouteInfoParser_hpp

#include "RouteInfoRequestData.hpp"

#include <iostream>
#include <memory>

namespace guide::interaction::input {

class StreamRouteInfoParser
{
public:
    static StreamRouteInfoParser& GetInstance();
    std::shared_ptr<request::data::RouteInfoRequestData> Parse(std::istream& in);

private:
    StreamRouteInfoParser();

public:
    StreamRouteInfoParser(StreamRouteInfoParser const&) = delete;
    void operator=(StreamRouteInfoParser const&)        = delete;
};

}

#endif /* StreamRouteInfoParser_hpp */
