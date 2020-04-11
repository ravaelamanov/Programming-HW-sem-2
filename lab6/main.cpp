#include <iostream>
#include <vector>
#include "generics.hpp"
#include "predicates.hpp"
#include "Point.h"

int main() {
    std::vector<int> numbers;
    numbers.push_back(-1);
    numbers.push_back(-2);
    numbers.push_back(3);
    numbers.push_back(4);
    if (any_of(numbers.begin(), numbers.end(), isNegative<int>()))
        std::cout << "exists negative\n";
    std::cout << "find_backward(3): " << find_backward(numbers.begin(), numbers.end(), 3) << "\n";
    if (is_partitioned(numbers.begin(), numbers.end(), isNegative<int>()))
        std::cout << "numbers is negative partitioned\n\n";

    std::vector<Point> points;
    for (int i = 0; i < 10; i++) {
        points.emplace_back(i, i);
    }
    if (any_of(points.begin(), points.end(), inFirstQuadrant())) {
        std::cout << "exists point in first quadrant\n";
    }
    Point find{2 , 2};
    std::cout << "find_backward(2, 2): " << find_backward(points.begin(), points.end(), find) << "\n";
    points.clear();
    points.emplace_back(1, 1); //in first quadrant
    points.emplace_back(1, 2); //in first quadrant
    points.emplace_back(-1, -1); //in third quadrant
    points.emplace_back(-1, 1);//in second quadrant
    points.emplace_back(1, -1);//in fourth quadrant
    if (is_partitioned(points.begin(), points.end(), inFirstQuadrant())) {
        std::cout << "points is partitioned";
    }
    return 0;
}
