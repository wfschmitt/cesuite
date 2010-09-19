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
 * \brief  Parser forward declarations.
 */

#if !defined(PARSER_PARSERFWD_H)
#define PARSER_PARSERFWD_H

#include <boost/tr1/memory.hpp>

namespace Parser
{
    struct IParser;
    typedef std::tr1::shared_ptr<IParser> IParserPtr;
}

#endif   // PARSER_PARSERFWD_H
