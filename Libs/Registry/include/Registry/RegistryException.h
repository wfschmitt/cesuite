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
 * \brief  Parser exception definition.
 */

#if !defined(REGISTRY_REGISTRYEXCEPTION_H)
#define REGISTRY_REGISTRYEXCEPTION_H

#include <stdexcept>

namespace Registry
{
    /*!
     * \author  Johan Andersson <skagget77@gmail.com>
     * \date    2010-04-18 01:23
     * \ingroup Registry
     * \brief   The RegistryException class.
     */
    class REGISTRY_API RegistryException : public std::runtime_error {
    public :
        /*!
         * Creates a new instance of the RegistryException class.
         *
         * \param msg Detailed message.
         */
        RegistryException( const std::string& msg )
            : std::runtime_error(msg) {
        }
    };
}

#endif  // REGISTRY_REGISTRYEXCEPTION_H
