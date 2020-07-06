//
//  ErrorResponse.hpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 06.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#ifndef ErrorResponse_hpp
#define ErrorResponse_hpp

#include "Writer.hpp"
#include "ErrorResponseData.hpp"

namespace guide::interaction::response {

class ErrorResponse: public Response
{
public:
    explicit ErrorResponse(const data::ErrorResponseData& errorResponseData);
    
    const data::ErrorResponseData& GetErrorResponseData() const;
    
    virtual void WriteOuptut(output::Writer& writer) const override;

private:
    data::ErrorResponseData errorResponseData_;
};

}
#endif /* ErrorResponse_hpp */
