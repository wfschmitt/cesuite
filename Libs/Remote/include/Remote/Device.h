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
 * \date   2010-10-01 11:44
 * \brief  Device interface definition.
 */

#if !defined(REMOTE_DEVICE_H)
#define REMOTE_DEVICE_H

#include "RemoteFwd.h"

#include <string>

namespace Remote
{
    /*!
     * \author  Johan Andersson <skagget77@gmail.com>
     * \date    2010-04-11 17:57
     * \ingroup Registry
     * \brief   IDevice interface.
     */
    struct IDevice
    {
        /*!
         * Destructor.
         */
        virtual ~IDevice() {}

        /*!
         *
         */
        virtual std::wstring GetId() const = 0;

        /*!
         *
         */
        virtual std::wstring GetName() const = 0;

        /*!
         *
         */
        virtual std::wstring GetPlatform() const = 0;

        /*!
         *
         */
        virtual std::wstring GetVersion() const = 0;

        /*!
         *
         */
        virtual void CopyFileTo( const std::wstring& source, const std::wstring& target ) const = 0;

        /*!
         *
         */
        virtual void Execute( const std::wstring path, const std::wstring& args ) const = 0;
    };
}

#endif  /* REMOTE_DEVICE_H */
