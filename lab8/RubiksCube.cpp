//
// Created by Sherzod on 18.05.2020.
//

#include "RubiksCube.h"

void RubiksCube::CubeSide::read(std::istream &input) {
    for (int i = 0; i < 9; i++) {
        input >> side_[i];
    }
}

void RubiksCube::CubeSide::write(std::ostream &output) const {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            output << side_[i * 3 + j] << " ";
        }
        output << "\n";
    }
    output << "\n";
}

int &RubiksCube::CubeSide::operator[](size_t index) {
    if (index < 0 || index >= 9)
        throw std::out_of_range("Index out of bounds!\n");
    else
        return side_[index];
}

const int &RubiksCube::CubeSide::operator[](size_t index) const {
    if (index < 0 || index >= 9)
        throw std::out_of_range("Index out of bounds!\n");
    else
        return side_[index];
}

std::istream &operator>>(std::istream &input, RubiksCube &cube) {
    for (int i = 0; i < 6; i++) {
        cube[i].read(input);
    }
    return input;
}

std::ostream &operator<<(std::ostream &output, const RubiksCube &cube) {
    for (int i = 0; i < 6; i++) {
        cube[i].write(output);
    }
    return output;
}

void RubiksCube::toConsole() const {
    std::string sides[6] = {"DOWN", "FRONT", "RIGHT", "BACK", "LEFT", "TOP"};
    for (int i = 0; i < 6; i++) {
        std::cout << sides[i] << "\n";
        (*this)[i].write(std::cout);
    }
}

RubiksCube::CubeSide &RubiksCube::operator[](std::size_t index) {
    if (index < 0 || index >= 6)
        throw std::out_of_range("Index out of bounds!");
    else
        return sides_[index];
}

const RubiksCube::CubeSide &RubiksCube::operator[](std::size_t index) const {
    if (index < 0 || index >= 6)
        throw std::out_of_range("Index out of bounds!");
    else
        return sides_[index];
}

void RubiksCube::rotate(int side, bool dir) {
//    std::cout << side << " " << dir << "\n";
    switch (side) {
        case FRONT: {
            rotateFront(dir);
            break;
        }
        case TOP: {
            rotateTop(dir);
            break;
        }
        case RIGHT: {
            rotateRight(dir);
            break;
        }
        case BACK: {
            rotateBack(dir);
            break;
        }
        case DOWN: {
            rotateDown(dir);
            break;
        }
        case LEFT: {
            rotateLeft(dir);
            break;
        }
        default: {
            std::cout << "Error!\n";
        }
    }
}

void RubiksCube::rotateFront(bool isClockwise) {
    int oldLeft[3] = {sides_[LEFT][8], sides_[LEFT][5], sides_[LEFT][2]};
    int oldTop[3] = {sides_[TOP][6], sides_[TOP][7], sides_[TOP][8]};
    int oldRight[3] = {sides_[RIGHT][6], sides_[RIGHT][3], sides_[RIGHT][0]};
    int oldDown[3] = {sides_[DOWN][0], sides_[DOWN][1], sides_[DOWN][2]};

    if (isClockwise) {
        //trdl -> ltrd;

        //update top
        sides_[TOP][6] = oldLeft[0];
        sides_[TOP][7] = oldLeft[1];
        sides_[TOP][8] = oldLeft[2];

        //update right
        sides_[RIGHT][0] = oldTop[0];
        sides_[RIGHT][3] = oldTop[1];
        sides_[RIGHT][6] = oldTop[2];

        //update down
        sides_[DOWN][0] = oldRight[0];
        sides_[DOWN][1] = oldRight[1];
        sides_[DOWN][2] = oldRight[2];


        //update left
        sides_[LEFT][2] = oldDown[0];
        sides_[LEFT][5] = oldDown[1];
        sides_[LEFT][8] = oldDown[2];
    }
    else {
        //trdl -> rtld;

        //update top
        sides_[TOP][6] = oldRight[2];
        sides_[TOP][7] = oldRight[1];
        sides_[TOP][8] = oldRight[0];


        //update right
        sides_[RIGHT][0] = oldDown[2];
        sides_[RIGHT][3] = oldDown[1];
        sides_[RIGHT][6] = oldDown[0];

        //update down
        sides_[DOWN][0] = oldLeft[2];
        sides_[DOWN][1] = oldLeft[1];
        sides_[DOWN][2] = oldLeft[0];


        //update left
        sides_[LEFT][2] = oldTop[2];
        sides_[LEFT][5] = oldTop[1];
        sides_[LEFT][8] = oldTop[0];
    }
    rotateSide(FRONT, isClockwise);
}

