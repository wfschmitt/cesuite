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

#if !defined(REGISTRY_REGISTRYIMPL_H)
#define REGISTRY_REGISTRYIMPL_H

#include "Registry/Registry.h"

namespace Registry
{
    /*!
     * \author  Johan Andersson <skagget77@gmail.com>
     * \date    2010-04-19 20:01
     * \ingroup Registry
     * \brief   The RegistryImpl class.
     */
    class REGISTRY_API RegistryImpl : public IRegistry
    {
    public :
        /*!
         *
         *
         * \param  root 
         */
        RegistryImpl( const std::wstring& key = L"" );
        
        /*
         * Inherited from IRegistry.
         */
        bool HasValue( const std::wstring& name ) const;
        int GetValueInt( const std::wstring& name ) const;
        void SetValueInt( const std::wstring& name, int value );
        void RemoveValue( const std::wstring& name );

    private :
        std::wstring m_Key;
    };
}

#endif   // REGISTRY_REGISTRYIMPL_H
