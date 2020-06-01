//
// Created by Sherzod on 31.05.2020.
//

#include "Automat.h"

Automat::Automat() {
    state_  = 0;
}

void Automat::initAutomat(const std::vector<State>& states) {
    states_ = states;
}

int Automat::getState() const {
    return state_;
}

void Automat::setState(int state) {
    state_ = state;
}

int Automat::size() const {
    return states_.size();
}
