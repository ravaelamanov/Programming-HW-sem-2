//
// Created by Sherzod on 01.06.2020.
//

#include "Automat1.h"

const std::string &Automat1::solveStep(RubiksCube &cube) {
    while (true) {
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
        if (!found) {
            setState(getState() + 1);
            cube.rotate(TOP, true);
            solution_ += ("5+");
        }
        if (getState() >= 4) {
            break;
        }
    }
    return solution_;
}
