
#include "PreCompile.h"
#include "CeRunFwd.h"

#include <AtlBase.h>

#include <iostream>

int wmain()
{
   CoInitializeEx(0, COINIT_MULTITHREADED);
   {
      IRAPIDesktopPtr rapidesktop;

      if(rapidesktop.CoCreateInstance(CLSID_RAPI) == S_OK)
      {
         IRAPIEnumDevicesPtr enumdevices;

         if(rapidesktop->EnumDevices(&enumdevices) == S_OK)
         {
            IRAPIDevicePtr device;

            if(enumdevices->Next(&device) == S_OK)
            {
               RAPI_DEVICEINFO devinfo;

               device->GetDeviceInfo(&devinfo);

               std::wcout << "Name......: " << devinfo.bstrName     << std::endl
                          << "Plaform...: " << devinfo.bstrPlatform << std::endl
                          << "Version...: " << devinfo.dwOsVersionMajor << "." 
                                            << devinfo.dwOsVersionMinor << std::endl;
            }
         }
      }
   }
   CoUninitialize();
}
