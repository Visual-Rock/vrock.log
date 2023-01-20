#pragma once

#include <memory>
#include <string>

#include <spdlog/spdlog.h>

namespace vrock::log {
    class Logger {
    public:
        Logger(std::string n);
        std::shared_ptr<spdlog::logger> log;        
    };
}
