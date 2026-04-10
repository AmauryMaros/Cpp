# Install fmt

```bash
brew install fmt
```

Allow :

```C
cout << "Guess the number (between " << minValue << " and " << maxValue << ")" << endl;

std::cout << fmt::format("Guess the number (between {} and {})", minValue, maxValue) << std::endl;

```

# Compile

```bash
clang++ -std=c++20 guess.cpp -I/opt/homebrew/include -L/opt/homebrew/lib -lfmt -o guess
```

# Run

```bash
./guess
```

