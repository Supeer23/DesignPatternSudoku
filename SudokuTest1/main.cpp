#include<iostream>
#include"board.cpp"
#include"board.h"
#include"player.cpp"
#include"player.h"
#include"game.cpp"
#include"game.h"
using namespace std;

int main(){
    game game;
    sBoard board;
    player player;
    game.initialize(board.getFilename(), player.getDifficulty());
    game.play(player.getName());
}