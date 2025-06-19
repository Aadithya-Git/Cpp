#include <gtest/gtest.h>
#include <external/LoggerIntf.hpp>
#include <filesystem>
#include <fstream>
#include <iostream>

using namespace ZSEngine;

static std::string test_log_path = "./test_log.txt";

class ZLoggerTest : public ::testing::Test {
protected:
    void SetUp() override {
        std::ofstream clearFile(test_log_path, std::ios::trunc);
        clearFile.close();
    }
};

TEST_F(ZLoggerTest, LogFileCreation) {
    ZLogger logger(test_log_path);
    EXPECT_TRUE(std::filesystem::exists(test_log_path));
}

TEST_F(ZLoggerTest, LogContentWritten) {
    ZLogger logger(test_log_path);
    logger.FileLog("Test message");


    std::ifstream file(test_log_path);
    
    if (!file.is_open()) {
        std::cerr << "Failed to open log file: " << test_log_path << std::endl;
        FAIL() << "Log file could not be opened for reading.";
    }

    std::string line;
    bool found = false;

    while (std::getline(file, line)) {
        if (line.find("Test message") != std::string::npos) {
            found = true;
            break;
        }
    }

    EXPECT_TRUE(found);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    int result = RUN_ALL_TESTS();
    return result;
}
