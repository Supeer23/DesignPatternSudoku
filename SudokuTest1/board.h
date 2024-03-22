#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include <time.h>
#include <random>
#include <fstream>
#include <string>
using namespace std;

const int s = 9;
const int Emt = 0;

class sBoard {
private:
    vector<vector<int>> board;
    vector<vector<bool>> preFill;
    string filename;

public:
    sBoard() : board(s, vector<int>(s, Emt)), preFill(s, vector<bool>(s, false)) {}
    bool checkRow(int row, int num) const;
    bool checkCol(int col, int num) const;
    bool checkBox(int sRow, int sCol, int num) const;
    bool isSafe(int row, int col, int num) const;
    int getNum(int row, int col) const;
    void setNum(int row, int col, int num);
    void printBoard();
    bool makeMove(int row, int col, int num);
    bool isValid(int row, int col, int num, int sRow, int sCol) const;
    void loadBoard(string& filename);
    string getFilename();
    void setFilename(string n);
};

#endif
