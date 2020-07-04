//
//  EmptyResponse.hpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 03.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#ifndef EmptyResponse_hpp
#define EmptyResponse_hpp

#include "Writer.hpp"

namespace guide::interaction::output {

class EmptyResponse: public Response
{
public:
    virtual void WriteOuptut(Writer& writer) const override { /* None */ }
};

}

#endif /* EmptyResponse_hpp */

