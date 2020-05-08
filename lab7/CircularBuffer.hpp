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

    explicit CircularBuffer(size_type capacity) {
        capacity_ = capacity;
        data_ = new value_type[capacity_ + 1];
        head_ = 0;
        tail_ = 0;
    }

    ~CircularBuffer() {
        delete[] data_;
    }

    bool empty() const {
        return head_ == tail_;
    }

    void push_back(T val) {
        if (tail_ == decrement(head_, 1))
            head_ = increment(head_, 1);

        data_[tail_] = val;
        tail_ = increment(tail_, 1);
    }

    void push_front(T val) {
        if (tail_ == decrement(head_, 1)) {
            tail_ = decrement(tail_, 1);
        }

        head_ = decrement(head_, 1);
        data_[head_] = val;
    }

    void pop_back() {
        if (empty())
            throw std::out_of_range("Buffer underflow!\n");
        else
            tail_ = decrement(tail_, 1);
    }

    void pop_front() {
        if (empty())
            throw std::out_of_range("Buffer underflow!\n");
        else
            head_ = increment(head_, 1);
    }

    reference front() {
        return data_[head_];
    }

    reference back() {
        return data_[decrement(tail_, 1)];
    }

    const_reference front() const {
        return data_[head_];
    }

    const_reference back() const {
        return data_[increment(head_, capacity_)];
    }

    reference operator [] (size_type index) {
        if (index >= capacity_ + 1)
            throw std::out_of_range("Buffer overflow!\n");
        return data_[increment(head_, index)];
    }

    const_reference operator [] (size_type index) const {
        if (index >= capacity_ + 1)
            throw std::out_of_range("Buffer overflow!\n");
        return data_[increment(head_, index)];
    }

    size_type size() const {
        return decrement(tail_, head_);
    }

    void resize(size_type new_size) {
        pointer new_data = new value_type[new_size + 1];
        cpy_data_(new_data, std::min(decrement(tail_, head_), new_size));
        delete [] data_;
        data_ = new_data;
        capacity_ = new_size;
        head_ = 0;
        tail_ = new_size;
    }

    class iterator : public std::iterator<std::random_access_iterator_tag, T> {
    private:
        size_type pos_;
        CircularBuffer<T>* cbuf_;
    public:
        iterator() {}
        iterator(CircularBuffer<T>* cbuf, size_type pos) {
            this->pos_ = pos;
            this->cbuf_ = cbuf;
        }
        iterator(const iterator& other) {
            this->cbuf_ = other.cbuf_;
            this->pos_ = other.pos_;
        }
        reference operator * () {return (*cbuf_)[pos_];}
        iterator& operator ++ () {pos_ = cbuf_->increment(pos_, 1); return *this;}
        iterator& operator -- () {pos_ = cbuf_->decrement(pos_, 1); return *this;}
        iterator& operator += (int val) {pos_ = cbuf_->increment(pos_, val); return *this;}
        iterator& operator -= (int val) {pos_ = cbuf_->decrement(pos_, val); return *this;}
        iterator operator + (int val) const {return iterator(cbuf_, cbuf_->increment(pos_, val));}
        iterator operator - (int val) const {return iterator(cbuf_, cbuf_->decrement(pos_, val));}
        iterator operator + (const iterator& other) const {return iterator(cbuf_, cbuf_->decrement(pos_, other.pos_));}
        difference_type operator - (const iterator& other) const {return cbuf_->decrement(pos_, other.pos_);}
        bool operator == (const iterator& other) const {return pos_ == other.pos_;}
        bool operator != (const iterator& other) const {return !(*this == other);}
        bool operator < (const iterator& other) const {
            if (pos_ < cbuf_->head_ && other.pos_ < cbuf_->head_ || pos_ >= cbuf_->head_ && other.pos_ >= cbuf_->head_) {
                return pos_ < other.pos_;
            }
            else
                return pos_ > other.pos_;
        }
        bool operator <= (const iterator& other) const {return *this < other || *this == other;}
        bool operator > (const iterator& other) const {return !(*this < other);}
        bool operator >= (const iterator& other) const {return *this > other || *this == other;}

    };

    iterator begin() {
        return iterator(this, 0);
    }
    iterator end() {
        return iterator(this, tail_);
    }

    iterator insert(const iterator& pos, T val) {
        if (pos >= iterator(this, capacity_))
            throw std::out_of_range("Buffer overflow!\n");
        auto it = pos;
        T temp = val;
        tail_ = increment(tail_, 1);
        for (; it != end(); ++it) {
            std::swap(*it, temp);
        }
        if (tail_ == head_)
            head_ = increment(head_, 1);
        return pos;
    }

    void erase(iterator pos) {
        if (empty())
            throw std::out_of_range("Buffer underflow!\n");
        auto it = end() - 1;
        T temp = *it;
        for (; pos <= it; --it) {
            std::swap(*it, temp);
        }
        tail_ = decrement(tail_, 1);
    }

private:
    value_type *data_;
    size_type capacity_;
    size_type head_;
    size_type tail_;

    size_type increment(size_type pos, int val) const {
        return (pos + val) % (capacity_ + 1);
    }

    size_type decrement(size_type pos, int val) const {
        return (pos + capacity_ + 1 - val) % (capacity_ + 1);
    }

    void cpy_data_(value_type *destination, size_type num) const {
        for (int i = 0; i < num; i++) {
            destination[i] = (*this)[i];
        }
    }
};


#include "CircularBuffer.hpp"

#endif //LAB7_CIRCULARBUFFER_HPP

