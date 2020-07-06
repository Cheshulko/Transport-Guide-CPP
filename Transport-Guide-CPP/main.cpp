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
#include "InputParser.hpp"

#include "JWriter.hpp"
#include "SWriter.hpp"

#include "Json.hpp"

#include "GuideException.hpp"

using Node = guide::serialization::json::Node;
using Document = guide::serialization::json::Document;

int main() {
    
//    std::ifstream file ("in.txt");
//
//    if (!file.is_open()) {
//        throw std::runtime_error("No in.txt");
//    }
    
    auto d = Document{ Node { std::vector<Node> {} } };
    
    guide::route::RoutesMap routesMap;
    guide::interaction::output::json::JWriter streamWriter(d);
    
    std::unique_ptr<guide::interaction::input::Parser> parser = std::make_unique<guide::interaction::input::json::JInputParser>(std::cin);
    
    const auto requests = parser->Parse();
    for (const auto& request: requests) {
        try {
            request->PerformOn(routesMap)->WriteOuptut(streamWriter);
        } catch(const guide::exception::GuideException& e) {
            // TODO: To writer
            std::cout << e.GetMessage() << std::endl;
        }
    }
    
    d.Write(std::cout);
//    std::ofstream out_file;
//    out_file.open("out.txt");
//    d.Write(out_file);
//    out_file.close();
    
    return 0;
}
