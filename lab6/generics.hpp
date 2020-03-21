#ifndef LAB6_GENERICS_HPP
#define LAB6_GENERICS_HPP

template <class It_type, class Predicate>
bool any_of(It_type it, It_type end, Predicate pred);

template <class It_type, class T>
int find_backward(It_type it, It_type end, const T &obj);

template <class It_type, class Predicate>
bool is_partitioned(It_type it, It_type end, Predicate pred);

#include "generics.tpp"

#endif //LAB6_GENERICS_HPP
