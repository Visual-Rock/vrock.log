#include "vrock/log/Logger.hpp"

int main()
{
    auto cfg = vrock::log::LoggerConfig("LOGGER")
                    .set_log_level(vrock::log::Info)
                    .add_console_colored()
                    .add_daily_file("log.txt")
                    .add_colored_error()
                    .add_ansi_console_colored()
                    .add_ansi_colored_error();

    auto logger = vrock::log::Logger(cfg);

    logger.log->debug("should not be logged");
    logger.log->info("should be logged {}"); // logged 4 times

    return 0;
}