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
 * \date   2010-09-23 20:29
 * \brief  
 */

#include "PreCompile.h"
#include "Remote/RemoteException.h"
#include "DeviceImpl.h"
#include "RemoteImpl.h"


using namespace Remote;


RemoteImpl::RemoteImpl()
{
    if(m_Desktop.CoCreateInstance(CLSID_RAPI) != S_OK)
        throw RemoteException("");
}


IDeviceCollection RemoteImpl::ListDevices() const
{
    IRAPIEnumDevicesPtr devices;

    if(m_Desktop->EnumDevices(&devices) == S_OK)
    {
        IDeviceCollection devices;
        IRAPIDevicePtr device;

        // Implementera en loop här.
        if(devices->Next(&device) == S_OK)
            devices.push_back(IDevicePtr(new DeviceImpl(device)));

        return devices;
    }

    throw RemoteException(L"");
}
