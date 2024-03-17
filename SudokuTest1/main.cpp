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
    player player;
    game.initialize(player.getPreFillNumber());
    game.play(player.getName());
}