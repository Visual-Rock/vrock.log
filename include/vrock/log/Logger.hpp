#pragma once

#include <memory>
#include <string>

#include <spdlog/spdlog.h>

#include "ByteArrayFormatter.hpp"
#include "LoggerConfig.hpp"

namespace vrock::log
{
    class Logger
    {
    public:
        explicit Logger( const std::string& n );
        explicit Logger( LoggerConfig cfg );

        std::shared_ptr<spdlog::logger> log;
    };

    /// @brief creates a logger with a given config
    /// @param cfg config for the logger
    /// @return shared pointer containing the logger
    auto create_logger( const LoggerConfig &cfg ) -> std::shared_ptr<Logger>;

    /// @brief creates a logger with a given name
    /// @param n name of the logger
    /// @return shared pointer containing the logger
    auto create_logger( const std::string &n ) -> std::shared_ptr<Logger>;

    /// @brief gets the logger with the given name. if the logger is not found it creates one.
    /// @param name name of the logger
    /// @return shared pointer containing the logger
    auto get_logger( const std::string &name ) -> std::shared_ptr<Logger>;
} // namespace vrock::log
