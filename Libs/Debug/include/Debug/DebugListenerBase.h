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
 * \date   2010-04-19 20:29
 * \brief  DebugListener base class.
 */

#if !defined(DEBUG_DEBUGLISTENERBASE_H)
#define DEBUG_DEBUGLISTENERBASE_H

#include "DebugListener.h"

namespace Debug
{
    /*!
     * \author  Johan Andersson <skagget77@gmail.com>
     * \date    2010-04-11 17:57
     * \ingroup Debug
     * \brief   DebugListenerBase class.
     */
    class DebugListenerBase : public IDebugListener 
    {
        /*!
         * Default implementation does nothing.
         */
        void OnCreateProcess() {
        }

        /*!
         * Default implementation does nothing.
         */
        void OnExitProcess( uint32 ) {
        }

        /*!
         * Default implementation does nothing.
         */
        void OnCreateThread() {
        }

        /*!
         * Default implementation does nothing.
         */
        void OnExitThread() {
        }

        /*!
         * Default implementation does nothing.
         */
        void OnLoadDll() {
        }

        /*!
         * Default implementation does nothing.
         */
        void OnUnloadDll() {
        }

        /*!
         * Default implementation does nothing.
         */
        void OnException() {
        }
    };
}

#endif   // DEBUG_DEBUGLISTENERBASE_H
