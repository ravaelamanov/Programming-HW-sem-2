//
// Created by Sherzod on 18.05.2020.
//

#ifndef LAB8_RUBIKSCUBE_H
#define LAB8_RUBIKSCUBE_H

#include <iostream>
#include "Sides.h"
#include <ctime>


class RubiksCube {
private:
    struct CubeSide {
        int side_[9];
        void read(std::istream& input);
        void write(std::ostream& output) const;
        int& operator [] (size_t index);
        const int& operator [] (size_t index) const;
    };
    CubeSide sides_[6];

    void rotateFront(bool isClockwise);
    void rotateTop(bool isClockwise);
    void rotateRight(bool isClockwise);
    void rotateBack(bool isClockwise);
    void rotateDown(bool isClockwise);
    void rotateLeft(bool isClockwise);
    void rotateSide(int side, bool isClockwise);
public:
    friend std::istream& operator >> (std::istream& input, RubiksCube& cube);
    friend std::ostream& operator << (std::ostream& output, const RubiksCube& cube);
    void toConsole() const;
    void rotate(int side, bool dir);
    bool checkCube() const;
    CubeSide& operator [] (std::size_t index);
    const CubeSide& operator [] (std::size_t index) const;
    bool operator == (const RubiksCube& other) const;
    void shuffle();
};


#endif //LAB8_RUBIKSCUBE_H
