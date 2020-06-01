//
// Created by Sherzod on 31.05.2020.
//

#ifndef LAB8_SOLVER_H
#define LAB8_SOLVER_H

#include "RubiksCube.h"
#include "Automat.h"
#include "fstream"
#include "Parameter.h"
#include "State.h"
#include "Parser.h"
#include "Sides.h"

class Solver {
private:
    Automat steps_[7];
    RubiksCube cube_;
    void init();
public:
    Solver(RubiksCube& cube);
    RubiksCube& solve();
};


#endif //LAB8_SOLVER_H
