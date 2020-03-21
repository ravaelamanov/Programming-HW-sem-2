#include "predicates.hpp"

template<class T>
bool isNegative<T>::operator()(const T &obj) {
    return obj < 0;
}

bool inFirstQuadrant::operator()(const Point &point) {
    return point.getX() > 0 && point.getY() > 0;
}
