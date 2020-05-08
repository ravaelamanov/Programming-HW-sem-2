#include "CircularBuffer.hpp"

template<class T>
CircularBuffer<T>::CircularBuffer(CircularBuffer::size_type capacity) {
    capacity_ = capacity;
    data_ = new value_type[capacity_ + 1];
    head_ = 0;
    tail_ = 0;
}

template<class T>
CircularBuffer<T>::~CircularBuffer() {
    delete[] data_;
}

template<class T>
bool CircularBuffer<T>::empty() const {
    return head_ == tail_;
}

template<class T>
void CircularBuffer<T>::push_back(T val) {
    if (tail_ == decrement(head_, 1))
        head_ = increment(head_, 1);
    data_[tail_] = val;
    tail_ = increment(tail_, 1);
}

template<class T>
void CircularBuffer<T>::push_front(T val) {
    if (tail_ == decrement(head_, 1)) {
        tail_ = decrement(tail_, 1);
    }

    head_ = decrement(head_, 1);
    data_[head_] = val;
}

template<class T>
void CircularBuffer<T>::pop_back() {
    if (empty())
        throw std::out_of_range("Buffer underflow!\n");
    else
        tail_ = decrement(tail_, 1);
}

template<class T>
void CircularBuffer<T>::pop_front() {
    if (empty())
        throw std::out_of_range("Buffer underflow!\n");
    else
        head_ = increment(head_, 1);
}

template<class T>
typename CircularBuffer<T>::reference CircularBuffer<T>::front() {
    return data_[head_];
}

template<class T>
typename CircularBuffer<T>::reference CircularBuffer<T>::back() {
    return data_[decrement(tail_, 1)];
}

template<class T>
typename CircularBuffer<T>::const_reference CircularBuffer<T>::front() const {
    return data_[head_];
}

template<class T>
typename CircularBuffer<T>::const_reference CircularBuffer<T>::back() const {
    return data_[increment(head_, capacity_)];
}

template<class T>
typename CircularBuffer<T>::reference CircularBuffer<T>::operator[](CircularBuffer::size_type index) {
    if (index >= capacity_ + 1)
        throw std::out_of_range("Buffer overflow!\n");
    return data_[increment(head_, index)];
}

template<class T>
typename CircularBuffer<T>::const_reference CircularBuffer<T>::operator[](CircularBuffer::size_type index) const {
    if (index >= capacity_ + 1)
        throw std::out_of_range("Buffer overflow!\n");
    return data_[increment(head_, index)];
}

template<class T>
typename CircularBuffer<T>::size_type CircularBuffer<T>::size() const {
    return decrement(tail_, head_);
}

template<class T>
void CircularBuffer<T>::resize(CircularBuffer::size_type new_size) {
    pointer new_data = new value_type[new_size + 1];
    cpy_data_(new_data, std::min(decrement(tail_, head_), new_size));
    delete[] data_;
    data_ = new_data;
    capacity_ = new_size;
    head_ = 0;
    tail_ = new_size;
}

template<class T>
typename CircularBuffer<T>::iterator CircularBuffer<T>::begin() {
    return iterator(this, 0);
}

template<class T>
typename CircularBuffer<T>::iterator CircularBuffer<T>::end() {
    return iterator(this, tail_);
}