void RubiksCube::rotateTop(bool isClockwise) {
    int oldBack[3] = {sides_[BACK][0], sides_[BACK][1], sides_[BACK][2]};
    int oldRight[3] = {sides_[RIGHT][0], sides_[RIGHT][1], sides_[RIGHT][2]};
    int oldFront[3] = {sides_[FRONT][0], sides_[FRONT][1], sides_[FRONT][2]};
    int oldLeft[3] = {sides_[LEFT][0], sides_[LEFT][1], sides_[LEFT][2]};

    if (isClockwise) {
        sides_[BACK][0] = oldLeft[0];
        sides_[BACK][1] = oldLeft[1];
        sides_[BACK][2] = oldLeft[2];

        sides_[RIGHT][0] = oldBack[0];
        sides_[RIGHT][1] = oldBack[1];
        sides_[RIGHT][2] = oldBack[2];

        sides_[FRONT][0] = oldRight[0];
        sides_[FRONT][1] = oldRight[1];
        sides_[FRONT][2] = oldRight[2];

        sides_[LEFT][0] = oldFront[0];
        sides_[LEFT][1] = oldFront[1];
        sides_[LEFT][2] = oldFront[2];
    }
    else {
        sides_[BACK][0] = oldRight[0];
        sides_[BACK][1] = oldRight[1];
        sides_[BACK][2] = oldRight[2];

        sides_[RIGHT][0] = oldFront[0];
        sides_[RIGHT][1] = oldFront[1];
        sides_[RIGHT][2] = oldFront[2];

        sides_[FRONT][0] = oldLeft[0];
        sides_[FRONT][1] = oldLeft[1];
        sides_[FRONT][2] = oldLeft[2];

        sides_[LEFT][0] = oldBack[0];
        sides_[LEFT][1] = oldBack[1];
        sides_[LEFT][2] = oldBack[2];
    }
    rotateSide(TOP, isClockwise);
}

void RubiksCube::rotateRight(bool isClockwise) {
    int oldTop[3] = {sides_[TOP][8], sides_[TOP][5], sides_[TOP][2]};
    int oldBack[3] = {sides_[BACK][6], sides_[BACK][3], sides_[BACK][0]};
    int oldDown[3] = {sides_[DOWN][2], sides_[DOWN][5], sides_[DOWN][8]};
    int oldFront[3] = {sides_[FRONT][2], sides_[FRONT][5], sides_[FRONT][8]};

    if (isClockwise) {
        sides_[TOP][2] = oldFront[0];
        sides_[TOP][5] = oldFront[1];
        sides_[TOP][8] = oldFront[2];

        sides_[BACK][0] = oldTop[0];
        sides_[BACK][3] = oldTop[1];
        sides_[BACK][6] = oldTop[2];

        sides_[DOWN][2] = oldBack[0];
        sides_[DOWN][5] = oldBack[1];
        sides_[DOWN][8] = oldBack[2];

        sides_[FRONT][2] = oldDown[0];
        sides_[FRONT][5] = oldDown[1];
        sides_[FRONT][8] = oldDown[2];
    }
    else {
        sides_[TOP][2] = oldBack[0];
        sides_[TOP][5] = oldBack[1];
        sides_[TOP][8] = oldBack[2];

        sides_[BACK][0] = oldDown[2];
        sides_[BACK][3] = oldDown[1];
        sides_[BACK][6] = oldDown[0];

        sides_[DOWN][2] = oldFront[0];
        sides_[DOWN][5] = oldFront[1];
        sides_[DOWN][8] = oldFront[2];

        sides_[FRONT][2] = oldTop[2];
        sides_[FRONT][5] = oldTop[1];
        sides_[FRONT][8] = oldTop[0];
    }
    rotateSide(RIGHT, isClockwise);
}

