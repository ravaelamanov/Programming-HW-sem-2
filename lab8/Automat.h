//
// Created by Sherzod on 31.05.2020.
//

#ifndef LAB8_AUTOMAT_H
#define LAB8_AUTOMAT_H

#include <vector>
#include "State.h"

class Automat {
private:
    int state_;
    std::vector<State> states_;
public:
    Automat();
    void initAutomat(const std::vector<State>& states);
    int getState() const;
    void setState(int state);
    int size() const;
    State& operator [] (int index) {
        return states_[index];
    }
};




#endif //LAB8_AUTOMAT_H
