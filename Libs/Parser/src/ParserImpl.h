/*
 * This file is part of CeSuite.
 *
 * CeSuite is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CeSuite is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CeSuite.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Copyright 2010 Johan Andersson.
 */

/*!
 * \file
 * \author Johan Andersson <skagget77@gmail.com>
 * \date   2010-04-13 22:38
 * \brief  Parser implementation.
 */

#if !defined(PARSER_PARSERIMPL_H)
#define PARSER_PARSERIMPL_H

#include "Parser/Parser.h"

#include <string>
#include <vector>

namespace Parser
{
    /*!
     * \author  Johan Andersson <skagget77@gmail.com>
     * \date    2010-04-11 17:57
     * \ingroup Parser
     * \brief   The ParserImpl class.
     */
    class PARSER_API ParserImpl : public IParser
    {
    public :
        /*!
         * Creates a new instance of the ParserImpl class.
         *
         * \param cmdline Command line to parse.
         */
        ParserImpl( const std::wstring& cmdline );

        /*
         * Inherited from IParser.
         */
        bool HasArgument( const std::wstring& argument ) const;
        std::wstring GetArgument( std::size_t index ) const;
        std::size_t GetArgumentCount() const;
        std::wstring GetArgumentValue( const std::wstring& argument ) const;

    private :
        typedef std::vector<std::wstring> wstringlist;

        /*!
         * Parses the next quoted command line argument starting at the 
         * specified index.
         *
         * \param  cmdline Command line.
         * \param  index Command line character index.
         * \return Argument.
         */
        static std::wstring ParserImpl::ParseQuotedArgument( 
            const std::wstring& cmdline, std::wstring::size_type& index );

        /*!
         * Parses the next space separated command line argument starting at
         * the specified index.
         *
         * \param  cmdline Command line.
         * \param  index Command line character index.
         * \return Argument.
         */
        static std::wstring ParserImpl::ParseSpacedArgument( 
            const std::wstring& cmdline, std::wstring::size_type& index );

        /*!
         * Parses the specified command line.
         *
         * \param  cmdline Command line.
         * \return Argument collection.
         */
        static wstringlist ParserImpl::ParseComandLine( const std::wstring& cmdline );

        wstringlist m_Arguments;
    };
}

#endif  // PARSER_PARSERIMPL_H
