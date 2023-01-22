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
}
