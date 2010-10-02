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
 * \date   2010-04-19 20:28
 * \brief  DebugListener interface.
 */

#if !defined(DEBUG_DEBUGLISTENER_H)
#define DEBUG_DEBUGLISTENER_H

#include "Core/BasicTypes.h"

namespace Debug
{
    /*!
     * \author  Johan Andersson <skagget77@gmail.com>
     * \date    2010-04-11 17:57
     * \ingroup Debug
     * \brief   IDebugListener interface.
     */
    struct IDebugListener 
    {
        /*!
         * Destructor.
         */
        virtual ~IDebugListener() {}

        /*! 
         * Called when the debugged process is created.
         */
        virtual void OnCreateProcess() = 0;

        /*! 
         * Called when the debugged process exits.
         *
         * \param exitCode Process exit code.
         */
        virtual void OnExitProcess( uint32 exitCode ) = 0;

        /*! 
         * Called when a thread is created in the debugged process.
         */
        virtual void OnCreateThread() = 0;

        /*!
         * Called when a thread in the debugged process exits.
         */
        virtual void OnExitThread() = 0;

        /*!
         * Called when the debugged process loads a DLL.
         */
        virtual void OnLoadDll() = 0;

        /*! 
         * Called when the debugged process unloads a DLL.
         */
        virtual void OnUnloadDll() = 0;

        /*! 
         * Called when an exception is thrown in the debugged process.
         */
        virtual void OnException() = 0;
    };
}

#endif   // DEBUG_DEBUGLISTENER_H
