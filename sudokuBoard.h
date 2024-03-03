// sudokuBoard.h

#ifndef SUDOKUBOARD_H
#define SUDOKUBOARD_H

class sudokuBoard {
public:
    sudokuBoard();  // Default constructor
    sudokuBoard(const int initialGrid[9][9]);  // Constructor with initial grid
    void printBoard() const;
    bool makeMove(int row, int col, int num);
    bool isValid(int row, int col, int num) const;
    bool isSolved() const;
    bool isFull() const;
private:
    int board[9][9];
};

#endif // SUDOKUBOARD_H
