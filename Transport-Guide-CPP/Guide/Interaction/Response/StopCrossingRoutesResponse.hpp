//
//  StopCrossingRoutesResponse.hpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 05.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#ifndef StopCrossingRoutesResponse_hpp
#define StopCrossingRoutesResponse_hpp

#include "Writer.hpp"
#include "StopCrossingRoutesResponseData.hpp"

namespace guide::interaction::response {

class StopCrossingRoutesResponse: public Response
{
public:
    StopCrossingRoutesResponse(const data::StopCrossingRoutesResponseData& crossingRoutesResponseData);
    
    const data::StopCrossingRoutesResponseData& GetStopCrossingRoutesResponseData() const;
    
    virtual void WriteOuptut(output::Writer& writer) const override;

private:
    data::StopCrossingRoutesResponseData crossingRoutesResponseData_;
};

}


#endif /* StopCrossingRoutesResponse_hpp */
