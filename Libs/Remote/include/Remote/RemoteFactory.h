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
 * \date   2010-10-01 10:24
 * \brief  Remote factory function.
 */

#if !defined(REMOTE_REMOTEFACTORY_H)
#define REMOTE_REMOTEFACTORY_H

#include "RemoteFwd.h"

namespace Remote
{
   /*!
    * Creates a new instance of an IRemote implementation.
    * 
    * \ingroup Remote
    * \return  An IRemote implementation.
    */
    REMOTE_API IRemotePtr CreateRemote();
}

#endif  /* REMOTE_REMOTEFACTORY_H */
