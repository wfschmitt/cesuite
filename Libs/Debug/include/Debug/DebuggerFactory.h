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
 * \date   2010-04-19 20:26
 * \brief  Debugger factory function.
 */

#if !defined(DEBUG_DEBUGGERFACTORY_H)
#define DEBUG_DEBUGGERFACTORY_H

#include "DebugFwd.h"

namespace Debug
{
   /*!    
    * Returns a new IDebugger implementation.
    *
    * \ingroup Debug
    * \param   listener Debug listener to register with the returned instance.
    * \return  An IDebugger implementation.
    */
   DEBUG_API IDebuggerPtr CreateDebugger( IDebugListenerPtr listener );
}

#endif   // DEBUG_DEBUGGERFACTORY_H
