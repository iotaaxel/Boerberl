#include "on_market_data.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <map>
#include <algorithm>

// Helper functions
namespace helpers {
	// Helper function to print market data
	void printMarketData(const std::map<std::string, MarketData>& marketDataMap, std::ostream& os) {
		for (const auto& pair : marketDataMap) {
			const MarketData& data = pair.second;
			os << "Symbol: " << data.getSymbol() << "\n";
			os << "Bid Price: " << data.getBidPrice() << "\n";
			os << "Ask Price: " << data.getAskPrice() << "\n";
			os << "Bid Size: " << data.getBidSize() << "\n";
			os << "Ask Size: " << data.getAskSize() << "\n";
			os << "\n";
		}
	}

	// Helper function to process input data
	void processInputData(const std::string& inputData) {
		MarketData marketData;
		marketData.on_market_data(inputData.c_str());
	}

	// Helper function to process each line of input data
	void processLine(const std::string& line, std::map<std::string, MarketData>& marketDataMap) {
		std::istringstream lineStream(line);
		std::string item;
		std::vector<std::string> items;
		while (lineStream >> item) {
			items.push_back(item);
		}

		if (items.size() != 5) {
			std::cerr << "Invalid data format\n";
			return;
		}

		// Process each line of input data with the following format:
		// <SYMBOL> <BID_PRICE> <ASK_PRICE> <BID_SIZE> <ASK_SIZE>
		std::string symbol = items[0];
		std::transform(symbol.begin(), symbol.end(), symbol.begin(), ::toupper); // Convert symbol to uppercase

		const double bid_price = std::stod(items[1]);
		const double ask_price = std::stod(items[2]);
		const int bid_size = std::stoi(items[3]);
		const int ask_size = std::stoi(items[4]);
		// Update the market data map with the latest data
		// Check if the symbol already exists in the market data map
		if (marketDataMap.count(symbol) > 0) {
			// Symbol already exists, update the market data
			MarketData& existingData = marketDataMap[symbol];
			// Update if highest bid and lowest ask prices found for symbol (use corresponding bid/ask sizes as well)
			if (bid_price > existingData.getBidPrice()) {
				existingData.setBidPrice(bid_price);
				existingData.setBidSize(bid_size);
			}

			if (ask_price < existingData.getAskPrice()) {
				existingData.setAskPrice(ask_price);
				existingData.setAskSize(ask_size);
			}
		} else {
			// Symbol does not exist, create a new market data entry
			marketDataMap[symbol] = MarketData(symbol, bid_price, ask_price, bid_size, ask_size);
		}
	}

	// Helper function to read input data from a file
	std::string helpers::readInputDataFromFile(const std::string& filePath) {
		std::ifstream inputFile(filePath);
		if (!inputFile) {
			std::cerr << "Failed to open file\n";
			return "";
		}
		std::stringstream buffer;
		buffer << inputFile.rdbuf();
		return buffer.str();
	}
	
}


void MarketData::on_market_data(char const *data){
	// Create a map to store the market data
	std::map<std::string, MarketData> marketDataMap;

	std::istringstream iss(data); // Declare and initialize the 'iss' variable
	std::string line;

	// Process each line of input data and update the market data map
	while (std::getline(iss, line, '\n')) {
		helpers::processLine(line, marketDataMap);
	}

	// Print the market data
	helpers::printMarketData(marketDataMap);
}

int main(int argc, char** argv) {

	int choice;
	std::cout << "Choose an option:\n";
	std::cout << "1. Input file path\n";
	std::cout << "2. Input string with this format for each line: SYMBOL BID_PRICE ASK_PRICE BID_SIZE ASK_SIZE\\n \n";
	std::cout << "Enter your choice: ";
	std::cin >> choice;

	switch (choice) {
		case 1: {
			// Read input data from a file
			std::string filePath;
			std::cout << "Enter file path: ";
			std::cin >> filePath;

			std::string inputData = helpers::readInputDataFromFile(filePath);
			helpers::processInputData(inputData);

			break;
		}
		case 2: {
			// Read input data from the user
			std::string input;
			std::string line;

			std::cout << "Enter the input string (end with an empty line):\n";

			std::cin.ignore(); // Ignore the newline character in the input buffer
			
			// Read input line by line and keep newlines
			while (std::getline(std::cin, line)) {
				if (line.empty()) { // End input when an empty line is entered
					break;
				}
				input += line + "\n";
			}			

			helpers::processInputData(input.c_str());

			break;
		}
		default:
			// Invalid user input
			std::cerr << "Invalid choice\n";
			return 1;
	}

	return 0;
}