#include "Array.hpp"
template <class T, int N>
Array<T, N>::Array() {
    array = new T[N];
}

template<class T, int N>
Array<T, N>::~Array() {
    delete[] array;
}

template<class T, int N>
T &Array<T, N>::operator[](int index) {
    if (index >= N || index < 0)
        throw ArrayException(index, "Index out of bounds!\n");
    else
        return array[index];
}

template<class T, int N>
const T &Array<T, N>::operator[](int index) const {
    if (index >= N || index < 0)
        throw ArrayException(index, "Index out of bounds!\n");
    else
        return array[index];
}


