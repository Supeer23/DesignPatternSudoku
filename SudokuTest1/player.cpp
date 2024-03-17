#include <iostream>
#include <string> // Include <string> instead of <string.h>
#include "player.h"

// Avoid using namespace std globally

player::player() {
    std::cout << "Enter your Name: " << std::endl;
    std::getline(std::cin, name); // Use getline() to handle names with spaces
    std::cout << "Enter how many pre-filled numbers: " << std::endl;
    while (!(std::cin >> numPre)) {
        std::cout << "Invalid input. Please enter a number: " << std::endl;
        std::cin.clear(); // Clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the newline character
}


std::string player::getName() const {
    return name;
}

int player::getPreFillNumber() const {
    return numPre;
}
