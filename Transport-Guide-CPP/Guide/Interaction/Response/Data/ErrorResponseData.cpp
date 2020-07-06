//
//  ErrorResponseData.cpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 06.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#include "ErrorResponseData.hpp"

namespace guide::interaction::response::data {

ErrorResponseData::ErrorResponseData(const std::string& errorMessage, std::optional<size_t> id)
    : errorMessage_(errorMessage)
    , id_(id)
{}

const std::string& ErrorResponseData::GetErrorMessage() const
{
    return errorMessage_;
}

std::optional<size_t> ErrorResponseData::GetRequestId() const
{
    return id_;
}

}
