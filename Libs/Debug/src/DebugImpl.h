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
 * \date   2010-04-19 20:30
 * \brief  Debug implementation.
 */

#if !defined(DEBUG_DEBUGIMPL_H)
#define DEBUG_DEBUGIMPL_H

#include "Debug/Debug.h"
#include "Debug/DebugListener.h"

#include <vector>

namespace Debug
{
   /*!
    * \author  Johan Andersson <skagget77@gmail.com>
    * \date    2010-04-11 17:57
    * \ingroup Debug
    * \brief   The DebugImpl class.
    */
    class DebugImpl : public IDebug
    {
    public :
        /*
         * Inherited from IDebug.
         */
        void RegisterListener( IDebugListenerPtr listener );
        bool Wait() const;

    private :
        typedef std::vector<IDebugListenerPtr> DebugListenerCollection;
        DebugListenerCollection m_Listeners;
    };
}

#endif   // DEBUG_DEBUGIMPL_H
