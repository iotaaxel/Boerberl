#ifndef ON_MARKET_DATA_H
#define ON_MARKET_DATA_H

#pragma once

class MarketData {
public:
    // Add the member variables and member functions of the MarketData class here
    std::string symbol;
    double bid_price;
    double ask_price;
    int bid_size;
    int ask_size;

    MarketData() = default; // default constructor

    MarketData(std::string symbol, double bid_price, double ask_price, int bid_size, int ask_size)
        : symbol(symbol), bid_price(bid_price), ask_price(ask_price), bid_size(bid_size), ask_size(ask_size) {}

    std::string Symbol() const { return symbol; }
    double getBidPrice() const { return bid_price; }
    double getAskPrice() const { return ask_price; }
    int getBidSize() const { return bid_size; }
    int getAskSize() const { return ask_size; }

    void setBidPrice(double price) { bid_price = price; }
    void setAskPrice(double price) { ask_price = price; }
    void setBidSize(int size) { bid_size = size; }
    void setAskSize(int size) { ask_size = size; }

    void on_market_data(char const *data);
    
}; // class MarketData

#endif