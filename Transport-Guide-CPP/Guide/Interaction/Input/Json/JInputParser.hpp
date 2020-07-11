//
//  JInputParser.hpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 02.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#ifndef JInputParser_hpp
#define JInputParser_hpp

#include "Parser.hpp"
#include "Request.hpp"

#include <iostream>

namespace guide::interaction::input::json {

class JInputParser: public Parser
{
public:
    explicit JInputParser(std::istream& in = std::cin);
    virtual std::vector<std::shared_ptr<interaction::request::Request>> GetBaseRequests() const override;
    virtual std::vector<std::shared_ptr<interaction::request::Request>> GetStatRequests() const override;
    virtual std::shared_ptr<route::RoutesMap::Settings> GetRouteMapSettings() const override;
    
    virtual bool Parse() override;
    
private:
    std::istream& in_;
    
    std::vector<std::shared_ptr<interaction::request::Request>> baseRequests_;
    std::vector<std::shared_ptr<interaction::request::Request>> statRequests_;
    std::shared_ptr<route::RoutesMap::Settings> routeMapSettings_;
};

}

#endif /* JInputParser_hpp */