template<class T>
typename CircularBuffer<T>::iterator CircularBuffer<T>::insert(const CircularBuffer::iterator &pos, T val) {
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

template<class T>
typename CircularBuffer<T>::iterator CircularBuffer<T>::erase(const CircularBuffer::iterator &pos) {
    if (empty())
        throw std::out_of_range("Buffer underflow!\n");
    auto it = end() - 1;
    T temp = *it;
    for (; pos <= it; --it) {
        std::swap(*it, temp);
    }
    tail_ = decrement(tail_, 1);
    return pos;
}

/*iterator implementations*/

template<class T>
CircularBuffer<T>::iterator::iterator(CircularBuffer<T> *cbuf, CircularBuffer::size_type pos) {
    this->pos_ = pos;
    this->cbuf_ = cbuf;
}

template<class T>
CircularBuffer<T>::iterator::iterator(const CircularBuffer::iterator &other) {
    this->cbuf_ = other.cbuf_;
    this->pos_ = other.pos_;
}

template<class T>
typename CircularBuffer<T>::reference CircularBuffer<T>::iterator::operator*() {
    return (*cbuf_)[pos_];
}

template<class T>
typename CircularBuffer<T>::iterator &CircularBuffer<T>::iterator::operator++() {
    pos_ = cbuf_->increment(pos_, 1);
    return *this;
}

template<class T>
typename CircularBuffer<T>::iterator &CircularBuffer<T>::iterator::operator--() {
    pos_ = cbuf_->decrement(pos_, 1);
    return *this;
}

template<class T>
typename CircularBuffer<T>::iterator &CircularBuffer<T>::iterator::operator+=(int val) {
    pos_ = cbuf_->increment(pos_, val);
    return *this;
}

template<class T>
typename CircularBuffer<T>::iterator &CircularBuffer<T>::iterator::operator-=(int val) {
    pos_ = cbuf_->decrement(pos_, val);
    return *this;
}

template<class T>
typename CircularBuffer<T>::iterator CircularBuffer<T>::iterator::operator+(int val) const {
    return iterator(cbuf_, cbuf_->increment(pos_, val));
}

template<class T>
typename CircularBuffer<T>::iterator CircularBuffer<T>::iterator::operator-(int val) const {
    return iterator(cbuf_, cbuf_->decrement(pos_, val));
}

template<class T>
typename CircularBuffer<T>::iterator
CircularBuffer<T>::iterator::operator+(const CircularBuffer::iterator &other) const {
    return iterator(cbuf_, cbuf_->decrement(pos_, other.pos_));
}

template<class T>
typename CircularBuffer<T>::difference_type
CircularBuffer<T>::iterator::operator-(const CircularBuffer::iterator &other) const {
    return cbuf_->decrement(pos_, other.pos_);
}

template<class T>
bool CircularBuffer<T>::iterator::operator==(const CircularBuffer::iterator &other) const {
    return pos_ == other.pos_;
}

template<class T>
bool CircularBuffer<T>::iterator::operator!=(const CircularBuffer::iterator &other) const {
    return !(*this == other);
}

template<class T>
bool CircularBuffer<T>::iterator::operator<(const CircularBuffer::iterator &other) const {
    if (pos_ < cbuf_->head_ && other.pos_ < cbuf_->head_ || pos_ >= cbuf_->head_ && other.pos_ >= cbuf_->head_) {
        return pos_ < other.pos_;
    } else
        return pos_ > other.pos_;
}

template<class T>
bool CircularBuffer<T>::iterator::operator<=(const CircularBuffer::iterator &other) const {
    return *this < other || *this == other;
}

template<class T>
bool CircularBuffer<T>::iterator::operator>(const CircularBuffer::iterator &other) const {
    return !(*this < other);
}

template<class T>
bool CircularBuffer<T>::iterator::operator>=(const CircularBuffer::iterator &other) const {
    return *this > other || *this == other;
}

/*private methods implementations*/

template<class T>
typename CircularBuffer<T>::size_type CircularBuffer<T>::increment(CircularBuffer::size_type pos, int val) const {
    return (pos + val) % (capacity_ + 1);
}

template<class T>
typename CircularBuffer<T>::size_type CircularBuffer<T>::decrement(CircularBuffer::size_type pos, int val) const {
    return (pos + capacity_ + 1 - val) % (capacity_ + 1);
}

template<class T>
void CircularBuffer<T>::cpy_data_(value_type *destination, CircularBuffer::size_type num) const {
    for (int i = 0; i < num; i++) {
        destination[i] = (*this)[i];
    }
}








































