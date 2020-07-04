//
//  Request.hpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 02.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#ifndef Request_hpp
#define Request_hpp

#include "RoutesMap.hpp"
#include "Response.hpp"

namespace guide::interaction {

class Request
{
public:
    enum class Type: size_t
    {
        AddStop,
        AddRoute,
        RouteInfo
    };
    
public:
    Request(Request::Type type)
        : type_(type)
    {}
    
    virtual std::shared_ptr<output::Response> PerformOn(route::RoutesMap& routesMap) const = 0;
    inline virtual Request::Type GetRequestType() const { return type_; }
    
    virtual ~Request() { /* None */ }
    
private:
    const Request::Type type_;
};

}

#endif /* Request_hpp */
