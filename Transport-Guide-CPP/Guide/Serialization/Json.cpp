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

namespace guide::serialization::json {

Document::Document(Node root)
    : root(move(root))
{}

const Node& Document::GetRoot() const {
    return root;
}

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

Node LoadInt(std::istream& input)
{
    int result = 0;
    while (isdigit(input.peek())) {
        result *= 10;
        result += input.get() - '0';
    }
    return Node(result);
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
    getline(input, line);
    if (line == "true") {
        return Node(true);
    } else {
        return Node(false);
    }
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
        return LoadBool(input);
    } else {
        input.putback(c);
        return LoadNumber(input);
    }
}

Document Load(std::istream& input)
{
    return Document{ LoadNode(input) };
}

}
