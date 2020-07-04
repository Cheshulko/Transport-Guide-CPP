//
//  Response.hpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 03.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#ifndef Response_h
#define Response_h

namespace guide::interaction::output {
    class Writer;
}

namespace guide::interaction::output {

class Response
{
public:
    virtual void WriteOuptut(Writer& writer) const = 0;
};

}

#endif /* Response_h */
