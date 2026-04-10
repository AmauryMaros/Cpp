#include <iostream>
#include <random> 

using namespace std;

int main(){

    // Define variables
    int minValue = 0;
    int maxValue = 100;

    std::random_device rd;                                      // 1. Obtain a seed from hardware to initialize the generator
    std::mt19937 gen(rd());                                     // 2. Choose a generator engine (Mersenne Twister is standard)
    std::uniform_int_distribution<> distr(minValue, maxValue);  // 3. Define the range [min, max] (inclusive)
    int secretNumber = distr(gen);                              // 4. Generate the random integer

    int guessNumber;

    cout << "Guess the number (between " << minValue << " and " << maxValue << ")" << endl;
    cin >> guessNumber;

    while (guessNumber != secretNumber)
    {
        if (guessNumber < secretNumber)
        {
            cout << "Higher..." << endl;
            cin >> guessNumber;
        } else if (guessNumber > secretNumber)
        {
            cout << "Lower..." << endl;
            cin >> guessNumber;
        }
    
    }
    
    cout << "You found it. The secet number was " << secretNumber << endl;
    return 0;
}