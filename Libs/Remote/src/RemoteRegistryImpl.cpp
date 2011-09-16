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
 * \date   2010-04-19 20:00
 * \brief  Remote registry implementation.
 */

#include "PreCompile.h"
#include "Core/CoreException.h"
#include "Registry/RegistryException.h"
//#include "RaiiRegistryKey.h"
#include "RemoteRegistryImpl.h"

#include <Windows.h>


using namespace Registry;
using namespace Remote;


RemoteRegistryImpl::RemoteRegistryImpl( IRAPISessionPtr session ) 
    : m_Session(session) {
}


RemoteRegistryImpl::RemoteRegistryImpl( 
    IRAPISessionPtr session, const std::wstring& key ) 
    : m_Session(session), m_Key(key) {
}


bool RemoteRegistryImpl::HasValue( const std::wstring& name ) const
{
    //RaiiRegKey key(m_Key, false);
    HKEY key;

    if(m_Session->CeRegQueryValueEx(key, name.c_str(), 0, 0, 0, 0) != ERROR_SUCCESS)
        return false;

    return true;
}


int RemoteRegistryImpl::GetValueInt( const std::wstring& name ) const
{
    //RaiiRegKey key(m_Key, false);
    HKEY key;

    DWORD type = 0;
    DWORD data = 0;
    DWORD size = sizeof(data);

    if(m_Session->CeRegQueryValueEx(key, name.c_str(), 0, &type,
        reinterpret_cast<PBYTE>(&data), &size) != ERROR_SUCCESS)
        throw RegistryException(L"Failed to get value");

    if(type != REG_DWORD)
        throw RegistryException(L"Value has wrong type");

    return data;
}


void RemoteRegistryImpl::SetValueInt( const std::wstring& name, int value )
{
    //RaiiRegKey key(m_Key, true);
    HKEY key;

    PBYTE data = reinterpret_cast<PBYTE>(&value);
    DWORD size = sizeof(value);

    if(m_Session->CeRegSetValueEx(key, name.c_str(), 0, REG_DWORD, data, size) != ERROR_SUCCESS)
        throw RegistryException(L"Failed to set value");
}


void RemoteRegistryImpl::RemoveValue( const std::wstring& name )
{
    //RaiiRegKey key(m_Key, false);
    HKEY key;

    if(m_Session->CeRegDeleteValue(key, name.c_str()) != ERROR_SUCCESS)
        throw RegistryException(L"Failed to remove value");
}
