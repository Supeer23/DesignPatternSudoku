#include <iostream>
#include "sudokuBoard.h"
#include "sudokuGame.h"
#include <cstdlib>
using namespace std;


sudokuBoard::sudokuBoard(const int initialGrid[9][9]) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            board[i][j] = initialGrid[i][j];
        }
    }
}

void sudokuBoard::printBoard() const {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << " " << board[i][j] << " ";
            
            if (j == 2 || j == 5) {
                cout << " | ";
            }
        }

        cout << endl;

        if (i == 2 || i == 5) {
            cout << "--------------------------------" << endl;
        }
    }
}

bool sudokuBoard::makeMove(int row, int col, int num){
    if (isValid(row, col, num) && board[row][col] == 0) {
            board[row][col] = num;
            return true;
        }

        return false;
}

bool sudokuBoard::isValid(int row, int col, int num)const{
    for (int i = 0; i < 9; ++i) {
            if (board[row][i] == num || board[i][col] == num) {
                return false;
            }
        }

        // Check if the number is not already present in the 3x3 subgrid
        int subgridStartRow = row - row % 3;
        int subgridStartCol = col - col % 3;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[subgridStartRow + i][subgridStartCol + j] == num) {
                    return false;
                }
            }
        }

        return true;
}

bool sudokuBoard::isSolved()const{
    if (!isFull()) {
            return false;
        }

        // Check if every number in each row, column, and subgrid is unique
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (!isValid(i, j, board[i][j])) {
                    return false;
                }
            }
        }
        return true;
}

bool sudokuBoard::isFull()const{
    for  (int i = 0; i <  9; ++i){
        for (int j = 0; j < 9; ++j){
           if (board[i][j]==0)
               return false;
        }
     }
     return true;
}

sudokuGame::sudokuGame(const int initialGrid[9][9]) : board(initialGrid){
    
} 

void sudokuGame::play() {
    int row, col, num;
    while (!board.isSolved()) {
        
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
    system("cls"); 
    cout << "Congratulations! Sudoku is solved." << endl;
    cout << "Final Sudoku Board:" << endl;
    board.printBoard();
}

int main (){
    int initialgrid[9][9] = {{5, 3, 0, 0, 7, 0, 0, 0, 0},
                      {6, 0, 0, 1, 9, 5, 0, 0, 0},
                      {0, 9, 8, 0, 0, 0, 0, 6, 0},
                      {8, 0, 0, 0, 6, 0, 0, 0, 3},
                      {4, 0, 0, 8, 0, 3, 0, 0, 1},
                      {7, 0, 0, 0, 2, 0, 0, 0, 6},
                      {0, 6, 0, 0, 0, 0, 2, 8, 0},
                      {0, 0, 0, 4, 1, 9, 0, 0, 5},
                      {0, 0, 0, 0, 8, 0, 0, 7, 9}};
    // Create an instance of the game with an empty grid
    sudokuGame mySudoku(initialgrid);
    // Play the game
    mySudoku.play();

    return 0;
}