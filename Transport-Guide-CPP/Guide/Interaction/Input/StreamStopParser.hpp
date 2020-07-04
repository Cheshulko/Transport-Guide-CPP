//
//  StreamStopParser.hpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 02.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#ifndef StreamStopParser_hpp
#define StreamStopParser_hpp

#include "Stop.hpp"

#include <iostream>

namespace guide::interaction::input {

class StreamStopParser
{
public:
    static StreamStopParser& GetInstance();
    std::shared_ptr<route::Stop> Parse(std::istream& in);

private:
    StreamStopParser();

public:
    StreamStopParser(StreamStopParser const&) = delete;
    void operator=(StreamStopParser const&)   = delete;
};

}

#endif /* StreamStopParser_hpp */
