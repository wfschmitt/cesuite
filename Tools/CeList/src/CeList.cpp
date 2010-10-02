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
 * \date   2010-10-02 22:49
 * \brief  CeList.
 */

#include "PreCompile.h"
#include "Core/CoreException.h"
#include "Remote/Device.h"
#include "Remote/Remote.h"
#include "Remote/RemoteFactory.h"
#include "DeviceInfoWriter.h"

#include <atlbase.h>

#include <algorithm>
#include <iostream>


using namespace CeList;
using namespace Remote;


/*!
 * CeList application entry point.
 *
 * \ingroup CeList
 * \param   argc Command line option count.
 * \param   argv Command line option arguments.
 * \return  Application exit code.
 */
int wmain( int, char*[] )
{
   if(CoInitializeEx(0, COINIT_MULTITHREADED) == S_OK)
   {
       try 
       {
           IDeviceCollection devices = CreateRemote()->ListDevices();

           std::for_each(devices.begin(), devices.end(), 
               DeviceInfoWriter(std::wcout));
       }
       catch(Core::CoreException& e) {
           std::wcout << L"Error: " << e.GetDetails() << L"." << std::endl;
       }
       catch(...) {
           std::wcout << L"Error: Unknown." << std::endl;
       }

       CoUninitialize();
   }
   else
       std::wcout << L"Error: Failed to initialize COM." << std::endl;
}
