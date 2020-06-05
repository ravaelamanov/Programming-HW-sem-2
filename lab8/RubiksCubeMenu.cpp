//
// Created by Sherzod on 05.06.2020.
//

#include "RubiksCubeMenu.h"

RubiksCubeMenu::RubiksCubeMenu() {
    std::ifstream fin("solved.txt");
    fin >> cube;
    printActionList();
}

void RubiksCubeMenu::printActionList() {
    std::cout << "Action list:\n";
    std::cout << "1: Read cube from file\n";
    std::cout << "2: Write cube to file\n";
    std::cout << "3: Check cube invariant\n";
    std::cout << "4: Write cube to console\n";
    std::cout << "5: Rotate cube\n";
    std::cout << "6: Shuffle cube\n";
    std::cout << "7: Solve cube\n";
    std::cout << "8: Quit\n";
}

void RubiksCubeMenu::run() {
    int action;
    std::cout << "Choose action: ";
    std::cin >> action;
    while (action != QUIT) {
        exectue(action);
        std::cout << "Choose action: ";
        std::cin >> action;
    }
}

void RubiksCubeMenu::exectue(int action) {
    switch (action) {
        case READ: {
            std::cout << "Input file name: ";
            std::string fileName;
            std::cin >> fileName;
            std::ifstream fin(fileName);
            fin >> cube;
            break;
        }
        case WRITE: {
            std::cout << "Input file name: ";
            std::string fileName;
            std::cin >> fileName;
            std::ofstream fout(fileName);
            fout << cube;
            break;
        }
        case CHECK: {
            bool isInvariant = cube.checkCube();
            if (isInvariant)
                std::cout << "Is correct invariant\n";
            else
                std::cout << "Is not correct invariant\n";
            break;
        }
        case CONSOLE: {
            cube.toConsole();
            break;
        }
        case ROTATE: {
            std::cout << "Input rotations (ex. R+U-D+L+R-): ";
            std::string rotations;
            std::cin >> rotations;
            Parser::convert(rotations);
            std::vector<std::pair<int, bool>> moves = Parser::parse(rotations);
            for (auto & move : moves)
                cube.rotate(move.first, move.second);
            break;
        }
        case SHUFFLE: {
            cube.shuffle();
            break;
        }
        case SOLVE: {
            Solver solver(&cube);
            std::string solution = solver.solve();
            std::cout << "Rotations count: " << solution.length() / 2 << "\n";
            std::cout << "Solution: " << solution << "\n";
            break;
        }
        default: return;
    }
}
