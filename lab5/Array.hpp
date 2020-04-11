#ifndef LAB5_ARRAY_HPP
#define LAB5_ARRAY_HPP

#include "ArrayException.h"


template<class T, int N>
class Array {
    T *array;
public:
    Array();
    T &operator[](int index);
    const T &operator[](int index) const;
    ~Array();
};

#include "Array.tpp"


#endif //LAB5_ARRAY_HPP
