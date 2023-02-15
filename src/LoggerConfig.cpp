#include "vrock/log/LoggerConfig.hpp"

#include <spdlog/sinks/daily_file_sink.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#include <utility>

namespace vrock::log
{
    LoggerConfig::LoggerConfig( std::string n ) : name( std::move( n ) ), cfg( { } )
    {
    }

    auto LoggerConfig::get_config( ) -> std::vector<spdlog::sink_ptr>
    {
        return cfg;
    }

    auto LoggerConfig::set_log_level( LogLevel lvl ) -> LoggerConfig
    {
        level = lvl;
        return *this;
    }

    auto LoggerConfig::add_console_colored( ) -> LoggerConfig
    {
        cfg.push_back( std::make_shared<spdlog::sinks::stdout_color_sink_mt>( ) );
        return *this;
    }

    auto LoggerConfig::add_colored_error( ) -> LoggerConfig
    {
        cfg.push_back( std::make_shared<spdlog::sinks::stderr_color_sink_mt>( ) );
        return *this;
    }

    auto LoggerConfig::add_ansi_console_colored( ) -> LoggerConfig
    {
        cfg.push_back( std::make_shared<spdlog::sinks::ansicolor_stdout_sink_mt>( ) );
        return *this;
    }

    auto LoggerConfig::add_ansi_colored_error( ) -> LoggerConfig
    {
        cfg.push_back( std::make_shared<spdlog::sinks::ansicolor_stderr_sink_mt>( ) );
        return *this;
    }

    auto LoggerConfig::add_daily_file( const std::string &file, uint16_t amount ) -> LoggerConfig
    {
        cfg.push_back( std::make_shared<spdlog::sinks::daily_file_sink_mt>( file, 23, 59, false, amount ) );
        return *this;
    }

    auto LoggerConfig::add_rotating_file( const std::string &file, size_t file_size, uint16_t amount ) -> LoggerConfig
    {
        cfg.push_back( std::make_shared<spdlog::sinks::rotating_file_sink_mt>( file, file_size, amount ) );
        return *this;
    }
} // namespace vrock::log
