//
// Created by Sherzod on 01.06.2020.
//

#include "Automat7.h"
#include "fstream"

const std::string& Automat7::solveStep(RubiksCube &cube) {
    for (int i = 0; i < 4; i++) {
        bool found = false;
        for (int j = 0; j < states_.size(); j++) {
            State state = states_[j];
            if (state.match(cube)) {
                solution_ += state.getActions();
                found = true;
                std::vector<std::pair<int, bool>> actions = Parser::parse(state.getActions());
                for (int k = 0; k < actions.size(); k++) {
                    cube.rotate(actions[k].first, actions[k].second);
                }
                setState(0);
                break;
            }
        }
        setState(getState() + 1);
        cube.rotate(TOP, true);
        solution_ += "5+";
    }
    std::ifstream in("solved.txt");
    RubiksCube solved = {};
    in >> solved;
    while (!(cube == solved)) {
        cube.rotate(TOP, true);
        solution_ += "5+";
    }
    return solution_;
}
