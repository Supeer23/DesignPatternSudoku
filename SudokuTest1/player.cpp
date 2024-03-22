#include <iostream>
#include <string> // Include <string> for std::string
#include "player.h"

using namespace std;

player::player() {
    cout << "Enter your Name: ";
    cin >> name;
    // Input validation for difficulty level
    do {
        cout << "Enter Difficulty (1-3): ";
        cin >> difficulty;
        if (cin.fail() || difficulty < 1 || difficulty > 3) {
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please enter a number between 1 and 3." << endl;
        }
    } while (difficulty < 1 || difficulty > 3);
}

string player::getName() const {
    return name;
}

int player::getDifficulty() const {
    return difficulty;
}

void player::setDifficulty(int d) {
    difficulty = d;
}
