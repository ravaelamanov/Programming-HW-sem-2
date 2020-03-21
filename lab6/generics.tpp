#include "generics.hpp"

template <class It_type, class Predicate>
bool any_of(It_type it, It_type end, Predicate pred) {
    for (; it != end; it++) {
        if (pred(*it))
            return true;
    }
    return false;
}

template <class It_type, class T>
int find_backward(It_type it, It_type end, const T &obj) {
    int pos = -1;
    for(int counter = 0; it != end; it++, counter++) {
        if (*it == obj) {
            pos = counter;
        }
    }
    return pos;
}

template <class It_type, class Predicate>
bool is_partitioned(It_type it, It_type end, Predicate pred) {
    bool temp = pred(*it);
    bool isPartitioned = false;
    it++;
    for (; it != end; it++) {
        if (pred(*it) != temp && !isPartitioned) {
            temp = pred(*it);
            isPartitioned = true;
        }
        if (isPartitioned && pred(*it) != temp) {
            return false;
        }
    }
    return isPartitioned;
}

