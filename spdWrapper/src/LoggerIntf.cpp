//
//  LoggerIntf.cpp
//  Logger
//
//  Created by Aadithya K S on 17/06/25.
//

#include <external/LoggerIntf.hpp>

namespace ZSEngine {
void ZLogger::ConsoleLog(const std::string& message, Severity severity, const std::string& value) {
    logger_impl_->ConsoleLog(message, severity, value);
}
void ZLogger::ConsoleLog(const std::string& message, Severity severity, int value) {
    logger_impl_->ConsoleLog(message, severity, value);
}
void ZLogger::ConsoleLog(const std::string& message, Severity severity, double value) {
    logger_impl_->ConsoleLog(message, severity, value);
}
void ZLogger::ConsoleLog(const std::string& message, Severity severity, bool value) {
    logger_impl_->ConsoleLog(message, severity, value);
}

void ZLogger::FileLog(const std::string& message, Severity severity, const std::string& value) {
    logger_impl_->FileLog(message, severity, value);
}
void ZLogger::FileLog(const std::string& message, Severity severity, int value) {
    logger_impl_->FileLog(message, severity, value);
}
void ZLogger::FileLog(const std::string& message, Severity severity, double value) {
    logger_impl_->FileLog(message, severity, value);
}
void ZLogger::FileLog(const std::string& message, Severity severity, bool value) {
    logger_impl_->FileLog(message, severity, value);
}

void ZLogger::CnFLog(const std::string& message, Severity severity, const std::string& value) {
    logger_impl_->CnFLog(message, severity, value);
}
void ZLogger::CnFLog(const std::string& message, Severity severity, int value) {
    logger_impl_->CnFLog(message, severity, value);
}
void ZLogger::CnFLog(const std::string& message, Severity severity, double value) {
    logger_impl_->CnFLog(message, severity, value);
}
void ZLogger::CnFLog(const std::string& message, Severity severity, bool value) {
    logger_impl_->CnFLog(message, severity, value);
}
}
