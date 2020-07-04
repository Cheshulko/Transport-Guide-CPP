//
//  ConsoleWriter.hpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 03.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#ifndef ConsoleWriter_hpp
#define ConsoleWriter_hpp

#include "Writer.hpp"

#include <iostream>

namespace guide::interaction::output {

class StreamWriter: public Writer
{
public:
    StreamWriter(std::ostream& os = std::cout);
    
    virtual void WriteRouteInfoResponse(const RouteInfoResponse& routeInfoResponse) override;
    
private:
    std::ostream& os_;
};

}

#endif /* ConsoleWriter_hpp */
