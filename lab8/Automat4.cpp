//
// Created by Sherzod on 01.06.2020.
//

#include "Automat4.h"

const std::string& Automat4::solveStep(RubiksCube &cube) {
    while (true) {
        bool found = false;
        int first = 0;
        int last = size();
        for (int j = first; j < last; j++) {
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
        if (!found) {
            break;
        }
    }
    return solution_;
}
