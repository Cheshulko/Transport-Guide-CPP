//
//  JStopCrossingRoutesParser.hpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 05.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#ifndef JStopCrossingRoutesParser_hpp
#define JStopCrossingRoutesParser_hpp

#include "StopCrossingRoutesRequestData.hpp"
#include "Json.hpp"

#include <iostream>
#include <memory>

namespace guide::interaction::input::json {

class JStopCrossingRoutesParser
{
public:
    static JStopCrossingRoutesParser& GetInstance();
    std::shared_ptr<request::data::StopCrossingRoutesRequestData> Parse(const serialization::json::Node& node);

private:
    JStopCrossingRoutesParser();

public:
    JStopCrossingRoutesParser(JStopCrossingRoutesParser const&) = delete;
    void operator=(JStopCrossingRoutesParser const&)            = delete;
};

}

#endif /* JStopCrossingRoutesParser_hpp */
