#include<string>
#include <map>
#include <iostream>

#ifndef ON_MARKET_DATA_H
#define ON_MARKET_DATA_H

#pragma once

class MarketData {
public:
    MarketData() = default; // default constructor
    MarketData(std::string symbol, double bid_price, double ask_price, int bid_size, int ask_size) : symbol(symbol), bid_price(bid_price), ask_price(ask_price), bid_size(bid_size), ask_size(ask_size) {}
   
    // Public member functions for accessing the member variables
    /**
     * Returns the symbol.
     *
     * @return the symbol
     */
    std::string getSymbol() const { return symbol; }
    /**
     * Returns the bid price.
     *
     * @return the bid_price
     */
    double getBidPrice() const { return bid_price; }
    /**
     * Returns the ask price.
     *
     * @return the ask_price
     */
    double getAskPrice() const { return ask_price; }
     /**
     * Returns the bid size.
     *
     * @return the bid_size
     */
    int getBidSize() const { return bid_size; }
    /**
     * Returns the ask size.
     *
     * @return the ask_size
     */
    int getAskSize() const { return ask_size; }

    /**
     * Set the bid price.
     *
     * @param[in] price the price to use for the bid price
     */
    void setBidPrice(double price) { bid_price = price; }
    /**
     * Set the ask price.
     *
     * @param[in] price the price to use for the ask price
     */
    void setAskPrice(double price) { ask_price = price; }
    /**
     * Set the bid size.
     *
     * @param[in] size the size to use for the bid size
     */
    void setBidSize(int size) { bid_size = size; }
    /**
     * Set the ask size.
     *
     * @param[in] size the size to use for the ask size
     */
    void setAskSize(int size) { ask_size = size; }

    /**
     * Retreive the latest top-of-book market data snapshot by symbol.
     *
     * @param data Pointer to char character in user input string.
     */
    void on_market_data(char const *data);

private:
    // Private member variables
    std::string symbol;
    double bid_price;
    double ask_price;
    int bid_size;
    int ask_size;

}; // class MarketData

#endif // ON_MARKET_DATA_H

// Helper functions
namespace helpers {
	// Helper function to print market data
	void printMarketData(const std::map<std::string, MarketData>& marketDataMap, std::ostream& os = std::cout);
	// Helper function to process input data
	void processInputData(const std::string& inputData);

	// Helper function to process each line of input data
	void processLine(const std::string& line, std::map<std::string, MarketData>& marketDataMap);

	// Helper function to read input data from a file
	std::string readInputDataFromFile(const std::string& filePath);
	
}; // namespace helpers
