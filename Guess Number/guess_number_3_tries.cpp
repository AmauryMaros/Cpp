#include <fmt/core.h>
#include <iostream>
#include <random> 

int main(){

    // Define variables
    int minValue = 0, maxValue = 100;

    std::random_device rd;                                      // 1. Obtain a seed from hardware to initialize the generator
    std::mt19937 gen(rd());                                     // 2. Choose a generator engine (Mersenne Twister is standard)
    std::uniform_int_distribution<> distr(minValue, maxValue);  // 3. Define the range [min, max] (inclusive)
    int secretNumber = distr(gen);                              // 4. Generate the random integer

    int guessNumber;
    int counter = 1;
    int guessLimit = 6;
    bool runGuess = true;

    std::cout << fmt::format("Guess the number (between {} and {}). You have {} tries. {}", minValue, maxValue, guessLimit) << std::endl;
    std::cin >> guessNumber;

    while (guessNumber != secretNumber && runGuess)
    {
        // Update counter and number of tries
        counter++;
        guessLimit--;

        // Give hints Lower or Higher
        if (guessNumber < secretNumber && guessLimit > 0)
        {
            std::cout << fmt::format("Higher... You have {} tries", guessLimit) << std::endl;
            std::cin >> guessNumber;
        } else if (guessNumber > secretNumber && guessLimit > 0)
        {
            std::cout << fmt::format("Lower... You have {} tries", guessLimit) << std::endl;
            std::cin >> guessNumber;
        } else if (guessNumber == secretNumber && guessLimit >0)
        {
            std::cout << fmt::format("You found it in {} tries. The secet number was {}", counter, secretNumber) << std::endl;
        } else if (guessLimit == 0)
        {
            runGuess = false;
            std::cout << fmt::format("No more tries. The secret number was {}.", secretNumber) << std::endl;
        }
    }
}