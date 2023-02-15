#include "vrock/log/Logger.hpp"

#include <unordered_map>
#include <vector>

#include <spdlog/sinks/null_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace vrock::log
{
    Logger::Logger( const std::string& n )
    {
        std::vector<spdlog::sink_ptr> sinks;
        sinks.emplace_back( std::make_shared<spdlog::sinks::stdout_color_sink_mt>( ) );
        log = std::make_shared<spdlog::logger>( n, sinks.begin( ), sinks.end( ) );
        log->set_level( spdlog::level::info );
        log->flush_on( spdlog::level::info );
    }

    Logger::Logger( LoggerConfig cfg )
    {
        auto sinks = cfg.get_config( );
        if ( sinks.empty( ) )
            sinks.push_back( std::make_shared<spdlog::sinks::null_sink_mt>( ) );
        log = std::make_shared<spdlog::logger>( cfg.name, sinks.begin( ), sinks.end( ) );
        log->set_level( (spdlog::level::level_enum)cfg.level );
        log->flush_on( (spdlog::level::level_enum)cfg.level );
    }

    std::unordered_map<std::string, std::shared_ptr<Logger>> logger = { };

    auto create_logger( const LoggerConfig &cfg ) -> std::shared_ptr<Logger>
    {
        logger[ cfg.name ] = std::make_shared<Logger>( cfg );
        return logger[ cfg.name ];
    }

    auto create_logger( const std::string &n ) -> std::shared_ptr<Logger>
    {
        logger[ n ] = std::make_shared<Logger>( n );
        return logger[ n ];
    }

    auto get_logger( const std::string &name ) -> std::shared_ptr<Logger>
    {
        if ( logger.find( name ) != logger.end( ) )
            return logger[ name ];
        return create_logger( name );
    }
} // namespace vrock::log
