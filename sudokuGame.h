// sudokuGame.h
#ifndef SUDOKUGAME_H
#define SUDOKUGAME_H
#include "sudokuBoard.h"

class sudokuGame {
private:
    sudokuBoard board;

public:
    sudokuGame(const int initialGrid[9][9]);
    void play();
};

#endif // SUDOKU_GAME_H
