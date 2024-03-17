#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "player.h"

class game : public player {
private:
    // No need for a redundant member variable
    sBoard board;
public:
    // No need to declare sBoard again; it's already inherited from player
    void initialize(int numPre);
    bool checkWin(int row, int col, int num) const;
    void play(string playerName);
};

#endif
