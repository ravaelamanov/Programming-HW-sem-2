#ifndef LAB7_CIRCULARBUFFER_HPP
#define LAB7_CIRCULARBUFFER_HPP

#include <iterator>
#include <stdexcept>
#include <algorithm>

template<class T>
class CircularBuffer {
public:
    typedef T value_type;
    typedef T *pointer;
    typedef const T *const_pointer;
    typedef T &reference;
    typedef const T &const_reference;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;

    explicit CircularBuffer(size_type capacity);

    ~CircularBuffer();

    bool empty() const;

    void push_back(T val);

    void push_front(T val);

    void pop_back();

    void pop_front();

    reference front();

    reference back();

    const_reference front() const;

    const_reference back() const;

    reference operator[](size_type index);

    const_reference operator[](size_type index) const;

    size_type size() const;

    void resize(size_type new_size);

    class iterator : public std::iterator<std::random_access_iterator_tag, T> {
    private:
        size_type pos_;
        CircularBuffer<T> *cbuf_;
    public:
        iterator() {}

        iterator(CircularBuffer<T> *cbuf, size_type pos);

        iterator(const iterator &other);

        reference operator*();

        iterator &operator++();

        iterator &operator--();

        iterator &operator+=(int val);

        iterator &operator-=(int val);

        iterator operator+(int val) const;

        iterator operator-(int val) const;

        iterator operator+(const iterator &other) const;

        difference_type operator-(const iterator &other) const;

        bool operator==(const iterator &other) const;

        bool operator!=(const iterator &other) const;

        bool operator<(const iterator &other) const;

        bool operator<=(const iterator &other) const;

        bool operator>(const iterator &other) const;

        bool operator>=(const iterator &other) const;

    };

    iterator begin();

    iterator end();

    iterator insert(const iterator &pos, T val);

    iterator erase(const iterator &pos);

private:
    value_type *data_;
    size_type capacity_;
    size_type head_;
    size_type tail_;

    size_type increment(size_type pos, int val) const;

    size_type decrement(size_type pos, int val) const;

    void cpy_data_(value_type *destination, size_type num) const;
};

#include "CircularBuffer.tpp"

#endif //LAB7_CIRCULARBUFFER_HPP
