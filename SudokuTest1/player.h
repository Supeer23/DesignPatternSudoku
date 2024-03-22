#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string.h>
using namespace std;

class player{
    private:
    string name;
    int difficulty; //1-easy, 2-medium, 3-hard
    public:
    player();
    string getName()const;
    void setName(string n);
    int getDifficulty() const;
    void setDifficulty(int d);
};

#endif