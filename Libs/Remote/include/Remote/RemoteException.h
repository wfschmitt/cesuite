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
 * \date   2010-10-01 11:30
 * \brief  Remote exception definition.
 */

#if !defined(REMOTE_REMOTEEXCEPTION_H)
#define REMOTE_REMOTEEXCEPTION_H

#include "Core/CoreException.h"

namespace Remote
{
    /*!
     * \author  Johan Andersson <skagget77@gmail.com>
     * \date    2010-04-18 01:23
     * \ingroup Registry
     * \brief   The RemoteException class.
     */
    class REMOTE_API RemoteException : public Core::CoreException
    {
    public :
        /*!
         * Constructor.
         *
         * \param details Detailed message.
         */
        RemoteException( const std::wstring& details )
            : Core::CoreException(details) {
        }
    };
}

#endif  // REMOTE_REMOTEEXCEPTION_H
