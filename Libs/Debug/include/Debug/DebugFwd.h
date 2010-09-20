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
 * \date   2010-04-11 19:15
 * \brief  Debug forward declarations.
 */

#if !defined(DEBUG_DEBUGFWD_H)
#define DEBUG_DEBUGFWD_H

#include <boost/tr1/memory.hpp>

namespace Debug
{
    struct IDebug;
    typedef std::tr1::shared_ptr<IDebug> IDebugPtr;

    struct IDebugListener;
    typedef std::tr1::shared_ptr<IDebugListener> IDebugListenerPtr;
}

#endif   // DEBUG_DEBUGFWD_H
