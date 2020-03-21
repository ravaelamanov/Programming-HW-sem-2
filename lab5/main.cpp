#include <iostream>
#include "ArrayException.h"
#include "Array.hpp"

template<class T>
T minimum(T ob1, T ob2) {
    if (ob1 < ob2)
        return ob1;
    else
        return ob2;
}

int main() {
    //variant 2
    std::cout << minimum(1, 5) << "\n";
    std::cout << minimum(1.5, 2.2) << "\n";
    std::cout << minimum('b', 'a') << "\n";
    std::cout << minimum("asd", "abc") << "\n";
    Array<int, 10> arr;

    for (int i = 0; i < 10; i++) {
        arr[i] = i;
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
    try {
        std::cout << arr[10];
    }
    catch (ArrayException &ex) {
        std::cout << ex.what();
        std::cout << ex.getBadIndex() << "\n";
    }

    try {
        std::cout << arr[-1];
    }
    catch (ArrayException &ex) {
        std::cout << ex.what();
        std::cout << ex.getBadIndex();
    }

    return 0;
}
