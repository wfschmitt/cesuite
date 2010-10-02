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
 * \date   2010-04-19 20:30
 * \brief  Debugger factory function.
 */

#include "PreCompile.h"
#include "Debug/Debugger.h"
#include "Debug/DebuggerFactory.h"
#include "Debug/DebugListener.h"
#include "DebuggerImpl.h"


using namespace Debug;


IDebuggerPtr Debug::CreateDebugger( IDebugListenerPtr listener ) 
{
   IDebuggerPtr debugger(new DebuggerImpl);

   // Register listener with implementation.
   debugger->RegisterListener(listener);

   return debugger;
}
