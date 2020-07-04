//
//  StreamRouteParser.hpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 02.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#ifndef StreamRouteParser_hpp
#define StreamRouteParser_hpp

#include "Route.hpp"

#include <iostream>
#include <memory>

namespace guide::interaction::input {

class StreamRouteParser
{
public:
    static StreamRouteParser& GetInstance();
    std::shared_ptr<route::Route> Parse(std::istream& in);

private:
    StreamRouteParser();

public:
    StreamRouteParser(StreamRouteParser const&) = delete;
    void operator=(StreamRouteParser const&)    = delete;
};

}

#endif /* StreamRouteParser_hpp */
