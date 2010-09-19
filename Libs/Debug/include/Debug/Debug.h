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
 * \date   2010-04-19 20:25
 * \brief  Debug interface definition.
 */

#if !defined(DEBUG_DEBUG_H)
#define DEBUG_DEBUG_H

#include "DebugFwd.h"

namespace Debug
{
    /*!
     * \author  Johan Andersson <skagget77@gmail.com>
     * \date    2010-04-19 20:25
     * \ingroup Debug
     * \brief   The IDebug interface.
     */
    struct IDebug
    {
        /*!
         * Destructor.
         */
        virtual ~IDebug() {}

        /*! 
         * Register an additional listener.
         *
         * \param listener Listener.
         */
        virtual void RegisterListener( IDebugListenerPtr listener ) = 0;

        /*!
         * Waits for a new debug event to occur.
         *
         * \return True if more debug events can occur, false otherwise.
         */
        virtual bool Wait() const = 0;
    };
}

#endif   // DEBUG_DEBUG_H
