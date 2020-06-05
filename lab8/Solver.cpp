//
// Created by Sherzod on 31.05.2020.
//

#include "Solver.h"

Solver::Solver(RubiksCube *cube) {
    cube_ = cube;
    init();
}

void Solver::init() {
    std::ifstream fin("automats.aut");
    steps_[0] = new Automat1();
    steps_[1] = new Automat2();
    steps_[2] = new Automat3();
    steps_[3] = new Automat4();
    steps_[4] = new Automat5();
    steps_[5] = new Automat6();
    steps_[6] = new Automat7();
    for (int i = 0; i < 7; i++) {
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
        steps_[i]->initAutomat(states);
    }
}

const std::string& Solver::solve() {
    if (!cube_->checkCube()) {
        std::cout << "Invalid Invariant!\n";
        return solution_;
    }
    for (int i = 0; i < 7; i++) {
        solution_ += steps_[i]->solveStep(*cube_);
    }
    Parser::convertBack(solution_);
    return solution_;
}

Solver::~Solver() {
    for (int i = 0; i < 7; i++) {
        delete steps_[i];
    }
}
