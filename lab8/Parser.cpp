//
// Created by Sherzod on 31.05.2020.
//

#include "Parser.h"


std::vector<std::pair<int, bool>> Parser::parse(const std::string &actions) {
    std::vector<std::pair<int, bool>> parsed;
    for (int i = 0; i < actions.length() - 1; i += 2) {
        int side = actions[i] - '0';
        bool dir = actions[i + 1] == '+';
        parsed.emplace_back(side, dir);
    }
    return parsed;
}

void Parser::convert(std::string& actions) {
    for (int i = 0; i < actions.length(); i += 2) {
        switch (actions[i]) {
            case 'F': {
                actions[i] = FRONT + '0';
                break;
            }
            case 'B': {
                actions[i] = BACK + '0';
                break;
            }
            case 'R': {
                actions[i] = RIGHT + '0';
                break;
            }
            case 'L': {
                actions[i] = LEFT + '0';
                break;
            }
            case 'U': {
                actions[i] = TOP + '0';
                break;
            }
            case 'D': {
                actions[i] = DOWN + '0';
                break;
            }
            default: break;
        }
    }
}

void Parser::convertBack(std::string &actions) {
    for (int i = 0; i < actions.length(); i += 2) {
        switch (actions[i]) {
            case '0': {
                actions[i] = 'D';
                break;
            }
            case '1': {
                actions[i] = 'F';
                break;
            }
            case '2': {
                actions[i] = 'R';
                break;
            }
            case '3': {
                actions[i] = 'B';
                break;
            }
            case '4': {
                actions[i] = 'L';
                break;
            }
            case '5': {
                actions[i] = 'U';
                break;
            }
        }
    }
}


