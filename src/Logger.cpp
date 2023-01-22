#include "vrock/log/Logger.hpp"

#include <vector>
#include <unordered_map>

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/null_sink.h>

namespace vrock::log {
    Logger::Logger(std::string n)
    {
        std::vector<spdlog::sink_ptr> sinks;
        sinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
        log = std::make_shared<spdlog::logger>(n, sinks.begin(), sinks.end());
        log->set_level( spdlog::level::info);
        log->flush_on(spdlog::level::info);
    }

    Logger::Logger(LoggerConfig cfg)
    {
        auto sinks = cfg.get_config();
        if (sinks.empty())
            sinks.push_back(std::make_shared<spdlog::sinks::null_sink_mt>());
        log = std::make_shared<spdlog::logger>(cfg.name, sinks.begin(), sinks.end());
        log->set_level((spdlog::level::level_enum)cfg.level);
        log->flush_on((spdlog::level::level_enum)cfg.level);
    }
}
