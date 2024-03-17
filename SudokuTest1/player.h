#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string.h>
using namespace std;

class player{
    private:
    string name;
    int numPre;
    public:
    player();
    string getName()const;
    void setName(string n);
    int getPreFillNumber() const;
};

#endif