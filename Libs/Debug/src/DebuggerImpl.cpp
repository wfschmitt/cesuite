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
 * \date   2010-04-19 20:30
 * \brief  Debug implementation.
 */

#include "PreCompile.h"
#include "DebuggerImpl.h"

#include <Windows.h>

#include <algorithm>


using namespace Debug;


namespace 
{
    class OnCreateProcess 
    {
    public :
        OnCreateProcess( LPCREATE_PROCESS_DEBUG_INFO info )
            : m_Info(info) {
        }

        void operator()( IDebugListenerPtr listener ) const {
            listener->OnCreateProcess();
        }

    private :
        LPCREATE_PROCESS_DEBUG_INFO m_Info;
    };

    class OnExitProcess 
    {
    public :
        OnExitProcess( LPEXIT_PROCESS_DEBUG_INFO info )
            : m_Info(info) {
        }

        void operator()( IDebugListenerPtr listener ) const {
            listener->OnExitProcess(m_Info->dwExitCode);
        }

    private :
        LPEXIT_PROCESS_DEBUG_INFO m_Info;
    };

    class OnCreateThread
    {
    public :
        OnCreateThread( LPCREATE_THREAD_DEBUG_INFO info )
            : m_Info(info) {
        }

        void operator()( IDebugListenerPtr listener ) const {
            listener->OnCreateThread();
        }

    private :
        LPCREATE_THREAD_DEBUG_INFO m_Info;
    };

    class OnExitThread
    {
    public :
        OnExitThread( LPEXIT_THREAD_DEBUG_INFO info )
            : m_Info(info) {
        }

        void operator()( IDebugListenerPtr listener ) const {
            listener->OnExitThread();
        }

    private :
        LPEXIT_THREAD_DEBUG_INFO m_Info;
    };

    class OnLoadDll
    {
    public :
        OnLoadDll( LPLOAD_DLL_DEBUG_INFO info )
            : m_Info(info) {
        }

        void operator()( IDebugListenerPtr listener ) const {
            listener->OnLoadDll();
        }

    private :
        LPLOAD_DLL_DEBUG_INFO m_Info;
    };

    class OnUnloadDll
    {
    public :
        OnUnloadDll( LPUNLOAD_DLL_DEBUG_INFO info )
            : m_Info(info) {
        }

        void operator()( IDebugListenerPtr listener ) const {
            listener->OnUnloadDll();
        }

    private :
        LPUNLOAD_DLL_DEBUG_INFO m_Info;
    };

    class OnException
    {
    public :
        OnException( LPEXCEPTION_DEBUG_INFO info )
            : m_Info(info) {
        }

        void operator()( IDebugListenerPtr listener ) const {
            listener->OnException();
        }

    private :
        LPEXCEPTION_DEBUG_INFO m_Info;
    };
}


void DebuggerImpl::RegisterListener( IDebugListenerPtr listener ) {
   m_Listeners.push_back(listener);
}


bool DebuggerImpl::Wait() const 
{
   DEBUG_EVENT debug;

   if(WaitForDebugEvent(&debug, INFINITE))
   {
      switch(debug.dwDebugEventCode)
      {
      case CREATE_PROCESS_DEBUG_EVENT :
         std::for_each(m_Listeners.begin(), m_Listeners.end(), 
            OnCreateProcess(&debug.u.CreateProcessInfo));
         break;

      case EXIT_PROCESS_DEBUG_EVENT :
         std::for_each(m_Listeners.begin(), m_Listeners.end(), 
            OnExitProcess(&debug.u.ExitProcess));
         break;

      case CREATE_THREAD_DEBUG_EVENT :
         std::for_each(m_Listeners.begin(), m_Listeners.end(), 
            OnCreateThread(&debug.u.CreateThread));
         break;

      case EXIT_THREAD_DEBUG_EVENT :
         std::for_each(m_Listeners.begin(), m_Listeners.end(),
            OnExitThread(&debug.u.ExitThread));
         break;

      case LOAD_DLL_DEBUG_EVENT :
         std::for_each(m_Listeners.begin(), m_Listeners.end(),
            OnLoadDll(&debug.u.LoadDll));
         break;

      case UNLOAD_DLL_DEBUG_EVENT :
         std::for_each(m_Listeners.begin(), m_Listeners.end(), 
            OnUnloadDll(&debug.u.UnloadDll));
         break;

      case EXCEPTION_DEBUG_EVENT :
         std::for_each(m_Listeners.begin(), m_Listeners.end(),
            OnException(&debug.u.Exception));
         break;
      }
      
      ContinueDebugEvent(
         debug.dwProcessId, debug.dwThreadId, DBG_EXCEPTION_NOT_HANDLED);

      return true;
   }
   else
      return false;
}
