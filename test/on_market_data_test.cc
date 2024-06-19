#include <iostream>
#include <gtest/gtest.h>
#include "src/on_market_data.cc"

// Input format is "SYMBOL BID_PRICE ASK_PRICE BID_SIZE ASK_SIZE\n"
// First line is "<SYMBOL> 0.0 0.0 0 0\n" or "<SYMBOL> <FILE> 0.0 0 0\n"
// std::string inputData = symbol + " 0.0 0.0 0 0\n" + "AAPL 150.0 150.5 100 200\nGOOGL 2500.0 2501.0 50 75\n";
// NOTE (TEST IDEA): should test highest bid on new stream value for symbol
TEST(OnMarketDataTest, OnMarketDataTest) {
    MarketData on_market_data("000001", 10.0, 100, 0.0, 0);
    ASSERT_EQ(on_market_data.Symbol(), "000001");
    ASSERT_EQ(on_market_data.getBidPrice(), 10.0);
    ASSERT_EQ(on_market_data.getAskPrice(), 10.0);
    ASSERT_EQ(on_market_data.getBidSize(), 10.0);
    ASSERT_EQ(on_market_data.getAskSize(), 10.0);
}

// NOTE (TEST IDEA): should test lowest ask price on new stream value for symbol
TEST(OnMarketDataTest, CrossedMarketTest) {
    MarketData on_market_data("000001", 10.0, 100, 0.0, 0);
    ASSERT_EQ(on_market_data.Symbol(), "000001");
    ASSERT_EQ(on_market_data.GetPrice(), 10.0);
    ASSERT_EQ(on_market_data.GetVolume(), 100);
}

// NOTE (TEST IDEA): If the ask was lower than the bid then they are considered “crossed.  This would be a “crossed market” and quickly resolved.
TEST(OnMarketDataTest, CrossedMarketTest) {
    MarketData on_market_data("000001", 10.0, 100, 0.0, 0);
    ASSERT_EQ(on_market_data.Symbol(), "000001");
    ASSERT_EQ(on_market_data.GetPrice(), 10.0);
    ASSERT_EQ(on_market_data.GetVolume(), 100);
}