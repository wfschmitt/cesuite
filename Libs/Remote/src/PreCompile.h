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
 * \date   2010-09-20 17:22
 * \brief  Remote precompiled header.
 */

#if !defined(REMOTE_PRECOMPILE_H)
#define REMOTE_PRECOMPILE_H

#if defined(_WINDLL)
#define REMOTE_DLL
#define REMOTE_EXPORT
#endif

#include <WinSock2.h>
#include <Rapi2.h>

#include "Core/CoreApi.h"
#include "Registry/RegistryApi.h"
#include "Remote/RemoteApi.h"

#pragma comment(lib, "rapi")
#pragma comment(lib, "rapiuuid")

#endif  // REMOTE_PRECOMPILE_H
