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

#if !defined(CORE_PARSERIMPL_H)
#define CORE_PARSERIMPL_H

#include "Core/Parser.h"

#include <string>
#include <vector>

namespace Core
{
    /*!
     * \author  Johan Andersson <skagget77@gmail.com>
     * \date    2010-04-11 17:57
     * \ingroup Core
     * \brief   ParserImpl class.
     */
    class CORE_API ParserImpl : public IParser
    {
    public :
        /*!
         * Constructor
         *
         * \param  cmdLine Command line to parse.
         * \param  caseInsensitive Tells whether parser operations should be
         *         case insensitive or not.
         * \throws ParserException If an error occurs while parsing the command
         *         line.
         */
        ParserImpl( const std::wstring& cmdLine, bool caseInsensitive );

        /* Documented in IParser. */
        bool HasOption( const std::wstring& option ) const;

        /* Documented in IParser. */
        std::wstring GetOption( std::size_t index ) const;

        /* Documented in IParser. */
        std::size_t GetOptionCount() const;

        /* Documented in IParser. */
        std::wstring GetValue( const std::wstring& option ) const;

        /* Documented in IParser. */
        std::wstring GetValue( 
            const std::wstring& option, const std::wstring& defValue ) const;

    private :
        typedef std::vector<std::wstring> wstringlist;

        /*!
         * Parses the next quoted command line option starting at the specified
         * index.
         *
         * \param  cmdLine Command line.
         * \param  index Command line character index.
         * \return Option.
         */
        static std::wstring ParserImpl::ParseQuotedOption( 
            const std::wstring& cmdLine, std::wstring::size_type& index );

        /*!
         * Parses the next space separated command line option starting at the
         * specified index.
         *
         * \param  cmdLine Command line.
         * \param  index Command line character index.
         * \return Option.
         */
        static std::wstring ParserImpl::ParseSpacedOption( 
            const std::wstring& cmdLine, std::wstring::size_type& index );

        /*!
         * Parses the specified command line.
         *
         * \param  cmdLine Command line.
         * \return Option collection.
         */
        static wstringlist ParserImpl::ParseComandLine( const std::wstring& cmdLine );

        wstringlist m_Options;
        bool m_CaseInsensitive;
    };
}

#endif  /* CORE_PARSERIMPL_H */
