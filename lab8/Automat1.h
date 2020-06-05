//
// Created by Sherzod on 01.06.2020.
//

#ifndef LAB8_AUTOMAT1_H
#define LAB8_AUTOMAT1_H

#include "Automat.h"

class Automat1 : public Automat {
public:
    const std::string& solveStep(RubiksCube &cube) override;
};


#endif //LAB8_AUTOMAT1_H
