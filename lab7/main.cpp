#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include "CircularBuffer.hpp"

template<class T>
void printBuffer(const CircularBuffer<T>& cb) {
    for (int i = 0; i < cb.size(); i++) {
        std::cout << cb[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    CircularBuffer<int> cb(10);
    std::cout << "cb.push_back(0...9): ";
    for(int i = 0; i < 10; i++) {
        cb.push_back(i);
    }
    printBuffer(cb);

    std::cout << "cb.push_back(10...14): ";
    for (int i = 0; i < 5; i++) {
        cb.push_back(10 + i);
    }
    printBuffer(cb);

    std::cout << "cb.push_front(-1): ";
    cb.push_front(-1);
    printBuffer(cb);

    std::cout << "cb.pop_back() 2x: ";
    cb.pop_back();
    cb.pop_back();
    printBuffer(cb);

    std::cout << "cb.pop_front() 2x: ";
    cb.pop_front();
    cb.pop_front();
    printBuffer(cb);

    std::cout << "cb.resize(4): ";
    cb.resize(4);
    printBuffer(cb);

    std::cout << "cb.resize(10) and cb[4...9] = {6...1}: ";
    cb.resize(10);
    for (int i = 4; i < 10; i++) {
        cb[i] = 10 - i;
    }
    printBuffer(cb);

    std::cout << "std::accumulate(cb.begin(), cb.end(), 0): " << std::accumulate(cb.begin(), cb.end(), 0) << "\n";

    std::cout << "std::sort(cb.begin(), cb.end()): ";
    std::sort(cb.begin(), cb.end());
    printBuffer(cb);

    std::cout << "std::reverse(cb.begin(), cb.end()): ";
    std::reverse(cb.begin(), cb.end());
    printBuffer(cb);

    auto it = cb.begin() + 5;
    std::cout << "cb.insert(it, 100): ";
    cb.insert(it, 100);
    printBuffer(cb);

    std::cout << "cb.erase(it): ";
    cb.erase(it);
    printBuffer(cb);

    return 0;
}
