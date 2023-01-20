#include "vrock/log/Logger.hpp"

#include <vector>
#include <unordered_map>

#include <spdlog/sinks/stdout_color_sinks.h>

namespace vrock::log {
    Logger::Logger(std::string n)
    {
        std::vector<spdlog::sink_ptr> sinks;
        sinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
        log = std::make_shared<spdlog::logger>(n, sinks.begin(), sinks.end());
        log->set_level( spdlog::level::info);
        log->flush_on(spdlog::level::info);
    }
}
