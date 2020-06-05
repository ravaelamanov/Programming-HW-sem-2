//
// Created by Sherzod on 31.05.2020.
//

#ifndef LAB8_PARAMETER_H
#define LAB8_PARAMETER_H


class Parameter {
    int side_;
    int position_;
    int color_;
public:
    Parameter();
    Parameter(int side, int position, int color);
    int side() const;
    int position() const;
    int color() const;
};


#endif //LAB8_PARAMETER_H
