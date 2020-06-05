//
// Created by Sherzod on 31.05.2020.
//

#ifndef LAB8_STATE_H
#define LAB8_STATE_H

#include "Parameter.h"
#include "RubiksCube.h"
#include <vector>
#include <string>

class State {
private:
    std::vector<Parameter> parameters_;
    std::string actions_;
public:
    State(const std::vector<Parameter>& parameters, const std::string& actions);
    bool match(const RubiksCube& cube) const;
    const std::string& getActions() const;
};


#endif //LAB8_STATE_H
