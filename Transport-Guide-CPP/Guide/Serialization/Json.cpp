//
//  Json.cpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 05.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#include "Json.hpp"

namespace guide::json {

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

Node LoadString(std::istream& input)
{
    std::string line;
    getline(input, line, '"');
    return Node(move(line));
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
    } else {
        input.putback(c);
        return LoadInt(input);
    }
}

Document Load(std::istream& input)
{
    return Document{ LoadNode(input) };
}

}
