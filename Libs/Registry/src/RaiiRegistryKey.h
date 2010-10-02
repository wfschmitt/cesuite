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
 * \brief  Win32 registry key with RAII semantics.
 */

#if !defined(REGISTRY_RAIIREGISTRYKEY_H)
#define REGISTRY_RAIIREGISTRYKEY_H

#include <Windows.h>

#include <string>

namespace Registry
{
    /*!
     * \author  Johan Andersson <skagget77@gmail.com>
     * \date    2010-10-02 14:25
     * \ingroup Registry
     * \brief   RaiiRegKey class.
     */
    class RaiiRegKey
    {
    public :
        /*!
         * Constructor.
         *
         * \param key Registry key name.
         * \param createKey True to create the key, false to open it.
         */
        RaiiRegKey( const std::wstring& key, bool createKey );

        /*!
         * Destructor.
         */
        ~RaiiRegKey();

        /*!
         * Converts the instance to a Win32 HKEY.
         *
         * \return Win32 HKEY.
         */
        operator HKEY() const;

    private :
        HKEY m_Key;
    };
}

#endif  /* REGISTRY_RAIIREGISTRYKEY_H */
