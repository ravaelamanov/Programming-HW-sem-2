//
// Created by Sherzod on 31.05.2020.
//

#ifndef LAB8_SOLVER_H
#define LAB8_SOLVER_H

#include "RubiksCube.h"
#include "Automat.h"
#include "Automat1.h"
#include "Automat2.h"
#include "Automat3.h"
#include "Automat4.h"
#include "Automat5.h"
#include "Automat6.h"
#include "Automat7.h"
#include "fstream"
#include "Parameter.h"
#include "State.h"
#include "Parser.h"
#include "Sides.h"

class Solver {
private:
    Automat* steps_[7];
    RubiksCube* cube_;
    std::string solution_;
    void init();
public:
    Solver(RubiksCube* cube);
    ~Solver();
    const std::string& solve();
};


#endif //LAB8_SOLVER_H
