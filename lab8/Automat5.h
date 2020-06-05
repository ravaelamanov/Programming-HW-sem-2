//
// Created by Sherzod on 01.06.2020.
//

#ifndef LAB8_AUTOMAT5_H
#define LAB8_AUTOMAT5_H

#include "Automat.h"

class Automat5 : public Automat {
public:
    const std::string& solveStep(RubiksCube& cube) override;
};


#endif //LAB8_AUTOMAT5_H