void RubiksCube::rotateBack(bool isClockwise) {
    int oldTop[3] = {sides_[TOP][2], sides_[TOP][1], sides_[TOP][0]};
    int oldLeft[3] = {sides_[LEFT][0], sides_[LEFT][3], sides_[LEFT][6]};
    int oldDown[3] = {sides_[DOWN][6], sides_[DOWN][7], sides_[DOWN][8]};
    int oldRight[3] = {sides_[RIGHT][2], sides_[RIGHT][5], sides_[RIGHT][8]};

    if (isClockwise) {
        sides_[TOP][0] = oldRight[0];
        sides_[TOP][1] = oldRight[1];
        sides_[TOP][2] = oldRight[2];

        sides_[LEFT][0] = oldTop[0];
        sides_[LEFT][3] = oldTop[1];
        sides_[LEFT][6] = oldTop[2];

        sides_[DOWN][6] = oldLeft[0];
        sides_[DOWN][7] = oldLeft[1];
        sides_[DOWN][8] = oldLeft[2];

        sides_[RIGHT][2] = oldDown[2];
        sides_[RIGHT][5] = oldDown[1];
        sides_[RIGHT][8] = oldDown[0];
    }
    else {
        sides_[TOP][0] = oldLeft[2];
        sides_[TOP][1] = oldLeft[1];
        sides_[TOP][2] = oldLeft[0];

        sides_[LEFT][0] = oldDown[0];
        sides_[LEFT][3] = oldDown[1];
        sides_[LEFT][6] = oldDown[2];

        sides_[DOWN][6] = oldRight[2];
        sides_[DOWN][7] = oldRight[1];
        sides_[DOWN][8] = oldRight[0];

        sides_[RIGHT][2] = oldTop[2];
        sides_[RIGHT][5] = oldTop[1];
        sides_[RIGHT][8] = oldTop[0];
    }
    rotateSide(BACK, isClockwise);
}

void RubiksCube::rotateDown(bool isClockwise) {
    int oldFront[3] = {sides_[FRONT][6], sides_[FRONT][7], sides_[FRONT][8]};
    int oldRight[3] = {sides_[RIGHT][6], sides_[RIGHT][7], sides_[RIGHT][8]};
    int oldBack[3] = {sides_[BACK][6], sides_[BACK][7], sides_[BACK][8]};
    int oldLeft[3] = {sides_[LEFT][6], sides_[LEFT][7], sides_[LEFT][8]};
    if (isClockwise) {
        sides_[FRONT][6] = oldLeft[0];
        sides_[FRONT][7] = oldLeft[1];
        sides_[FRONT][8] = oldLeft[2];

        sides_[RIGHT][6] = oldFront[0];
        sides_[RIGHT][7] = oldFront[1];
        sides_[RIGHT][8] = oldFront[2];

        sides_[BACK][6] = oldRight[0];
        sides_[BACK][7] = oldRight[1];
        sides_[BACK][8] = oldRight[2];

        sides_[LEFT][6] = oldBack[0];
        sides_[LEFT][7] = oldBack[1];
        sides_[LEFT][8] = oldBack[2];
    }
    else {
        sides_[FRONT][6] = oldRight[0];
        sides_[FRONT][7] = oldRight[1];
        sides_[FRONT][8] = oldRight[2];

        sides_[RIGHT][6] = oldBack[0];
        sides_[RIGHT][7] = oldBack[1];
        sides_[RIGHT][8] = oldBack[2];

        sides_[BACK][6] = oldLeft[0];
        sides_[BACK][7] = oldLeft[1];
        sides_[BACK][8] = oldLeft[2];

        sides_[LEFT][6] = oldFront[0];
        sides_[LEFT][7] = oldFront[1];
        sides_[LEFT][8] = oldFront[2];
    }
    rotateSide(DOWN, isClockwise);
}

