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
 * \date   2010-10-03 15:15
 * \brief  Remote registry implementation.
 */

#if !defined(REMOTE_REMOTEREGISTRYIMPL_H)
#define REMOTE_REMOTEREGISTRYIMPL_H

#include "Registry/Registry.h"
#include "DetailFwd.h"

namespace Remote
{
    /*!
     * \author  Johan Andersson <skagget77@gmail.com>
     * \date    2010-10-03 15:15
     * \ingroup Remote
     * \brief   RemoteRegistryImpl class.
     */
    class REGISTRY_API RemoteRegistryImpl : public Registry::IRegistry
    {
    public :
        /*!
         * Constructor.
         *
         * \param session 
         */
        RemoteRegistryImpl( IRAPISessionPtr session );

        /*!
         * Constructor.
         *
         * \param session 
         * \param key Registry key.
         */
        RemoteRegistryImpl( IRAPISessionPtr session, const std::wstring& key );

        /* Documented in IRegistry. */
        bool HasValue( const std::wstring& name ) const;

        /* Documented in IRegistry. */
        int GetValueInt( const std::wstring& name ) const;

        /* Documented in IRegistry. */
        void SetValueInt( const std::wstring& name, int value );

        /* Documented in IRegistry. */
        void RemoveValue( const std::wstring& name );

    private :
        IRAPISessionPtr m_Session;
        std::wstring m_Key;
    };
}

#endif   /* REMOTE_REMOTEREGISTRYIMPL_H */
