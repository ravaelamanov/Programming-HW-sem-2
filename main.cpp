#include <iostream>
#include "ArrayException.h"
#include "Array.hpp"

using namespace std;

template<class T>
T maximum(T ob1, T ob2) {
    if (ob1 > ob2)
        return ob1;
    else
        return ob2;
}

int main() {
    cout << maximum("asd", "abc") << "\n";
    Array<int, 10> arr;

    for (int i = 0; i < 10; i++) {
        arr[i] = i;
        cout << arr[i] << " ";
    }
    cout << "\n";
    try {
        cout << arr[10];
    }
    catch (ArrayException &ex) {
        cout << ex.what();
        cout << ex.getBadIndex();
    }

    return 0;
}
