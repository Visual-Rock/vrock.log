#include "vrock/log/Logger.hpp"

int main()
{
    auto cfg = vrock::log::LoggerConfig("LOGGER")
                    .set_log_level(vrock::log::Info)
                    .add_console_colored();

    auto logger = vrock::log::create_logger(cfg);

    logger->log->info("log entry from logger");

    auto other_logger = vrock::log::get_logger("LOGGER");

    logger->log->info("log entry from other_logger");

    return 0;
}