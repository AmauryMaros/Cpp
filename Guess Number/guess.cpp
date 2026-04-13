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

    std::cout << fmt::format("Guess the number (between {} and {})", minValue, maxValue) << std::endl;
    std::cin >> guessNumber;

    while (guessNumber != secretNumber)
    {
        if (guessNumber < secretNumber)
        {
            std::cout << "Higher..." << std::endl;
            counter++;
            std::cin >> guessNumber;
        } else if (guessNumber > secretNumber)
        {
            std::cout << "Lower..." << std::endl;
            counter++;
            std::cin >> guessNumber;
        }
    
    }
    
    std::cout << fmt::format("You found it in {} tries. The secet number was {}", counter, secretNumber) << std::endl;
    return 0;
}