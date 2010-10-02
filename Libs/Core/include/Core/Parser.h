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
 * \date   2010-04-18 01:23
 * \brief  Parser interface.
 */

#if !defined(CORE_PARSER_H)
#define CORE_PARSER_H

#include "CoreFwd.h"

#include <cstddef>
#include <string>

namespace Core
{
    /*!
     * \author  Johan Andersson <skagget77@gmail.com>
     * \date    2010-04-18 01:23
     * \ingroup Core
     * \brief   IParser interface.
     */
    struct IParser
    {
        /*!
         * Destructor.
         */
        virtual ~IParser() {}

        /*!
         * Returns true if the parsed command line contains the specified
         * option.
         *
         * \param  option Option.
         * \return True if the command line contains the specified option,
         *         false otherwise.
         */
        virtual bool HasOption( const std::wstring& option ) const = 0;

        /*!
         * Returns the option at the specified index.
         *
         * \param  index Index.
         * \return Option at the specified index.
         * \throws ParserException When index is out of range.
         */
        virtual std::wstring GetOption( std::size_t index ) const = 0;

        /*!
         * Returns the number of options.
         *
         * \return Number of options.
         */
        virtual std::size_t GetOptionCount() const = 0;

        /*!
         * Returns the value of the specified option.
         *
         * \param  option Option.
         * \return Value of the specified option.
         * \throws ParserException When the specified option can't be found or
         *         has no value.
         */
        virtual std::wstring GetValue( const std::wstring& option ) const = 0;

        /*!
         * Returns the value of the specified option or \p defValue if the
         * parsed command line is missing the option.
         *
         * \param  option Option.
         * \param  defval Default value.
         * \return Value of the specified option.
         * \throws ParserException When the specified option has no value.
         */
        virtual std::wstring GetValue(
            const std::wstring& option, const std::wstring& defValue ) const = 0;
    };
}

#endif  /* CORE_PARSER_H */
