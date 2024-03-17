#include <iostream>
#include "game.h"
#include "player.h"
#include "board.h"
using namespace std;

void game::initialize(int numPre) {
    board.generateNum(numPre);
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
