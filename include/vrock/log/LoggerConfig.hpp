#pragma once

#include <string>
#include <vector>

#include <spdlog/sinks/sink.h>

namespace vrock::log {

    /// @brief Loglevel (equivalent to spdlog level's)
    enum LogLevel {
        Trace = spdlog::level::trace,
        Debug = spdlog::level::debug,
        Info = spdlog::level::info,
        Warning = spdlog::level::warn,
        Error = spdlog::level::err,
        Critical = spdlog::level::critical,
        Off = spdlog::level::off
    };

    class LoggerConfig {
    public:
        /// @brief creates a new instance of LoggerConfig that can be used to initialize a new Logger
        /// @param name name of the Logger
        LoggerConfig(std::string name);

        /// @brief gets all spdlog sinks
        /// @return vector containing all sinks
        std::vector<spdlog::sink_ptr> get_config();

        LoggerConfig set_log_level(LogLevel lvl);

        /// @brief add a colored console sink
        /// @return return this LoggerConfig
        LoggerConfig add_console_colored();
        
        /// @brief add a daily file sink
        /// @return return this LoggerConfig
        LoggerConfig add_daily_file(std::string file, uint16_t amount = 5);
    public:
        /// @brief name of the Logger
        std::string name;

        LogLevel level = LogLevel::Trace;
    private:
        std::vector<spdlog::sink_ptr> cfg;
    };
}