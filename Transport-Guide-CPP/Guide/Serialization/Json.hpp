//
//  Json.hpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 05.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#ifndef Json_hpp
#define Json_hpp

#include <iostream>
#include <map>
#include <string>
#include <variant>
#include <vector>

namespace guide::serialization::json {

class Node: public std::variant<std::vector<Node>,
            std::map<std::string, Node>,
            int, double, bool, std::string>
{
public:
    using variant::variant;

    const auto& AsArray() const {
        return std::get<std::vector<Node>>(*this);
    }
    
    const auto& AsMap() const {
        return std::get<std::map<std::string, Node>>(*this);
    }
    
    auto& AsArray() {
        return std::get<std::vector<Node>>(*this);
    }
    
    auto& AsMap() {
        return std::get<std::map<std::string, Node>>(*this);
    }
    
    int AsInt() const {
        return std::get<int>(*this);
    }
    
    double AsDouble() const {
        return std::get<double>(*this);
    }
    
    int AsBool() const {
        return std::get<bool>(*this);
    }
    
    const auto& AsString() const {
        return std::get<std::string>(*this);
    }
    
    void Write(std::ostream& os, bool isLast = false) const;
};

class Document
{
public:
    explicit Document(Node root);

    const Node& GetRoot() const;
    Node& GetRoot();
    
    void Write(std::ostream& os) const;
    
    static Document Load(std::istream& input);

private:
    Node root_;
};

}

#endif /* Json_hpp */
