#include "vrock/log/Logger.hpp"

int main()
{
    auto logger = vrock::log::Logger("LOGGER");

    logger.log->info("Hello, World!");

    return 0;
}