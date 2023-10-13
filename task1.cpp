#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Seed the random number generator
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // Generate a random number between 1 and 100
    int randomNumber = std::rand() % 100 + 1;

    int userGuess;
    int numberOfTries = 0;

    std::cout << "Welcome to the Number Guessing Game!" << std::endl;
    std::cout << "I'm thinking of a number between 1 and 100. Can you guess it?" << std::endl;

    while (true) {
        std::cout << "Enter your guess: ";
        std::cin >> userGuess;
        numberOfTries++;

        if (userGuess == randomNumber) {
            std::cout << "Congratulations! You guessed the correct number (" << randomNumber << ") in " << numberOfTries << " tries." << std::endl;
            break;
        } else if (userGuess < randomNumber) {
            std::cout << "Too low. Try again." << std::endl;
        } else {
            std::cout << "Too high. Try again." << std::endl;
        }
    }

    return 0;
}
