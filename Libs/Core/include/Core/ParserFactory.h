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
 * \brief  Parser factory.
 */

#if !defined(CORE_PARSERFACTORY_H)
#define CORE_PARSERFACTORY_H

#include "CoreFwd.h"

#include <string>

namespace Core
{
    /*!
     * Creates a new instance of an IParser implementation. Parser operations
     * will be case sensitive.
     *
     * \ingroup Core
     * \param   cmdline Command line to parse.
     * \return  An IParser implementation.
     */
    CORE_API IParserPtr CreateParser( const std::wstring& cmdline );

    /*!
     * Creates a new instance of an IParser implementation.
     *
     * \ingroup Core
     * \param   cmdline Command line to parse.
     * \param   caseinsensitive Tells whether parser operations should be case
     *          insensitive or not.
     * \return  An IParser implementation.
     */
    CORE_API IParserPtr CreateParser( const std::wstring& cmdline, bool caseinsensitive );
}

#endif  // CORE_PARSERFACTORY_H
