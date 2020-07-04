//
//  main.cpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 01.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#include <iostream>

#define LOG_DEBUG

#include "RoutesMap.hpp"
#include "StreamInputParser.hpp"
#include "StreamWriter.hpp"

#include "GuideException.hpp"

int main() {
    
    guide::route::RoutesMap routesMap;
    guide::interaction::output::StreamWriter streamWriter;
    
    std::unique_ptr<guide::interaction::input::InputParser> parser = std::make_unique<guide::interaction::input::StreamInputParser>();
    
    const auto requests = parser->Parse();
    for (const auto& request: requests) {
        try {
            request->PerformOn(routesMap)->WriteOuptut(streamWriter);
        } catch(const guide::exception::GuideException& e) {
            // TODO: To wtriter
            std::cout << e.GetMessage() << std::endl;
        }
    }
    
    return 0;
}
