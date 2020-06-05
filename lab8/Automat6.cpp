//
// Created by Sherzod on 01.06.2020.
//

#include "Automat6.h"

const std::string& Automat6::solveStep(RubiksCube &cube) {
    int cnt = 0;
    while (true) {
        bool found = false;
        int first = 0;
        int last = size();

        switch (cnt) {
            case 0: {
                last = 18;
                break;
            }
            case 1: {
                first = 18;
                last = 30;
                break;
            }
            default: {
                std::cout << "Error\n";
                break;
            }
        }
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
        cnt++;
        if (cnt == 2)
            break;
    }
    return solution_;
}
