//
//  StreamStopParser.hpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 02.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#ifndef StreamStopParser_hpp
#define StreamStopParser_hpp

#include "AddStopRequestData.hpp"

#include <iostream>
#include <memory>

namespace guide::interaction::input {

class StreamStopParser
{
public:
    static StreamStopParser& GetInstance();
    std::shared_ptr<request::data::AddStopRequestData> Parse(std::istream& in);

private:
    StreamStopParser();

public:
    StreamStopParser(StreamStopParser const&) = delete;
    void operator=(StreamStopParser const&)   = delete;
};

}

#endif /* StreamStopParser_hpp */
