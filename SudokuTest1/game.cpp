#include <iostream>
#include "game.h"
#include "player.h"
#include "board.h"
#include <ctime> // Include <ctime> for time function
#include <random>
using namespace std;

void game::initialize(std::string filename, int difficulty) {
    srand(static_cast<unsigned int>(std::time(nullptr)));
    int randomI = rand() % 3;
    switch (difficulty) {
        case 1:
            {
                std::string easyPlaces[] = {
                    "D:\\Tugas\\Coding\\Design Pattern\\SudokuTest1\\Board\\Easy\\easy 1.txt",
                    "D:\\Tugas\\Coding\\Design Pattern\\SudokuTest1\\Board\\Easy\\easy 2.txt",
                    "D:\\Tugas\\Coding\\Design Pattern\\SudokuTest1\\Board\\Easy\\easy 3.txt"
                };
                filename = easyPlaces[randomI];
            }
            break;
        case 2:
            {
                std::string normalPlaces[] = {
                    "D:\\Tugas\\Coding\\Design Pattern\\SudokuTest1\\Board\\Normal\\normal 1.txt",
                    "D:\\Tugas\\Coding\\Design Pattern\\SudokuTest1\\Board\\Normal\\normal 2.txt",
                    "D:\\Tugas\\Coding\\Design Pattern\\SudokuTest1\\Board\\Normal\\normal 3.txt"
                };
                filename = normalPlaces[randomI];
            }
            break;
        case 3:
            {
                std::string hardPlaces[] = {
                    "D:\\Tugas\\Coding\\Design Pattern\\SudokuTest1\\Board\\Hard\\hard 1.txt",
                    "D:\\Tugas\\Coding\\Design Pattern\\SudokuTest1\\Board\\Hard\\hard 2.txt",
                    "D:\\Tugas\\Coding\\Design Pattern\\SudokuTest1\\Board\\Hard\\hard 3.txt"
                };
                filename = hardPlaces[randomI];
            }
            break;
        default:
            std::cerr << "Invalid difficulty level!" << std::endl;
            exit(1);
            break;
    }
    board.loadBoard(filename);
}
bool game::checkWin(int row, int col, int num) const {
    // Use different variable names for loop counters
    for (int r = 0; r < s; r++) {
        for (int n = 0; n < s; n++) {
            if (!board.checkRow(r, n)) {
                return false;
            }
        }
    }
    for (int c = 0; c < s; c++) {
        for (int n = 0; n < s; n++) {
            if (!board.checkCol(c, n)) {
                return false;
            }
        }
    }
    for (int sRow = 0; sRow < s; sRow += 3) {
        for (int sCol = 0; sCol < s; sCol += 3) {
            if (!board.checkBox(sRow, sCol, num)) {
                return false;
            }
        }
    }
    return true;
}

void game::play(string name) {
    int row, col, num; // Declare row, col, and num variables

    while (!checkWin(row, col, num)) { // Call checkWin without using game::
        cout << "Current Sudoku Board:" << endl;
        board.printBoard();

        cout << "Enter row (1-9), column (1-9), and number (1-9) to make a move (e.g., 3 5 7): ";
        cin >> row >> col >> num;

        --row;
        --col;

        if (row >= 0 && row < 9 && col >= 0 && col < 9 && num >= 1 && num <= 9) {
            if (board.makeMove(row, col, num)) {
                cout << "Move successful!" << endl;
            } else {
                cout << "Invalid move. Try again." << endl;
            }
        } else {
            cout << "Invalid input. Please enter valid row, column, and number." << endl;
        }
    }
}

