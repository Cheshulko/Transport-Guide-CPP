//
//  JWriter.hpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 06.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#ifndef JWriter_hpp
#define JWriter_hpp

#include "Writer.hpp"
#include "Json.hpp"

#include <iostream>

namespace guide::interaction::output::json {

class JWriter: public Writer
{
public:
    explicit JWriter(serialization::json::Document& document);
    
    virtual void WriteRouteInfoResponse(const response::RouteInfoResponse& routeInfoResponse) override;
    virtual void WriteStopCrossingRoutesResponse(const response::StopCrossingRoutesResponse& stopCrossingRoutesResponse) override;
    virtual void WriteErrorResponse(const response::ErrorResponse& errorResponse) override;
    
private:
    serialization::json::Document& document_;
    std::vector<serialization::json::Node>& rootArray_;
};

}

#endif /* JWriter_hpp */
