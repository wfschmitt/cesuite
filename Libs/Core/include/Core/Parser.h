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
 * \brief  Parser interface definition.
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
     * \brief   The IParser interface.
     */
    struct IParser
    {
        /*!
         * Destructor.
         */
        virtual ~IParser() {}

        /*!
         * Returns true if the parsed command line contains the specified
         * argument.
         *
         * \param  argument Argument
         * \return True if the command line contains the specified argument.
         */
        virtual bool HasArgument( const std::wstring& argument ) const = 0;

        /*!
         * Returns the argument with the specified index.
         *
         * \param  index Index.
         * \return Argument with the specified index.
         */
        virtual std::wstring GetArgument( std::size_t index ) const = 0;

        /*!
         * Returns the number of arguments.
         *
         * \return The number of arguments.
         */
        virtual std::size_t GetArgumentCount() const = 0;

        /*!
         * Returns the value of the specified argument. The value is the 
         * argument following the specified argument.
         *
         * \param  argument Argument.
         * \return Value of the specified argument.
         */
        virtual std::wstring GetArgumentValue( const std::wstring& option ) const = 0;
    };
}

#endif  // CORE_PARSER_H
