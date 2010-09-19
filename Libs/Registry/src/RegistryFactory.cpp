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
 * \date   2010-04-19 19:59
 * \brief  Registry factory function.
 */

#include "PreCompile.h"
#include "Registry/Registry.h"
#include "Registry/RegistryFactory.h"
#include "RegistryImpl.h"


using namespace Registry;


IRegistryPtr Registry::CreateRegistry() {
   return IRegistryPtr(new RegistryImpl);
}


IRegistryPtr Registry::CreateRegistry( const std::wstring& key ) {
    return IRegistryPtr(new RegistryImpl(key));
}
