//
// Created by Sherzod on 05.06.2020.
//

#ifndef LAB8_RUBIKSCUBEMENU_H
#define LAB8_RUBIKSCUBEMENU_H

#include "RubiksCube.h"
#include "fstream"
#include "vector"
#include "utility"
#include "Parser.h"
#include "Solver.h"

enum Actions {
    READ = 1, WRITE, CHECK, CONSOLE, ROTATE, SHUFFLE, SOLVE, QUIT
};

class RubiksCubeMenu {
private:
    RubiksCube cube = {};
    static void printActionList() ;
    void exectue(int action);
public:
    RubiksCubeMenu();
    void run();
};


#endif //LAB8_RUBIKSCUBEMENU_H
