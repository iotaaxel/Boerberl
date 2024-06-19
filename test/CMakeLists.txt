cmake_minimum_required(VERSION 3.14)

project(on_market_data_test)

# Add the test executable
add_executable(${PROJECT_NAME} on_market_data_test.cc)

# Link the test executable with Google Test and any other necessary libraries
target_link_libraries(${PROJECT_NAME} gtest_main)

include(GoogleTest)
gtest_discover_tests(on_market_data_test)

# Add a test target
# add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})