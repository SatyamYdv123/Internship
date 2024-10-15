#include <iostream>
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()

int main() {
    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(0)));

    // Generate a random number between 1 and 100
    int randomNumber = std::rand() % 100 + 1;
    int userGuess = 0;

    std::cout << "Welcome to the Guessing Game!" << std::endl;
    std::cout << "I have selected a random number between 1 and 100." << std::endl;
    std::cout << "Try to guess it!" << std::endl;

    // Loop until the user guesses the correct number
    while (userGuess != randomNumber) {
        std::cout << "Enter your guess: ";
        std::cin >> userGuess;

        if (userGuess < randomNumber) {
            std::cout << "Too low! Try again." << std::endl;
        } else if (userGuess > randomNumber) {
            std::cout << "Too high! Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You guessed the correct number: " << randomNumber << std::endl;
        }
    }

    return 0;
}
