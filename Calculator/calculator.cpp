#include <iostream>
#include <algorithm>

using namespace std;

// Define function to verify wether input is a number
bool verifyInputIsNumber() {
    if (cin.fail()) {
        cout << "Not a number" << endl;
        cin.clear();                // reset fail state
        cin.ignore(1000, '\n');     // discard bad input
        return false;
    }
    return true;
}

int main() {

    // Define variable
    double num1, num2, result;
    char operatorArray[] = {'+', '-', '*', '/'};
    char operatorChar;

    // Ask number 1 until a number is provided
    cout << "Enter number 1: ";
    cin >> num1;
    while (!verifyInputIsNumber()) {
        cout << "Enter number 1: ";
        cin >> num1;
    }

    // Ask for basic operator
    cout << "Select an operator (+ - / *): ";
    cin >> operatorChar;

    // Check if operator is valid
    while(find(begin(operatorArray), end(operatorArray), operatorChar) == end(operatorArray)){
        cout << operatorChar << " is NOT a valid operator" << endl;
        cout << "Select an operator (+ - / *): ";
        cin >> operatorChar;
    }

    // Ask number 2 until a number is provided
    cout << "Enter number 2: ";
    cin >> num2;
    while (!verifyInputIsNumber()) {
        cout << "Enter number 2: ";
        cin >> num2;
    }

    // Do the maths
    if (operatorChar == '+'){
        result = num1 + num2;
    } else if (operatorChar == '-')
    {
        result = num1 - num2;
    } else if (operatorChar == '/')
    {
        if (num2 == 0){
            cout << "Division by 0 impossible" << endl;
            return 0;
        }
        result = num1 / num2;
    } else if (operatorChar == '*')
    {
        result = num1 * num2;
    }

    // print out result
    cout << "Result: " << num1 << operatorChar << num2 << " = " << result << endl;
    return 0;
}