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
 * \brief  RapiRegistry implementation.
 */

#include "PreCompile.h"
#include "Registry/RegistryException.h"
#include "RaiiRegistryKey.h"


using namespace Registry;


RaiiRegKey::RaiiRegKey( const std::wstring& key, bool createKey )
{
    if(createKey)
    {
        if(RegCreateKeyEx(HKEY_CURRENT_USER, key.c_str(), 0, 0, 0,
            KEY_QUERY_VALUE|KEY_SET_VALUE, 0, &m_Key, 0) != ERROR_SUCCESS)
            throw RegistryException(L"Failed to create registry key");
    }
    else
    {
        if(RegOpenKeyEx(HKEY_CURRENT_USER, key.c_str(), 0, 
            KEY_QUERY_VALUE|KEY_SET_VALUE, &m_Key) != ERROR_SUCCESS)
            throw RegistryException(L"Failed to open registry key");
    }
}


RaiiRegKey::~RaiiRegKey() {
    RegCloseKey(m_Key);
}


RaiiRegKey::operator HKEY() const {
    return m_Key;
}
