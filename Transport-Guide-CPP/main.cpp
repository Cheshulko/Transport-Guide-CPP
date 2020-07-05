//
//  main.cpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 01.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#include <iostream>
#include <fstream>

#define LOG_DEBUG

#include "RoutesMap.hpp"
#include "JInputParser.hpp"
#include "StreamWriter.hpp"

#include "Json.hpp"

#include "GuideException.hpp"

int main() {
    
    guide::route::RoutesMap routesMap;
    guide::interaction::output::StreamWriter streamWriter;
    
    std::ifstream file ("in.txt");
    
    if (!file.is_open()) {
        throw std::runtime_error("No in.txt");
    }
    
    std::unique_ptr<guide::interaction::input::Parser> parser = std::make_unique<guide::interaction::input::json::JInputParser>(file);
    
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
