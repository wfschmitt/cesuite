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
 * \brief  Registry factory function.
 */

#if !defined(REGISTRY_REGISTRYFACTORY_H)
#define REGISTRY_REGISTRYFACTORY_H

#include "RegistryFwd.h"

namespace Registry
{
   /*!
    * Returns a new IRegistry implementation.
    * 
    * \ingroup Registry
    * \return  An IRegistry implementation.
    */
   REGISTRY_API IRegistryPtr CreateRegistry();

   /*!
    * Returns a new IRegistry implementation.
    * 
    * \ingroup Registry
    * \param   key Registry key.
    * \return  An IRegistry implementation.
    */
   REGISTRY_API IRegistryPtr CreateRegistry( const std::wstring& key );
}

#endif   /* REGISTRY_REGISTRYFACTORY_H */
