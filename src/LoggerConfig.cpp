#include "vrock/log/LoggerConfig.hpp"

#include <spdlog/sinks/stdout_color_sinks.h>

namespace vrock::log {
    LoggerConfig::LoggerConfig(std::string n) : name(n), cfg({ }) { } 

    std::vector<spdlog::sink_ptr> LoggerConfig::get_config() { return cfg; }

    LoggerConfig LoggerConfig::set_log_level(LogLevel lvl)
    {
        level = lvl;
        return *this;
    }

    LoggerConfig LoggerConfig::add_console_colored()
    {
        cfg.push_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
        return *this;
    }
}
