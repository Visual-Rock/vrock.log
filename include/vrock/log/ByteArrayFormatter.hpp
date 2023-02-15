#pragma once

#include <spdlog/fmt/bundled/format.h>

#include <vrock/utils/ByteArray.hpp>

#include <algorithm>
#include <iomanip>
#include <sstream>

template <> struct fmt::formatter<vrock::utils::ByteArray>
{
    constexpr static auto parse( format_parse_context &ctx ) -> decltype( ctx.begin( ) )
    {
        return ctx.end( );
    }

    template <typename FormatContext>
    auto format( const vrock::utils::ByteArray &input, FormatContext &ctx ) -> decltype( ctx.out( ) )
    {
        if ( input.length <= 0 )
            return format_to( ctx.out( ), "" );

        std::stringstream strstm;
        constexpr size_t line_len{ 8 };

        auto rows = ( input.length / line_len ) + 1;
        for ( size_t i = 0; i < rows; i++ )
        {
            if ( i * line_len < input.length )
                strstm << '\n';
            size_t written = 0;
            for ( size_t j = 0; j < std::min( line_len, input.length - line_len * i ); j++, ++written )
                strstm << std::setw( 2 ) << std::setfill( '0' ) << std::hex << (int)input.data[ i * line_len + j ]
                       << ' ';
            auto missing = line_len - written;
            char c;
            if ( written != 0 )
            {
                for ( size_t j = 0; j < missing; j++ )
                    strstm << "   ";
                strstm << "| ";
                for ( size_t j = 0; j < std::min( line_len, input.length - line_len * i ); j++ )
                {
                    c = input.get( i * line_len + j );
                    if ( c == '{' )
                        strstm << "{{";
                    else if ( c == '}' )
                        strstm << "}}";
                    else if ( std::isprint( c ) )
                        strstm << c;
                    else
                        strstm << '.';
                }
            }
        }
        return fmt::format_to( ctx.out( ), strstm.str( ) );
    }
};

template <> struct fmt::formatter<std::shared_ptr<vrock::utils::ByteArray>>
{
    constexpr static auto parse( format_parse_context &ctx ) -> decltype( ctx.begin( ) )
    {
        return ctx.end( );
    }

    template <typename FormatContext>
    auto format( const std::shared_ptr<vrock::utils::ByteArray> &input, FormatContext &ctx ) -> decltype( ctx.out( ) )
    {
        if ( input->length <= 0 )
            return format_to( ctx.out( ), "" );

        std::stringstream strstm;
        constexpr size_t line_len{ 8 };

        auto rows = ( input->length / line_len ) + 1;

        char c;
        for ( size_t i = 0; i < rows; i++ )
        {
            if ( i * line_len < input->length )
                strstm << '\n';
            size_t written = 0;
            for ( size_t j = 0; j < std::min( line_len, input->length - line_len * i ); j++, ++written )
                strstm << std::setw( 2 ) << std::setfill( '0' ) << std::hex << (int)input->get( i * line_len + j )
                       << ' ';
            auto missing = line_len - written;
            if ( written != 0 )
            {
                for ( size_t j = 0; j < missing; j++ )
                    strstm << "   ";
                strstm << "| ";
                for ( size_t j = 0; j < std::min( line_len, input->length - line_len * i ); j++ )
                {
                    c = (char)input->get( i * line_len + j );
                    if ( c == '{' )
                        strstm << "{{";
                    else if ( c == '}' )
                        strstm << "}}";
                    else if ( std::isprint( c ) )
                        strstm << c;
                    else
                        strstm << '.';
                }
            }
        }

        return fmt::format_to( ctx.out( ), strstm.str( ) );
    }
};