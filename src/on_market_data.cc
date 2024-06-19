#include "on_market_data.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <map>
#include <algorithm>

// Helper function for case-insensitive string matching
inline bool isCaseInsensitiveMatch(const std::string& str1, const std::string& str2) {
	return std::equal(str1.begin(), str1.end(), str2.begin(), str2.end(),
		[](char c1, char c2) {
			return std::toupper(c1) == std::toupper(c2);
		});
}

// Helper function to process input data
void processInputData(const std::string& symbol, const std::string& inputData) {
	std::string modifiedInputData = inputData;
	modifiedInputData.insert(0, symbol + " 0.0 0.0 0 0\n");

	MarketData marketData;
	marketData.on_market_data(modifiedInputData.c_str());
}

// Helper function to read input data from a file
std::string readInputDataFromFile(const std::string& filePath) {
	std::ifstream inputFile(filePath);
	if (!inputFile) {
		std::cerr << "Failed to open file\n";
		return "";
	}
	std::stringstream buffer;
	buffer << inputFile.rdbuf();
	return buffer.str();
}

// Helper function to print market data
void printMarketData(const std::map<std::string, MarketData>& marketDataMap) {
	for (const auto& pair : marketDataMap) {
		const MarketData& data = pair.second;
		std::cout << "Symbol: " << data.Symbol() << "\n";
		std::cout << "Bid Price: " << data.getBidPrice() << "\n";
		std::cout << "Ask Price: " << data.getAskPrice() << "\n";
		std::cout << "Bid Size: " << data.getBidSize() << "\n";
		std::cout << "Ask Size: " << data.getAskSize() << "\n";
		std::cout << "\n";
	}
}


void MarketData::on_market_data(char const *data){
	
	// Process the five items with the following format
	// <SYMBOL> <BID_PRICE> <ASK_PRICE> <BID_SIZE> <ASK_SIZE>
	// The first line is "<SYMBOL> 0.0 0.0 0 0"

	// Now you can retrieve the latest top-of-book market data snapshot by symbol
	// Example:
	// MarketData latestData = marketDataMap["AAPL"];
	// double latestBidPrice = latestData.getBidPrice();
	// double latestAskPrice = latestData.getAskPrice();
	// int latestBidSize = latestData.getBidSize();
	// int latestAskSize = latestData.getAskSize();


	std::string filter_symbol;
	std::istringstream iss(data); // Declare and initialize the 'iss' variable
	std::string line;

	// Create a map to store the market data
	std::map<std::string, MarketData> marketDataMap;
	
	// Create a vector to store the items
	std::vector<std::string> items;

	// Extract the symbol from the first line
	std::getline(iss, line, '\n');
	std::istringstream lineStream(line);
	lineStream >> filter_symbol;
	
	// Process the remaining lines
	while (std::getline(iss, line, '\n')) {
		std::istringstream lineStream(line);
		std::string item;

		while (lineStream >> item) {
			items.push_back(item);
		}
	
		// Process the five items with the following format
		// <SYMBOL> <BID_PRICE> <ASK_PRICE> <BID_SIZE> <ASK_SIZE>
		if (items.size() != 5) {
			std::cerr << "Invalid data format\n";
			return;
		}

		std::string symbol = items[0];
		std::transform(symbol.begin(), symbol.end(), symbol.begin(), ::toupper);

		double bid_price = std::stod(items[1]);
		double ask_price = std::stod(items[2]);
		int bid_size = std::stoi(items[3]);
		int ask_size = std::stoi(items[4]);

		// Check if the symbol matches the filter symbol
		if (isCaseInsensitiveMatch(symbol, filter_symbol)) {
			// Check if the symbol already exists in the market data map
			if (marketDataMap.count(symbol) > 0) {
				// Symbol already exists, update the market data
				MarketData& existingData = marketDataMap[symbol];
				existingData.setBidPrice(bid_price);
				existingData.setAskPrice(ask_price);
				existingData.setBidSize(bid_size);
				existingData.setAskSize(ask_size);
			} else {
				// Symbol does not exist, create a new market data entry
				marketDataMap[filter_symbol] = MarketData(filter_symbol, bid_price, ask_price, bid_size, ask_size);
			}

		} else {
			// User not filtering on this symbol, skip to next iteration
			continue;
		}
	
		// Clear the items vector for the next iteration
		items.clear();
	}

	printMarketData(marketDataMap);
}

int main(int argc, char** argv) {
	// Ask user for symbol to filter on
	std::string symbol;
	std::cout << "Enter symbol: ";
	std::cin >> symbol;

	int choice;
	std::cout << "Choose an option:\n";
	std::cout << "1. Input file path\n";
	std::cout << "2. Input string with this format for each line: SYMBOL BID_PRICE ASK_PRICE BID_SIZE ASK_SIZE\\n";
	std::cout << "Enter your choice: ";
	std::cin >> choice;

	switch (choice) {
		case 1: {
			// Read input data from a file
			std::string filePath;
			std::cout << "Enter file path: ";
			std::cin >> filePath;

			std::string inputData = readInputDataFromFile(filePath);
			processInputData(symbol, inputData);

			break;
		}
		case 2: {
			// Read input data from the user
			std::string inputString;
			std::cout << "Enter input string: ";
			std::cin.ignore(); // Ignore the newline character left in the input stream
			std::getline(std::cin, inputString);

			processInputData(symbol, inputString);

			break;
		}
		default:
			// Invalid user input
			std::cerr << "Invalid choice\n";
			return 1;
	}

	return 0;
}