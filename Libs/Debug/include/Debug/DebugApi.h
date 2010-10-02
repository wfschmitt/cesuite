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
 * \brief  Debug API import/export.
 */

#if !defined(DEBUG_DEBUGAPI_H)
#define DEBUG_DEBUGAPI_H

#if defined(DEBUG_DLL)
#if defined(DEBUG_EXPORT)
#define DEBUG_API __declspec(dllexport)
#else
#define DEBUG_API __declspec(dllimport)
#endif
#else
#define DEBUG_API
#endif

#endif  // DEBUG_DEBUGAPI_H
