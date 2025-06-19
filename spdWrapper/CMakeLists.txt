cmake_minimum_required(VERSION 3.15)
project(SpdWrapper)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find required packages
find_package(spdlog REQUIRED)
find_package(GTest REQUIRED)

# Create the spd_wrapper library
add_library(spd_wrapper
    src/LoggerImpl.cpp
    src/LoggerIntf.cpp
    include/internal/LoggerImpl.hpp
    include/external/LoggerIntf.hpp
)

target_include_directories(spd_wrapper PUBLIC include)

target_link_libraries(spd_wrapper PRIVATE spdlog::spdlog)

# Create test executable
add_executable(zlogger_test Test/ZLoggerTest.cpp)

target_link_libraries(zlogger_test
    spd_wrapper
    spdlog::spdlog       
    GTest::gtest
    GTest::gtest_main
    pthread
)

