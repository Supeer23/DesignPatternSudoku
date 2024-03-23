// player.h
#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class player {
private:
    std::string name;
    int difficulty;
public:
    player(); // Constructor
    void setName(std::string n);
    std::string getName() const;
    int getDifficulty() const;
    void setDifficulty(int d);
    void addInfo();
};

#endif // PLAYER_H
