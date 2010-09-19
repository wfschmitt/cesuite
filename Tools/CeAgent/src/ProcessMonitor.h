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
 * \date   2010-04-19 21:01
 * \brief  ProcessMonitor definition.
 */

#if !defined(CEDEBUG_PROCESSMONITOR_H)
#define CEDEBUG_PROCESSMONITOR_H

#include "Debug/DebugListenerBase.h"
#include "Registry/RegistryFwd.h"

namespace CeDebug
{
    /*!
     * \author  Johan Andersson <skagget77@gmail.com>
     * \date    2010-04-19 21:01
     * \ingroup CeDebug
     * \brief   The ProcessMonitor class.
     */
    class ProcessMonitor : public Debug::DebugListenerBase
    {
    public :
        /*!
         *
         */
        enum ProcessState {
            PROCESS_NONE,
            PROCESS_STARTED,
            PROCESS_EXITED
        };

        /*!
         * Constructor.
         *
         * \param registry
         * \param[in] name Name.
         */
        ProcessMonitor( Registry::IRegistryPtr registry, const std::wstring& name );

        /*
         * Inherited from DebugListenerBase.
         */
        void OnCreateProcess();
        void OnExitProcess();

    private :
        Registry::IRegistryPtr m_Registry;
        std::wstring m_Name;
    };
}

#endif   // CEDEBUG_PROCESSMONITOR_H
