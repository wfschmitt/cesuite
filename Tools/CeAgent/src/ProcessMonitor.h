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

#if !defined(CEAGENT_PROCESSMONITOR_H)
#define CEAGENT_PROCESSMONITOR_H

#include "Debug/DebugListenerBase.h"
#include "Registry/RegistryFwd.h"

namespace CeAgent
{
    /*!
     * \author  Johan Andersson <skagget77@gmail.com>
     * \date    2010-04-19 21:01
     * \ingroup CeAgent
     * \brief   ProcessMonitor class.
     */
    class ProcessMonitor : public Debug::DebugListenerBase
    {
    public :
        /*!
         * The different states a monitored process can be in.
         */
        enum ProcessState 
        {
            PROCESS_NONE,
            PROCESS_STARTED,
            PROCESS_EXITED
        };

        /*!
         * Constructor.
         *
         * \param registry Registry.
         * \param name Name.
         */
        ProcessMonitor( Registry::IRegistryPtr registry, const std::wstring& name );

        /* Documented in IDebugListener. */
        void OnCreateProcess();

        /* Documented in IDebugListener. */
        void OnExitProcess( uint32 exitCode );

    private :
        Registry::IRegistryPtr m_Registry;
        std::wstring m_Name;
    };
}

#endif   /* CEAGENT_PROCESSMONITOR_H */
