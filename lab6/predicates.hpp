#ifndef LAB6_PREDICATES_HPP
#define LAB6_PREDICATES_HPP

#include "Point.h"

template <class T>
class isNegative {
public:
    bool operator () (const T &obj);
};

class inFirstQuadrant { //checks if a point is in first quadrant
public:
    bool operator () (const Point &point);
};

#include "predicates.tpp"

#endif //LAB6_PREDICATES_HPP
