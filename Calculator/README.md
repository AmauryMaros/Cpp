# Compile
g++ calculator.cpp -o calculator
clang++ -std=c++20 calculator.cpp -I/opt/homebrew/include -L/opt/homebrew/lib -lfmt -o calculator

# Run
./calculator