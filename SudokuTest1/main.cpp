#include<iostream>
#include"board.cpp"
#include"board.h"
#include"player.cpp"
#include"player.h"
#include"game.cpp"
#include"game.h"
using namespace std;

int main(){
    game gameManager;
    sBoard board;
    player myPlayer;
    myPlayer.addInfo();
    gameManager.initialize(board.getFilename(), myPlayer.getDifficulty());
    gameManager.play(myPlayer.getName());
}