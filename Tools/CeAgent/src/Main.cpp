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
 * \date   2010-04-13 22:38
 * \brief  CeAgent.
 */

#include "PreCompile.h"
#include "Core/CoreException.h"
#include "Core/Parser.h"
#include "Core/ParserFactory.h"
#include "Debug/Debugger.h"
#include "Debug/DebuggerFactory.h"
#include "Registry/Registry.h"
#include "Registry/RegistryFactory.h"
#include "ProcessMonitor.h"

#include <Windows.h>


using namespace CeAgent;
using namespace Core;
using namespace Debug;
using namespace Registry;


/*!
 * Executes the specified file.
 *
 * \param name Name.
 * \param file File to execute.
 * \param args Command line options.
 *
 */
void RunProcess( const std::wstring& name, const std::wstring& file, const std::wstring& args )
{
    PROCESS_INFORMATION procinfo;

    if(CreateProcess(file.c_str(), args.c_str(), 0, 0, 0, DEBUG_PROCESS, 0, 0, 0, &procinfo))
    {
        IDebuggerPtr debugger = CreateDebugger(
            IDebugListenerPtr(new ProcessMonitor(CreateRegistry(L"Software\\CeAgent"), name)));

        while(debugger->Wait());
    }
    else
        throw CoreException(L"Failed to create process");
}


/*!
 * CeAgent application entry point.
 *
 * \ingroup CeAgent
 * \param   instance Application instance.
 * \param   prevInstance Not used.
 * \param   cmdLine Command line options.
 * \param   cmdShow Control how the window is to be shown.
 * \return  Application exit code.
 */
int WINAPI WinMain( HINSTANCE instance, HINSTANCE prevInstance, LPWSTR cmdLine, int cmdShow )
{
    try 
    {
        IParserPtr parser = CreateParser(cmdLine, true);

        std::wstring name = parser->GetValue(L"/name");
        std::wstring file = parser->GetValue(L"/path");
        std::wstring args = parser->GetValue(L"/args", L"");

        RunProcess(name, file, args);
    }
    catch(CoreException& e) {
        MessageBox(0, e.GetDetails().c_str(), L"CeAgent", MB_OK);
    }
    catch(...) {
        MessageBox(0, L"Caught unhandled exception", L"CeAgent", MB_OK);
    }
}
