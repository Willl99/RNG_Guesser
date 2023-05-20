#include <iostream>
#include <ctime>
#include <sstream>
#include <algorithm>
#include <vector>
#include <limits>

int rng(int seed) {
    return (seed + 1325) % 10;
}

int getInput() {
    std::vector<int> validNumbers{ 0,1,2,3,4,5,6,7,8,9,10 };
    int guess;
    bool valid = false;
    while (!valid) {
        std::cout << "Guess a random number between 0 and 10: ";
        std::cin >> guess;

        if ((std::cin) && (std::find(validNumbers.begin(), validNumbers.end(), guess) != validNumbers.end())) {
            valid = true;
        }
        else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input, please try again." << std::endl;
        }
    }
    return guess;
}

int main() {
    bool playAgain = true;

    while (playAgain) {
        auto seconds = time(NULL);
        int integerSeconds = static_cast<int>(seconds);

        int randomInt = rng(integerSeconds);

        int userGuess = getInput();

        if (userGuess == randomInt) {
            std::cout << "You guessed correctly." << std::endl;
        }
        else {
            std::cout << "Sorry, the right number was " << randomInt << "." << std::endl;
        }

        std::cout << "Do you want to play again? (y/n): ";
        char playAgainInput;
        std::cin >> playAgainInput;

        playAgain = (playAgainInput == 'y' || playAgainInput == 'Y');
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return 0;
}
