<div align="center">
<h1>Market Data Processing</h1>
<span>💡 This repository aims to provide code with <strong>good readability</strong> and <strong>consistent style</strong> for the given prompt in C++20.</i></span>
</div>

## Formatting

| Language   | Formatter                                                   | Style Guide                                                                       | Configuration                                                                  |
| ---------- | ----------------------------------------------------------- | --------------------------------------------------------------------------------- | ------------------------------------------------------------------------------ |
| C++        | [ClangFormat](https://clang.llvm.org/docs/ClangFormat.html) | [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)       | [`.clang-format`](https://github.com/iotaaxel/Boerberl/blob/main/.clang-format) |

## Objective
Create a C++ function to process and efficiently store market data.

## Function Signature
```cpp 
void on_market_data(char const* data);
```

## Input Data Format
The function will receive a stream of strings with the following format:
```cpp 
<SYMBOL> <BID_PRICE> <ASK_PRICE> <BID_SIZE> <ASK_SIZE>\n
```
* Each item in the string is separated by a space.
* Each string is delimited by a newline (`\n`).

This represents the top-of-book snapshots of the current state of market data for a symbol.

## Requirements
1. Your code should parse the given data.
2. Implement a data structure that allows the user to retrieve the latest top-of-book market
data snapshot by symbol.
3. Aim for efficiency in both space and time complexity.
4. You can use the Standard Template Library (STL) for your solution.

## Optional (but recommended)
* Include unit tests to verify the correctness of your implementation.
* Provide sample usage of your function.
* If necessary, include Makefiles or any build instructions.
* Include any additional documentation or comments to support or clarify the code.

## Submission Guidelines
* Ensure your code is well-commented and adheres to coding best practices.
* Include all necessary files and dependencies for building and running your solution.
* Submit your solution as a compressed folder containing all necessary files.

## License

Licensed under the MIT License, Copyright © 2019-2024
[Axel Iota](https://github.com/iotaaxel/Boerberl).

<div align="center">
  <sub>Assembled with ❤️ in New York.</sub>
</div>
