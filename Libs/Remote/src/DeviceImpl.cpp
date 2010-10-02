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
 * \date   2010-10-01 11:54
 * \brief  Device implementation.
 */

#include "PreCompile.h"
#include "Core/BasicTypes.h"
#include "Remote/RemoteException.h"
#include "DeviceImpl.h"
#include "RaiiHandle.h"

#include <iostream>
#include <iomanip>
#include <sstream>


using namespace Remote;


namespace
{
    typedef std::vector<uint8> FileBuffer;

    void Win32ReadSourceFile( const std::wstring& sourcePath, FileBuffer& buffer )
    {
        RaiiHandle file(CreateFile(sourcePath.c_str(), 
            GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, 0, 0));

        if(file != INVALID_HANDLE_VALUE)
        {
            LARGE_INTEGER size;

            if(GetFileSizeEx(file, &size))
            {
                DWORD count = 0;

                buffer.resize(size.QuadPart);
                
                if(ReadFile(file, &buffer[0], buffer.size(), &count, 0))
                    return;
            }
        }

        throw RemoteException("Failed to read source file");
    }


    void WinCeWriteTargetFile( 
        IRAPISessionPtr session, const std::wstring& targetPath, const FileBuffer& buffer )
    {
        RaiiCeHandle file(session, session->CeCreateFile(
            targetPath.c_str(), GENERIC_READ|GENERIC_WRITE, 0, 0, CREATE_ALWAYS, 
            FILE_ATTRIBUTE_HIDDEN|FILE_ATTRIBUTE_READONLY|FILE_FLAG_WRITE_THROUGH, 0));

        if(file != INVALID_HANDLE_VALUE)
        {
            DWORD count = 0;

            if(session->CeWriteFile(file, &buffer.front(), buffer.size(), &count, 0))
            {
                if(count == buffer.size())
                    return;
            }
        }
        
        throw RemoteException("");
    }
}


class RAIIIRAPISession
{
public :
    RAIIIRAPISession( IRAPISessionPtr session )
        : m_Session(session) {
        m_Session->CeRapiInit();
    }

    ~RAIIIRAPISession() {
        m_Session->CeRapiUninit();
    }

    IRAPISessionPtr operator->() {
        return m_Session;
    }

    IRAPISessionPtr operator->() const {
        return m_Session;
    }

private :
    IRAPISessionPtr m_Session;
};


DeviceImpl::DeviceImpl( IRAPIDevicePtr device )
    : m_Device(device) {
}


std::wstring DeviceImpl::GetId() const
{
    RAPI_DEVICEINFO devinfo;

    if(m_Device->GetDeviceInfo(&devinfo) == NOERROR)
    {
        std::wostringstream buf;

        buf << std::hex << std::uppercase
            << devinfo.DeviceId.Data1 << "-"
            << devinfo.DeviceId.Data2 << "-"
            << devinfo.DeviceId.Data3 << "-"
            << devinfo.DeviceId.Data4[0] << devinfo.DeviceId.Data4[1] << "-"
            << devinfo.DeviceId.Data4[2] << devinfo.DeviceId.Data4[3]
            << devinfo.DeviceId.Data4[4] << devinfo.DeviceId.Data4[5]
            << devinfo.DeviceId.Data4[6] << devinfo.DeviceId.Data4[7] << std::ends;

        return buf.str();
    }

    throw RemoteException("");
}


std::wstring DeviceImpl::GetName() const
{
    RAPI_DEVICEINFO devinfo;

    if(m_Device->GetDeviceInfo(&devinfo) == NOERROR)
        return devinfo.bstrName;

    throw RemoteException("");
}


std::wstring DeviceImpl::GetPlatform() const 
{
    RAPI_DEVICEINFO devinfo;

    if(m_Device->GetDeviceInfo(&devinfo) == NOERROR)
        return devinfo.bstrPlatform;

    throw RemoteException("");
}


std::wstring DeviceImpl::GetVersion() const 
{
    RAPI_DEVICEINFO devinfo;

    if(m_Device->GetDeviceInfo(&devinfo) == NOERROR)
    {
        std::wostringstream buf;

        buf << devinfo.dwOsVersionMajor << L"."
            << devinfo.dwOsVersionMinor << std::ends;

        return buf.str();
    }

    throw RemoteException("");
}


void DeviceImpl::CopyFileTo( const std::wstring& sourcePath, const std::wstring& targetPath ) const
{
    IRAPISessionPtr session;

    if(m_Device->CreateSession(&session) == S_OK)
    {
        if(session->CeRapiInit() == S_OK)
        {
            FileBuffer buffer;

            Win32ReadSourceFile(sourcePath, buffer);
            WinCeWriteTargetFile(session, targetPath, buffer);

            session->CeRapiUninit();
            return;
        }
    }

    throw RemoteException("");

}


void DeviceImpl::Execute( const std::wstring path, const std::wstring& args ) const
{
    IRAPISessionPtr session;

    if(m_Device->CreateSession(&session) == S_OK)
    {
        if(session->CeRapiInit() == S_OK)
        {
            PROCESS_INFORMATION procinfo;

            session->CeCreateProcess(path.c_str(), args.c_str(), 0, 0, FALSE, DEBUG_PROCESS, 0, 0, 0, &procinfo);

            WaitForSingleObject(procinfo.hProcess, INFINITE);
            DWORD exitCode = 0;
            GetExitCodeProcess(procinfo.hProcess, &exitCode);

            session->CeRapiUninit();
            return;
        }
    }

    throw RemoteException("");
}
