#include "vrock/log/Logger.hpp"

auto main( ) -> int
{
    auto logger = vrock::log::Logger( "LOGGER" );

    logger.log->info( "Hello, World!" );

    return 0;
}