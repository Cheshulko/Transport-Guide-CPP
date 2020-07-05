//
//  StreamStopCrossingRoutesParser.hpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 05.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#ifndef StreamStopCrossingRoutesParser_hpp
#define StreamStopCrossingRoutesParser_hpp

#include "StopCrossingRoutesRequestData.hpp"

#include <iostream>
#include <memory>

namespace guide::interaction::input {

class StreamStopCrossingRoutesParser
{
public:
    static StreamStopCrossingRoutesParser& GetInstance();
    std::shared_ptr<request::data::StopCrossingRoutesRequestData> Parse(std::istream& in);

private:
    StreamStopCrossingRoutesParser();

public:
    StreamStopCrossingRoutesParser(StreamStopCrossingRoutesParser const&) = delete;
    void operator=(StreamStopCrossingRoutesParser const&)                = delete;
};

}

#endif /* StreamStopCrossingRoutesParser_hpp */
