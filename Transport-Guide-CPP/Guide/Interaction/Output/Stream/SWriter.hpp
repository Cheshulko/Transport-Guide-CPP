//
//  ConsoleWriter.hpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 03.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#ifndef SWriter_hpp
#define SWriter_hpp

#include "Writer.hpp"

#include <iostream>

namespace guide::interaction::output::stream {

class SWriter: public Writer
{
public:
    explicit SWriter(std::ostream& os = std::cout);
    
    virtual void WriteRouteInfoResponse(const response::RouteInfoResponse& routeInfoResponse) override;
    virtual void WriteStopCrossingRoutesResponse(const response::StopCrossingRoutesResponse& stopCrossingRoutesResponse) override;
    
private:
    std::ostream& os_;
};

}

#endif /* SWriter_hpp */
