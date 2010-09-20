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
 * \brief  RAII Registry keys.
 */

#if !defined(REGISTRY_RAIIREGISTRYKEY_H)
#define REGISTRY_RAIIREGISTRYKEY_H

#include <Windows.h>

#include <string>

namespace Registry
{
    class RaiiOpenKey
    {
    public :
        RaiiOpenKey( const std::wstring& key );
        ~RaiiOpenKey();

        operator HKEY() const;

    private :
        HKEY m_Key;
    };

    class RaiiCreateKey
    {
    public :
        RaiiCreateKey( const std::wstring& key );
        ~RaiiCreateKey();

        operator HKEY() const;

    private :
        HKEY m_Key;
    };
}

#endif  // REGISTRY_RAIIREGISTRYKEY_H
