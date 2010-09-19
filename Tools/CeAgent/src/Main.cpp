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

#include "PreCompile.h"
#include "ProcessMonitor.h"
#include "Debug/Debug.h"
#include "Debug/DebugFactory.h"
#include "Parser/Parser.h"
#include "Parser/ParserFactory.h"
#include "Registry/Registry.h"
#include "Registry/RegistryFactory.h"

#include <Windows.h>


using namespace CeDebug;
using namespace Debug;
using namespace Parser;
using namespace Registry;


/*!
 *
 *
 */
void RunProcess( const std::wstring& name, const std::wstring& file, const std::wstring& args )
{
    PROCESS_INFORMATION procinfo;

    if(CreateProcess(file.c_str(), args.c_str(), 0, 0, 0, DEBUG_PROCESS, 0, 0, 0, &procinfo))
    {
        IDebugPtr debug = CreateDebug(
            IDebugListenerPtr(new ProcessMonitor(CreateRegistry(L"Software\\CeDebug"), name)));

        while(debug->Wait())
            Sleep(50);
    }
}


/*!
 * CeDebug /key name /debug "\Storage Card\TestWM5\TestWM5 -xml -o \Test"
 *
 */
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow )
{
    try {
        IParserPtr parser = CreateParser(lpCmdLine);

        std::wstring name = parser->GetArgumentValue(L"/name");
        std::wstring file = parser->GetArgumentValue(L"/file");
        std::wstring args = parser->GetArgumentValue(L"/args");

        RunProcess(name, file, args);
    }
    catch(std::runtime_error&) {
        MessageBox(0, L"Failed to launch process", L"CeDebug", MB_OK);
    }
}
