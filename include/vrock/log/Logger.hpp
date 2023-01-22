#pragma once

#include <memory>
#include <string>

#include <spdlog/spdlog.h>

#include "LoggerConfig.hpp"
#include "ByteArrayFormatter.hpp"

namespace vrock::log {
    class Logger {
    public:
        Logger(std::string n);
        Logger(LoggerConfig cfg);

        std::shared_ptr<spdlog::logger> log;        
    };

    /// @brief creates a logger with a given config
    /// @param cfg config for the logger
    /// @return shared pointer containing the logger
    std::shared_ptr<Logger> create_logger(LoggerConfig cfg);

    /// @brief creates a logger with a given name
    /// @param n name of the logger
    /// @return shared pointer containing the logger
    std::shared_ptr<Logger> create_logger(std::string n);

    /// @brief gets the logger with the given name. if the logger is not found it creates one.
    /// @param name name of the logger
    /// @return shared pointer containing the logger
    std::shared_ptr<Logger> get_logger(std::string name);
}
