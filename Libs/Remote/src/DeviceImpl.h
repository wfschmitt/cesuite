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
 * \date   2010-10-01 11:52
 * \brief  Device implementation.
 */

#if !defined(REMOTE_DEVICEIMPL_H)
#define REMOTE_DEVICEIMPL_H

#include "Remote/Device.h"
#include "DetailFwd.h"


namespace Remote
{
    /*!
     * \author  Johan Andersson <skagget77@gmail.com>
     * \date    2010-09-23 20:41
     * \ingroup Registry
     * \brief   IDevice interface.
     */
    class DeviceImpl : public IDevice
    {
    public :
        DeviceImpl( IRAPIDevicePtr device );

        /* Documented in IDevice. */
        std::wstring GetId() const;

        /* Documented in IDevice. */
        std::wstring GetName() const;

        /* Documented in IDevice. */
        std::wstring GetPlatform() const;

        /* Documented in IDevice. */
        std::wstring GetVersion() const;

        /* Documented in IDevice. */
        void CopyFileTo( const std::wstring& source, const std::wstring& target ) const;

        /* Documented in IDevice. */
        void Execute( const std::wstring path, const std::wstring& args ) const;

    private :
        IRAPIDevicePtr m_Device;
    };
}

#endif  /* REMOTE_DEVICEIMPL_H */
