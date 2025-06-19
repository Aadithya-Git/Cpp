#ifndef LoggerIntf_hpp
#define LoggerIntf_hpp

#include <internal/LoggerImpl.hpp>

namespace ZSEngine {

class ZLogger {
public:
    ZLogger(const std::string& logfilepath = "./logs.txt")
        : logger_impl_(std::make_unique<LoggerImpl>(logfilepath)) {}

    void ConsoleLog(const std::string& message, Severity severity = Severity::INFO, const std::string& value = "");
    void ConsoleLog(const std::string& message, Severity severity, int value);
    void ConsoleLog(const std::string& message, Severity severity, double value);
    void ConsoleLog(const std::string& message, Severity severity, bool value);

    void FileLog(const std::string& message, Severity severity = Severity::INFO, const std::string& value = "");
    void FileLog(const std::string& message, Severity severity, int value);
    void FileLog(const std::string& message, Severity severity, double value);
    void FileLog(const std::string& message, Severity severity, bool value);

    void CnFLog(const std::string& message, Severity severity = Severity::INFO, const std::string& value = "");
    void CnFLog(const std::string& message, Severity severity, int value);
    void CnFLog(const std::string& message, Severity severity, double value);
    void CnFLog(const std::string& message, Severity severity, bool value);

    ~ZLogger() = default;

private:
    std::unique_ptr<LoggerImpl> logger_impl_;
};

} 

#endif // LoggerIntf_hpp
