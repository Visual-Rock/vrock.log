#include "vrock/log/Logger.hpp"

#include "vrock/utils/ByteArray.hpp"

auto main( ) -> int
{
    auto cfg = vrock::log::LoggerConfig( "LOGGER" ).add_console_colored( );
    auto logger = vrock::log::Logger( cfg );

    auto data = std::make_shared<vrock::utils::ByteArray>( "ALJSHDkjslkfjsdlkcyklxjclskjhfkfg" );
    auto data1 = vrock::utils::ByteArray( "nsjsuhoijsdfioiosdaio" );
    auto bin =
        vrock::utils::ByteArray::from_hex_string( "28BF4E5E4E758A4164004E56FFFA01082E2E00B6D0683E802F0CA9FE6453697A" );

    logger.log->info( "data: {}", data );
    logger.log->info( "data1: {}", data1 );
    logger.log->info( "bin: {}", bin );

    return 0;
}