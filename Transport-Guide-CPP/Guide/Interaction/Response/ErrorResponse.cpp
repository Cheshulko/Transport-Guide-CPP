//
//  ErrorResponse.cpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 06.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#include "ErrorResponse.hpp"

namespace guide::interaction::response {

ErrorResponse::ErrorResponse(const data::ErrorResponseData& errorResponseData)
    : errorResponseData_(errorResponseData)
{}

const data::ErrorResponseData& ErrorResponse::GetErrorResponseData() const
{
    return errorResponseData_;
}

void ErrorResponse::WriteOuptut(output::Writer& writer) const
{
    writer.WriteErrorResponse(*this);
}

}
