/* $Id$ */

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
 * \brief  Registry implementation.
 */

#include "PreCompile.h"
#include "Registry/RegistryException.h"
#include "RegistryImpl.h"
#include "RAIIRegistryKey.h"

#include <Windows.h>


using namespace Registry;


RegistryImpl::RegistryImpl( const std::wstring& key ) 
    : m_Key(key) {
}


bool RegistryImpl::HasValue( const std::wstring& name ) const
{
    RaiiOpenKey key(m_Key);

    if(RegQueryValueEx(key, name.c_str(), 0, 0, 0, 0) != ERROR_SUCCESS)
        return false;

    return true;
}


int RegistryImpl::GetValueInt( const std::wstring& name ) const
{
    RaiiOpenKey key(m_Key);

    DWORD type = 0;
    DWORD data = 0;
    DWORD size = sizeof(data);

    if(RegQueryValueEx(key, name.c_str(), 0, &type, reinterpret_cast<PBYTE>(&data), &size) != ERROR_SUCCESS)
        throw RegistryException("");

    if(type != REG_DWORD)
        throw RegistryException("");

    return data;
}


void RegistryImpl::SetValueInt( const std::wstring& name, int value )
{
    RaiiCreateKey key(m_Key);

    PBYTE data = reinterpret_cast<PBYTE>(&value);
    DWORD size = sizeof(value);

    if(RegSetValueEx(key, name.c_str(), 0, REG_DWORD, data, size) != ERROR_SUCCESS)
        throw RegistryException("");
}


void RegistryImpl::RemoveValue( const std::wstring& name )
{
    RaiiOpenKey key(m_Key);

    if(RegDeleteValue(key, name.c_str()) != ERROR_SUCCESS)
        throw RegistryException("");
}
