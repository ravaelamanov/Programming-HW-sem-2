#include <exception>

#ifndef LAB5_ARRAYEXCEPTION_H
#define LAB5_ARRAYEXCEPTION_H


class ArrayException : public std::exception {
    int badIndex;
    const char* msg;
public:
    ArrayException(int badIndex, const char* msg) {
        this->badIndex = badIndex;
        this->msg = msg;
    }
    const char* what() const noexcept override;
    int getBadIndex() const;
};


#endif //LAB5_ARRAYEXCEPTION_H
