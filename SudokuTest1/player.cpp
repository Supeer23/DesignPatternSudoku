// player.cpp
#include <iostream>
#include <limits>
#include "player.h"

player::player() : difficulty(1) { // Initialize difficulty to 1 in the constructor
}

void player::setName(std::string n) {
    name = n;
}

std::string player::getName() const {
    return name;
}

int player::getDifficulty() const {
    return difficulty;
}

void player::setDifficulty(int d) {
    difficulty = d;
}

void player::addInfo() {
    std::cout << "Enter name: ";
    std::cin >> name;
    do {
        std::cout << "Enter Difficulty (1-3): ";
        std::cin >> difficulty;
        if (std::cin.fail() || difficulty < 1 || difficulty > 3) {
            std::cin.clear(); // Clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Invalid input. Please enter a number between 1 and 3." << std::endl;
        }
    } while (difficulty < 1 || difficulty > 3);
}
