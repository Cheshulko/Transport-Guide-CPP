//
//  Json.cpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 05.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#include "Json.hpp"

#include <iostream>
#include <string>
#include <iomanip>

namespace guide::serialization::json {

namespace {

template<class... Ts> struct overloaded : Ts... { using Ts::operator()...; };
template<class... Ts> overloaded(Ts...) -> overloaded<Ts...>;

Node LoadNode(std::istream& input);

Node LoadArray(std::istream& input)
{
    std::vector<Node> result;

    for (char c; input >> c && c != ']'; ) {
        if (c != ',') {
            input.putback(c);
        }
    result.push_back(LoadNode(input));
    }

    return Node(move(result));
}

Node LoadNumber(std::istream& input)
{
    double result = 0;
    double p = 0.1;
    while (isdigit(input.peek())) {
        result *= 10;
        result += input.get() - '0';
    }
    if (input.peek() == '.') {
        input.get();
        while (isdigit(input.peek())) {
            result += p * (input.get() - '0');
            p *= 0.1;
        }
        return Node(result);
    } else {
        return Node(static_cast<int>(result));
    }
}

Node LoadString(std::istream& input)
{
    std::string line;
    getline(input, line, '"');
    return Node(move(line));
}

Node LoadBool(std::istream& input)
{
    std::string line;
    input >> line;
    return Node((line == "true"));
}

Node LoadDict(std::istream& input)
{
    std::map<std::string, Node> result;

    for (char c; input >> c && c != '}'; ) {
        if (c == ',') {
            input >> c;
        }

        std::string key = LoadString(input).AsString();
        input >> c;
        result.emplace(move(key), LoadNode(input));
    }

    return Node(move(result));
}

Node LoadNode(std::istream& input)
{
    char c;
    input >> c;

    if (c == '[') {
        return LoadArray(input);
    } else if (c == '{') {
        return LoadDict(input);
    } else if (c == '"') {
        return LoadString(input);
    } else if (c == 'f' || c == 't') {
        input.putback(c);
        return LoadBool(input);
    } else {
        input.putback(c);
        return LoadNumber(input);
    }
}
}

Document::Document(Node root)
    : root_(move(root))
{}

const Node& Document::GetRoot() const {
    return root_;
}

Node& Document::GetRoot() {
    return root_;
}

void Node::Write(std::ostream& os, bool isLast) const
{
    std::visit(overloaded {
        [&os, isLast](const std::vector<Node>& value) {
            os << " [ ";
            for (auto it = value.cbegin(); it != value.cend(); ++it) {
                bool isLastValue = (it == std::prev(value.cend()));
                
                it->Write(os, isLastValue);
            }
            os << " ] " << (isLast ? " " : ", ");
        },
        [&os, isLast](const std::map<std::string, Node>& value) {
            os << " { ";
            for (auto it = value.cbegin(); it != value.cend(); ++it) {
                bool isLastValue = (it == std::prev(value.cend()));
                
                os << "\"" << it->first << "\" : ";
                it->second.Write(os, isLastValue);
            }
            os << " } ";
        },
        [&os, isLast](int value) {
            os << value << (isLast ? " " : ", ");
        },
        [&os, isLast](double value) {
            os << std::setprecision(6) << value << (isLast ? " " : ", ");
        },
        [&os, isLast](bool value) {  },
        [&os, isLast](const std::string& value) {
            os << "\"" << value << "\"" << (isLast ? " " : ", ");
        },
    }, *this);
}

void Document::Write(std::ostream& os) const
{
    root_.Write(os, true);
}

Document Document::Load(std::istream& input)
{
    return Document{ LoadNode(input) };
}

}
