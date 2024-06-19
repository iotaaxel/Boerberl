#include <iostream>
#include <sstream>
#include <cassert>
#include <gtest/gtest.h>
// #include "../lib/on_market_data.h" // Include the header file that defines the 'MarketData' class
#include <on_market_data.h>

TEST(OnMarketDataTest, HelloTest) {
    EXPECT_EQ(1, 1);
   
}

TEST(OnMarketDataTest, HelloSTest) {
    EXPECT_EQ(1, 1);
   
}
TEST(OnMarketDataTest, ReadUserInputTest) {
    MarketData on_market_data("AAPL", 150, 151, 100, 200);
    EXPECT_EQ(on_market_data.getSymbol(), "AAPL");
    EXPECT_EQ(on_market_data.getBidPrice(), 150);
    EXPECT_EQ(on_market_data.getAskPrice(), 151);
    EXPECT_EQ(on_market_data.getBidSize(), 100);
    EXPECT_EQ(on_market_data.getAskSize(), 200);
}

// #TODO: Troubleshoot ld: symbol(s) not found for architecture arm64
// TEST(OnMarketDataTest, ReadInputDataFromFileTest) {
//     // Read input data from file
//     std::string filePath = "input_most_bought_by_hedge_funds.txt";
//     std::string inputData = helpers::readInputDataFromFile(filePath);

//     // Process input data
//     std::map<std::string, MarketData> marketDataMap;
//     helpers::processInputData(inputData);

//     // Check if market data for specific symbols exists
//     ASSERT_TRUE(marketDataMap.count("X") > 0);
//     ASSERT_TRUE(marketDataMap.count("SNAP") > 0);
//     ASSERT_TRUE(marketDataMap.count("BAC") > 0);
// }

// #TODO: Troubleshoot ld: symbol(s) not found for architecture arm64
// TEST(OnMarketDataTest, ProcessLineTest) {
//     std::string line = "AAPL 150.0 151.0 100 200";
//     std::map<std::string, MarketData> marketDataMap;
//     helpers::processLine(line, marketDataMap);

//     // Check if market data for specific symbols exists
//     ASSERT_TRUE(marketDataMap.count("AAPL") > 0);
// }

// #TODO: Troubleshoot ld: symbol(s) not found for architecture arm64
// TEST(OnMarketDataTest, printMarketDataTest) {
    
//     std::string inputData = "DELL 147.10 143.10 100 200\n"
//                             "DELL 150.09 151.15 150 250\n"
//                             "DELL 143.07 151.20 120 220\n";

//     std::map<std::string, MarketData> marketDataMap;
//     std::ostringstream output_buffer;

//     helpers::processLine(inputData, marketDataMap);

//     helpers::printMarketData(marketDataMap, output_buffer);

//     std::string expected_string = "Symbol: DELL\n"
//                             "Bid Price: 150.09\n"
//                             "Ask Price: 143.10\n"
//                             "Bid Size: 150\n"
//                             "Ask Size: 200\n"
//                             "\n";

//     // Assert
//     assert(output_buffer.str() == expected_string);
// }

// Run all the tests
// int main(int argc, char** argv) {
//     testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }