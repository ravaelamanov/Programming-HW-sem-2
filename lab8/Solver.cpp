//
// Created by Sherzod on 31.05.2020.
//

#include "Solver.h"

Solver::Solver(RubiksCube &cube) {
    cube_ = cube;
    init();
}

void Solver::init() {
    std::ifstream fin("automats.aut");
    for (int i = 0; i < 5; i++) {
        std::vector<State> states;
        int statesCnt, parameterCnt, side, position, color;
        std::string action;
        fin >> statesCnt;
        for (int j = 0; j < statesCnt; j++) {
            fin >> parameterCnt;
            std::vector<Parameter> parameters;
            for (int k = 0; k < parameterCnt; k++) {
                fin >> side >> position >> color;
                Parameter param(side, position, color);
                parameters.push_back(param);
            }
            fin >> action;
            State state(parameters, action);
            states.push_back(state);
        }
        steps_[i].initAutomat(states);
    }
}

RubiksCube& Solver::solve() {
    for (int i = 0; i < 5; i++) {
        int cnt = 0;
        while (true) {
            bool found = false;
            int first = 0;
            int last = steps_[i].size();
            if (i == 2) {
                last = 8;
                if (steps_[i].getState() == 4) {
                    first = 8;
                    last = 16;
                }
            }
            if (i == 4) {
                switch (cnt) {
                    case 0: {
                        last = 3;
                        break;
                    }
                    case 1: {
                        first = 3;
                        last = 5;
                        break;
                    }
                    case 2: {
                        first = 5;
                        last = 6;
                        break;
                    }
                    default: {
                        std::cout << "Error\n";
                        break;
                    }
                }
            }
            for (int j = first; j < last; j++) {
                State state = steps_[i][j];
                if (state.match(cube_)) {
                    found = true;
                    std::vector<std::pair<int, bool>> actions = Parser::parse(state.getActions());
                    for (int k = 0; k < actions.size(); k++) {
                        cube_.rotate(actions[k].first, actions[k].second);
                    }
                    steps_[i].setState(0);
                    break;
                }
            }
            if (cnt == 3 && i == 4)
                break;
            if (!found) {
                if (i == 3)
                    break;
                if (i < 4) {
                    steps_[i].setState(steps_[i].getState() + 1);
                    cube_.rotate(TOP, true);
                }
            }
            if (steps_[i].getState() >= 4) {
                if (i < 2 || i == 2 && last == 16)
                    break;
            }
            cnt++;
        }
    }
    return cube_;
}
