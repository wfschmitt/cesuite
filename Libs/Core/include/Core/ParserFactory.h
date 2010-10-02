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
 * \brief  Parser factory function.
 */

#if !defined(CORE_PARSERFACTORY_H)
#define CORE_PARSERFACTORY_H

#include "CoreFwd.h"

#include <string>

namespace Core
{
    /*!
     * Returns a new IParser implementation. Parser operations will be case
     * sensitive.
     *
     * \ingroup Core
     * \param   cmdLine Command line to parse.
     * \return  An IParser implementation.
     * \throws  ParserException If an error occurs while parsing the command
     *          line.
     */
    CORE_API IParserPtr CreateParser( const std::wstring& cmdLine );

    /*!
     * Returns a new IParser implementation.
     *
     * \ingroup Core
     * \param   cmdLine Command line to parse.
     * \param   caseInsensitive Tells whether parser operations should be case
     *          insensitive or not.
     * \return  An IParser implementation.
     * \throws  ParserException If an error occurs while parsing the command
     *          line.
     */
    CORE_API IParserPtr CreateParser( const std::wstring& cmdLine, bool caseInsensitive );
}

#endif  // CORE_PARSERFACTORY_H
