//
// Created by Sherzod on 31.05.2020.
//

#include "State.h"

State::State(const std::vector<Parameter> &parameters, const std::string &actions) {
    parameters_ = parameters;
    actions_ = actions;
}

bool State::match(const RubiksCube &cube) const {
    for (int i = 0; i < parameters_.size(); i++) {
        int side = parameters_[i].side();
        int position = parameters_[i].position();
        if (parameters_[i].color() >= 0 && cube[side][position] != parameters_[i].color() || parameters_[i].color() < 0 &&
            cube[side][position] == std::abs(parameters_[i].color()))
            return false;
    }
    return true;
}

const std::string& State::getActions() const {
    return actions_;
}
