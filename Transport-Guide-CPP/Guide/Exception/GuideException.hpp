//
//  GuideException.hpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 03.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#ifndef GuideException_hpp
#define GuideException_hpp

#include <string>

namespace guide::exception {

class GuideException
{
public:
    explicit GuideException(const std::string& message)
        : message_(message) {}
    
    const std::string& GetMessage() const { return message_; };
    
private:
    const std::string message_;
};

}

#endif /* GuideException_hpp */
