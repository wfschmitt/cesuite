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
 * \brief  Parser implementation.
 */

#include "PreCompile.h"
#include "Core/ParserException.h"
#include "ParserImpl.h"

#include <algorithm>


using namespace Core;


std::wstring ParserImpl::ParseQuotedArgument( 
    const std::wstring& cmdline, std::wstring::size_type& index )
{
    // Step over the first quoatation mark before searching.
    std::wstring::size_type next = cmdline.find('"', ++index);

    if(next != std::wstring::npos)
    {
        std::swap(index, next);
        return cmdline.substr(next, index - next);
    }
    
    throw ParserException("Unexpected end of argument");
}


std::wstring ParserImpl::ParseSpacedArgument( 
    const std::wstring& cmdline, std::wstring::size_type& index )
{
    std::wstring::size_type next = cmdline.find(' ', index);

    std::swap(index, next);

    return next != std::wstring::npos ?
        cmdline.substr(next, index - next) : cmdline.substr(next);
}


ParserImpl::wstringlist ParserImpl::ParseComandLine( const std::wstring& cmdline ) 
{
    wstringlist list;

    for(std::wstring::size_type index = 0; index < cmdline.size(); ++index)
    {
        switch(cmdline.at(index))
        {
        case ' ' :
            break;

        case '"' :
            list.push_back(ParseQuotedArgument(cmdline, index));
            break;

        default :
            list.push_back(ParseSpacedArgument(cmdline, index));
            break;
        }
    }

    return list;
}


ParserImpl::ParserImpl( const std::wstring& cmdline )
    : m_Arguments(ParseComandLine(cmdline)) {
}


bool ParserImpl::HasArgument( const std::wstring& argument ) const 
{
    wstringlist::const_iterator it = 
        std::find(m_Arguments.begin(), m_Arguments.end(), argument);

    return it != m_Arguments.end();
}


std::wstring ParserImpl::GetArgument( std::size_t index ) const 
{
    try {
        return m_Arguments.at(index);
    }
    catch(std::range_error&) {
        throw ParserException("Atgument index out of range");
    }
}


std::size_t ParserImpl::GetArgumentCount() const {
    return m_Arguments.size();
}


std::wstring ParserImpl::GetArgumentValue( const std::wstring& argument ) const 
{
    wstringlist::const_iterator it = 
        std::find(m_Arguments.begin(), m_Arguments.end(), argument);

    if(it != m_Arguments.end() && ++it != m_Arguments.end())
        return *it;

    throw ParserException("Value for argument not found");
}
