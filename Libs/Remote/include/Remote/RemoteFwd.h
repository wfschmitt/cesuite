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
 * \date   2010-04-11 19:15
 * \brief  Remote forward declarations.
 */

#if !defined(REMOTE_REMOTEFWD_H)
#define REMOTE_REMOTEFWD_H

#include <boost/tr1/memory.hpp>
#include <vector>

namespace Remote
{
    struct IRemote;
    typedef std::tr1::shared_ptr<IRemote> IRemotePtr;

    struct IDevice;
    typedef std::tr1::shared_ptr<IDevice> IDevicePtr;
    typedef std::vector<IDevicePtr> IDeviceCollection;
}

#endif   // REMOTE_REMOTEFWD_H
