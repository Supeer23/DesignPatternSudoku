#include <iostream>
#include "board.h"
using namespace std;

void sBoard::setNum(int row, int col, int num) {
    board[row][col] = num;
}

int sBoard::getNum(int row, int col) const {
    return board[row][col];
}

bool sBoard::isSafe(int row, int col, int num) const {
    return !checkRow(row, num) && !checkCol(col, num) && !checkBox(row - row % 3, col - col % 3, num);
}

bool sBoard::checkRow(int row, int num) const {
    for (int col = 0; col < s; col++) {
        if (board[row][col] == num)
            return true;
    }
    return false;
}

bool sBoard::checkCol(int col, int num) const {
    for (int row = 0; row < s; row++) {
        if (board[row][col] == num)
            return true;
    }
    return false;
}

bool sBoard::checkBox(int sRow, int sCol, int num) const {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (board[row + sRow][col + sCol] == num) {
                return true;
            }
        }
    }
    return false;
}

void sBoard::generateNum(int numPre) {
    srand(time(nullptr));
    int count = 0;
    while (count < numPre) {
        int row = rand() % s;
        int col = rand() % s;
        int num = rand() % s;
        if (board[row][col] == Emt && isSafe(row, col, num)) {
            setNum(row, col, num);
            ++count;
        }
    }
}

void sBoard::printBoard() {
    system("cls");
    for (int row = 0; row < s; row++) {
        for (int col = 0; col < s; col++) {
            cout << board[row][col] << " ";
            if (col == 2 || col == 5) {
                cout << " | ";
            }
        }
        cout << endl;
        if (row == 2 || row == 5) {
            cout << "---------------------" << endl;
        }
    }
}

bool sBoard::isPrefilled(int row, int col) const {
    return preFill[row][col];
}

void sBoard::markPreFill(int row, int col) {
    preFill[row][col] = true;
}

bool sBoard::isValid(int row, int col, int num, int sRow, int sCol) const {
    return !checkRow(row, num) && !checkCol(col, num) && !checkBox(sRow, sCol, num);
}

bool sBoard::makeMove(int row, int col, int num) {
    if (!isValid(row, col, num, row - row % 3, col - col % 3) || board[row][col] != 0) {
        return false;
    }
    setNum(row, col, num);
    return true;
}
