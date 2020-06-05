//
// Created by Sherzod on 31.05.2020.
//

#ifndef LAB8_PARSER_H
#define LAB8_PARSER_H

#include <vector>
#include <utility>
#include <string>
#include "Sides.h"

class Parser {
public:
    static void convert(std::string& actions);
    static std::vector<std::pair<int, bool>> parse(const std::string& actions);
    static void convertBack(std::string& actions);
};


#endif //LAB8_PARSER_H
