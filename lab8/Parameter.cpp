//
// Created by Sherzod on 31.05.2020.
//

#include "Parameter.h"

Parameter::Parameter() {
    side_ = 0;
    position_ = 0;
    color_ = 0;
}

Parameter::Parameter(int side, int position, int color) {
    side_ = side;
    position_ = position;
    color_ = color;
}

int Parameter::side() const {
    return side_;
}

int Parameter::position() const {
    return position_;
}

int Parameter::color() const {
    return color_;
}

