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
 * \date   2010-10-01 14:38
 * \brief  Win32 HANDLE with RAII semantics.
 */

#if !defined(REMOTE_RAIIHANDLE_H)
#define REMOTE_RAIIHANDLE_H

namespace Remote
{
    /*!
     * \author  Johan Andersson <skagget77@gmail.com>
     * \date    2010-10-01 14:40
     * \ingroup Remote
     * \brief   RaiiHandle class.
     */
    class RaiiHandle
    {
    public :
        /*!
         * Constructor.
         *
         * \param handle Win32 HANDLE
         */
        RaiiHandle( HANDLE handle )
            : m_Handle(handle) {
        }

        /*!
         * Destructor.
         */
        ~RaiiHandle() 
        {
            if(m_Handle != INVALID_HANDLE_VALUE)
                CloseHandle(m_Handle);
        }

        /*!
         * Converts instance to a Win32 HANDLE.
         *
         * \return Win32 HANDLE.
         */
        operator HANDLE() const {
            return m_Handle;
        }

    private :
        HANDLE m_Handle;
    };

    /*!
     * \author  Johan Andersson <skagget77@gmail.com>
     * \date    2010-10-01 14:40
     * \ingroup Remote
     * \brief   RaiiHandle class.
     */
    class RaiiCeHandle
    {
    public :
        /*!
         * Constructor.
         *
         * \param handle Win32 HANDLE
         */
        RaiiCeHandle( IRAPISessionPtr session, HANDLE handle )
            : m_Session(session), m_Handle(handle) {
        }

        /*!
         * Destructor.
         */
        ~RaiiCeHandle() 
        {
            if(m_Handle != INVALID_HANDLE_VALUE)
                m_Session->CeCloseHandle(m_Handle);
        }

        /*!
         * Converts instance to a Win32 HANDLE.
         *
         * \return Win32 HANDLE.
         */
        operator HANDLE() const {
            return m_Handle;
        }

    private :
        IRAPISessionPtr m_Session;
        HANDLE m_Handle;
    };
}

#endif  // REMOTE_RAIIHANDLE_H
