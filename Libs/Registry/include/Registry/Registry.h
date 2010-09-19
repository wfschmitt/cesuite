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
 * \date   2010-04-11 17:57
 * \brief  Registry interface definition.
 */

#if !defined(REGISTRY_REGISTRY_H)
#define REGISTRY_REGISTRY_H

#include "RegistryFwd.h"

#include <string>

namespace Registry
{
   /*!
    * \author  Johan Andersson <skagget77@gmail.com>
    * \date    2010-04-11 17:57
    * \ingroup Registry
    * \brief   The IRegistry interface.
    */
   struct IRegistry
   {
      /*!
       * Destructor.
       */
      virtual ~IRegistry() {}

      /*!
       * Returns true if the value, identified by the specified key, exist.
       *
       * \param  key 
       * \return 
       */
      virtual bool HasValue( const std::wstring& name ) const = 0;

      /*!
       * Returns the value as an intenger.
       *
       * \param  name 
       * \return 
       */
      virtual int GetValueInt( const std::wstring& name ) const = 0;

      /*! 
       * Sets the value of the specified registry key.
       *
       * \param name Registry key name.
       * \param value Value
       */
      virtual void SetValueInt( const std::wstring& name, int value ) = 0;

      /*!
       * Removes the specified value.
       *
       * \param key Key identifying the value.
       */
      virtual void RemoveValue( const std::wstring& name ) = 0;
   };
}

#endif   // REGISTRY_REGISTRY_H
