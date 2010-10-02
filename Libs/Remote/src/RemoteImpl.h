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
 * \date   2010-09-23 20:29
 * \brief  Remote implementation
 */

#if !defined(REMOTE_REMOTEIMPL_H)
#define REMOTE_REMOTEIMPL_H

#include "Remote/Remote.h"
#include "DetailFwd.h"


namespace Remote
{
    /*!
     * \author  Johan Andersson <skagget77@gmail.com>
     * \date    2010-09-23 20:41
     * \ingroup Registry
     * \brief   RemoteImpl class.
     */
    class RemoteImpl : public IRemote
    {
    public :
        RemoteImpl();

        /* Documented in IRemote. */
        IDeviceCollection ListDevices() const;

    private :
        IRAPIDesktopPtr m_Desktop;
    };
}

#endif  /* REMOTE_REMOTEIMPL_H */