void RubiksCube::rotateLeft(bool isClockwise) {
    int oldTop[3] = {sides_[TOP][0], sides_[TOP][3], sides_[TOP][6]};
    int oldFront[3] = {sides_[FRONT][0], sides_[FRONT][3], sides_[FRONT][6]};
    int oldDown[3] = {sides_[DOWN][0], sides_[DOWN][3], sides_[DOWN][6]};
    int oldBack[3] = {sides_[BACK][2], sides_[BACK][5], sides_[BACK][8]};

    if (isClockwise) {
        sides_[TOP][0] = oldBack[2];
        sides_[TOP][3] = oldBack[1];
        sides_[TOP][6] = oldBack[0];

        sides_[FRONT][0] = oldTop[0];
        sides_[FRONT][3] = oldTop[1];
        sides_[FRONT][6] = oldTop[2];

        sides_[DOWN][0] = oldFront[0];
        sides_[DOWN][3] = oldFront[1];
        sides_[DOWN][6] = oldFront[2];

        sides_[BACK][2] = oldDown[2];
        sides_[BACK][5] = oldDown[1];
        sides_[BACK][8] = oldDown[0];
    }
    else {
        sides_[TOP][0] = oldFront[0];
        sides_[TOP][3] = oldFront[1];
        sides_[TOP][6] = oldFront[2];

        sides_[FRONT][0] = oldDown[0];
        sides_[FRONT][3] = oldDown[1];
        sides_[FRONT][6] = oldDown[2];

        sides_[DOWN][0] = oldBack[2];
        sides_[DOWN][3] = oldBack[1];
        sides_[DOWN][6] = oldBack[0];

        sides_[BACK][2] = oldTop[2];
        sides_[BACK][5] = oldTop[1];
        sides_[BACK][8] = oldTop[0];

    }
    rotateSide(LEFT, isClockwise);
}

void RubiksCube::rotateSide(int side, bool isClockwise) {
    CubeSide oldSide = sides_[side];
    if (isClockwise) {
        sides_[side][0] = oldSide[6];
        sides_[side][1] = oldSide[3];
        sides_[side][2] = oldSide[0];

        sides_[side][3] = oldSide[7];
        sides_[side][4] = oldSide[4];
        sides_[side][5] = oldSide[1];

        sides_[side][6] = oldSide[8];
        sides_[side][7] = oldSide[5];
        sides_[side][8] = oldSide[2];
    }
    else {
        sides_[side][0] = oldSide[2];
        sides_[side][1] = oldSide[5];
        sides_[side][2] = oldSide[8];

        sides_[side][3] = oldSide[1];
        sides_[side][4] = oldSide[4];
        sides_[side][5] = oldSide[7];

        sides_[side][6] = oldSide[0];
        sides_[side][7] = oldSide[3];
        sides_[side][8] = oldSide[6];
    }
}

bool RubiksCube::checkCube() const {
    int cnt[6] = {0};
    //check centres
    for (int i = 0; i < 6; i++) {
        if (cnt[sides_[i][4]] > 0)
            return false;
        else cnt[sides_[i][4]]++;
    }
    //check other
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 9; j++) {
            if (j == 4)
                continue;
            cnt[sides_[i][j]]++;
        }
    }
    for (int i = 0; i < 6; i++) {
        if (cnt[i] != 9)
            return false;
    }
    return true;
}

bool RubiksCube::operator==(const RubiksCube &other) const {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 9; j++) {
            if ((*this)[i][j] != other[i][j])
                return false;
        }
    }
    return true;
}

void RubiksCube::shuffle() {
    std::srand(time(nullptr));
    int rotationsCnt = rand() % 100 + 100;
    for (int i = 0; i < rotationsCnt; i++) {
        rotate(rand() % 6, rand() % 2);
    }

}
