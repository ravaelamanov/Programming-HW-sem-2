//
// Created by Sherzod on 31.05.2020.
//

#ifndef LAB8_AUTOMAT_H
#define LAB8_AUTOMAT_H

#include <vector>
#include "State.h"
#include "RubiksCube.h"
#include "Parser.h"

class Automat {
protected:
    int state_;
    std::vector<State> states_;
    std::string solution_;
public:
    Automat();
    void initAutomat(const std::vector<State>& states);
    int getState() const;
    void setState(int state);
    int size() const;
    State& operator [] (int index);
    virtual const std::string& solveStep(RubiksCube& cube) = 0;
};




#endif //LAB8_AUTOMAT_H
