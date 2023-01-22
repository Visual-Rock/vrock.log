#include "vrock/log/Logger.hpp"

int main()
{
    auto cfg = vrock::log::LoggerConfig("LOGGER").set_log_level(vrock::log::Info).add_console_colored();

    auto logger = vrock::log::Logger(cfg);

    logger.log->debug("should not be logged");
    logger.log->info("should be logged {}");

    return 0;
}