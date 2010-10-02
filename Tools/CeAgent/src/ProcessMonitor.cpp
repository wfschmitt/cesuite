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

#include "PreCompile.h"
#include "Registry/Registry.h"
#include "Registry/RegistryException.h"
#include "ProcessMonitor.h"

#include <string>


using namespace CeAgent;
using namespace Registry;


ProcessMonitor::ProcessMonitor( IRegistryPtr registry, const std::wstring& name )
    : m_Registry(registry), m_Name(name) 
{
    try {
        m_Registry->SetValueInt(m_Name + L".status", PROCESS_NONE);
        m_Registry->SetValueInt(m_Name + L".exitCode", 0);
    }
    catch(RegistryException&) {
    }
}


void ProcessMonitor::OnCreateProcess() 
{
    try {
        m_Registry->SetValueInt(m_Name + L".status", PROCESS_STARTED);
    }
    catch(RegistryException&) {
    }
}


void ProcessMonitor::OnExitProcess( uint32 exitCode ) 
{
    try {
        m_Registry->SetValueInt(m_Name + L".status", PROCESS_EXITED);
        m_Registry->SetValueInt(m_Name + L".exitCode", exitCode);
    }
    catch(RegistryException&) {
    }
}
