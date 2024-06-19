<div align="center">
<h1>Market Data Processing</h1>
<span>💡 This repository aims to provide code with <strong>good readability</strong> and <strong>consistent style</strong> for the given prompt in C++20.</i></span>
</div>

## Formatting

| Language   | Formatter                                                   | Style Guide                                                                       | Configuration                                                                  |
| ---------- | ----------------------------------------------------------- | --------------------------------------------------------------------------------- | ------------------------------------------------------------------------------ |
| C++        | [ClangFormat](https://clang.llvm.org/docs/ClangFormat.html) | [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)       | [`.clang-format`](https://github.com/iotaaxel/Boerberl/blob/main/.clang-format) |

* From [Google's C++ Style Guide - FileNames](https://google.github.io/styleguide/cppguide.html#File_Names): 
```
C++ files should end in .cc and header files should end in .h. Files that rely on being textually included at specific points should end in .inc (see also the section on self-contained headers).

Do not use filenames that already exist in /usr/include, such as db.h.

In general, make your filenames very specific. For example, use http_server_logs.h rather than logs.h. A very common case is to have a pair of files called, e.g., foo_bar.h and foo_bar.cc, defining a class called FooBar.
```

## Objective
Create a C++ function to process and efficiently store market data. The user should be able to retrieve the latest top-of-book market data snapshot by symbol.

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

## Build and Run:
1. Create a `build` directory: 
  ```mkdir build && cd build```
2. Configure CMake: 
  ```cmake ..```
3. Build:
  ```cmake --build .```
4. Run Clang-Tidy (optional): 
  ```cmake --build . --target clang-tidy```
5. Run Clang-Format (optional): 
  ```clang-format -i src/* test/*```
6. Run Tests:
  ```ctest```

## Sample Data:
* Sample data observed on [Yahoo Finance's Most Bought by Hedge Funds](https://finance.yahoo.com/u/yahoo-finance/watchlists/most-bought-by-hedge-funds/) is used to create a text file representing the input format.

## Future Improvements:
  1. Keep the state while continously processing new user market data input.
  2. Add the ability to filter on multiple symbols simultaneously. 
  3. Add the ability to also filter on bid price, ask price, bid size, and ask size either individually or simultaneously. 
  4. Increase test coverage. 
  5. Add logging. 

## References
* [Quickstart: Building with CMake](https://google.github.io/googletest/quickstart-cmake.html)
* [Google Googletest Repository](https://github.com/google/googletest/tree/main)
  * [Examples](googletest/samples) of using `.h` and `.cc` files with GoogleTest tests built with CMake
* [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)
* [Clang-Format](https://clang.llvm.org/docs/ClangFormat.html)
* [CMake Resources](https://cmake.org/resources)
* [CMake Latest Releases](https://cmake.org/download/)
* [Homebrew for CMake](https://formulae.brew.sh/formula/cmake)
* [Clang-Format Style Options](https://clang.llvm.org/docs/ClangFormatStyleOptions.html)

## License

Licensed under the MIT License, Copyright © 2019-2024
[Axel Iota](https://github.com/iotaaxel/Boerberl).

<div align="center">
  <sub>Assembled with ❤️ in New York.</sub>
</div>
