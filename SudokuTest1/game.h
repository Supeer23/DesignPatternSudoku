#ifndef GAME_H
#define GAME_H
#include <ctime>
#include <random>
#include "board.h"
#include "player.h"

class game : public player {
private:
    // No need for a redundant member variable
    player player;
    sBoard board;
public:
    // No need to declare sBoard again; it's already inherited from player
    void initialize(string fileplace, int difficulty);
    bool checkWin(int row, int col, int num) const;
    void play(string playerName);
    
};

#endif
