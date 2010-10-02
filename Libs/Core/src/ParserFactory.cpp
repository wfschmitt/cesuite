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
 * \date   2010-04-18 01:10
 * \brief  Parser factory function.
 */

#include "PreCompile.h"
#include "Core/Parser.h"
#include "Core/ParserFactory.h"
#include "ParserImpl.h"


using namespace Core;


IParserPtr Core::CreateParser( const std::wstring& cmdLine ) {
    return IParserPtr(new ParserImpl(cmdLine, false));
}


IParserPtr Core::CreateParser( const std::wstring& cmdLine, bool caseInsensitive ) {
    return IParserPtr(new ParserImpl(cmdLine, caseInsensitive));
}
