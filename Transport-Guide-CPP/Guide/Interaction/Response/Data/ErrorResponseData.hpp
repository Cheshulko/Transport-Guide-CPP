//
//  ErrorResponseData.hpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 06.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#ifndef ErrorResponseData_hpp
#define ErrorResponseData_hpp

#include <cstddef>
#include <string>
#include <optional>

namespace guide::interaction::response::data {

class ErrorResponseData
{
public:
    ErrorResponseData(const std::string& errorMessage, std::optional<size_t> id = std::nullopt);
    
    const std::string& GetErrorMessage() const;
    
    std::optional<size_t> GetRequestId() const;
    
private:
    std::string errorMessage_;

    std::optional<size_t> id_;
};

}

#endif /* ErrorResponseData_hpp */
