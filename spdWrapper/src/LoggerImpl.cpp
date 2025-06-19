#include <internal/LoggerImpl.hpp>
#include <external/LoggerIntf.hpp>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <iostream>

namespace ZSEngine {

LoggerImpl::LoggerImpl(const std::string& logfilepath) {
    console_logger_ = spdlog::stdout_color_mt("console");
    file_logger_ = spdlog::basic_logger_mt("file_logger", logfilepath);
    
    console_logger_->set_level(spdlog::level::debug);
    file_logger_->set_level(spdlog::level::debug);
    
    if(file_logger_){
        std:: cout << "Log file { " << logfilepath << " } generated successfully" << std::endl;
    }else{
        std::cout << "Log file is not generated due to some error" << std::endl;
    }
    
    if(console_logger_){
        std:: cout << "Console is ready to log" << std::endl;
    }else{
        std::cout << "Console log is not reaady to log due to some error" << std::endl;
    }
    
    console_logger_->set_pattern("[%Y-%m-%d %H:%M:%S] [console] [%l] %v");
    file_logger_->set_pattern("[%Y-%m-%d %H:%M:%S] [file] [%l] %v");

}

LoggerImpl::~LoggerImpl() {
    spdlog::shutdown();
}

spdlog::level::level_enum LoggerImpl::ToSpdLevel(Severity severity) {
    switch (severity) {
        case Severity::INFO: return spdlog::level::info;
        case Severity::DEBUG_MSG: return spdlog::level::debug;
        case Severity::ERROR: return spdlog::level::err;
        default: return spdlog::level::info;
    }
}



}
