#include <iostream>
#include "on_market_data.h"

void on_market_data(char const *data){
	//#TODO: FIX!
	//1. Your code should parse the given data.
	// 2. Implement a data structure that allows the user to retrieve the latest top-of-book market
	// data snapshot by symbol.
	// 3. Aim for efficiency in both space and time complexity.
	// 4. You can use the Standard Template Library (STL) for your solution.

	// 	The function will receive a stream of strings with the following format:
	// ```cpp 
	// <SYMBOL> <BID_PRICE> <ASK_PRICE> <BID_SIZE> <ASK_SIZE>\n
	// ```
	// * Each item in the string is separated by a space.
	// * Each string is delimited by a newline (`\n`).

	// This represents the top-of-book snapshots of the current state of market data for a symbol.

	// The top of the book is where you'll find the highest bid and lowest ask prices. 
	// NOTE (TEST IDEA): should test highest bid on new stream value for symbol
	// NOTE (TEST IDEA): should test lowest ask price on new stream value for symbol

	// NOTE (TEST IDEA): If the ask was lower than the bid then they are considered “crossed.  This would be a “crossed market” and quickly resolved.

	std::cout << "Hello World!\n";
}
