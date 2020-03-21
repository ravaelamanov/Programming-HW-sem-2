//
// Created by Sherzod on 14.03.2020.
//

#ifndef LAB6_POINT_H
#define LAB6_POINT_H


class Point {
    double x, y;
public:
    Point(double x, double y) {
        this->x = x;
        this->y = y;
    }
    double getX() const {
        return x;
    }
    double getY() const {
        return y;
    }
    bool operator == (const Point &other) {
        return this->x == other.x && this->y == other.y;
    }
};


#endif //LAB6_POINT_H
