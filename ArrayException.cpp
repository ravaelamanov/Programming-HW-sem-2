#include "ArrayException.h"

int ArrayException::getBadIndex() const {
    return badIndex;
}

const char *ArrayException::what() const noexcept {
    return msg;
}




