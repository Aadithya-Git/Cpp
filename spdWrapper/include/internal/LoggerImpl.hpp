#ifndef LoggerImpl_hpp
#define LoggerImpl_hpp

#include <string>
#include <memory>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace ZSEngine {

enum class Severity {
    INFO,
    DEBUG_MSG,
    ERROR
};

class LoggerImpl {
public:
    LoggerImpl(const std::string& logfilepath = "./logs.txt");
    ~LoggerImpl();

    template <typename T = std::string>
    void ConsoleLog(const std::string& message, Severity severity = Severity::INFO, const T& value = "") {
        console_logger_->log(ToSpdLevel(severity), "{} {}", message, value);
    }

    template <typename T = std::string>
    void FileLog(const std::string& message, Severity severity = Severity::INFO, const T& value = "") {
        file_logger_->log(ToSpdLevel(severity), "{} {}", message, value);
        file_logger_->flush();
    }

    template <typename T = std::string>
    void CnFLog(const std::string& message, Severity severity = Severity::INFO, const T& value = "") {
        console_logger_->log(ToSpdLevel(severity), "{} {}", message, value);
        file_logger_->log(ToSpdLevel(severity), "{} {}", message, value);
    }


private:
    std::shared_ptr<spdlog::logger> console_logger_;
    std::shared_ptr<spdlog::logger> file_logger_;

    spdlog::level::level_enum ToSpdLevel(Severity severity);
};

}

#endif // LoggerImpl_hpp
