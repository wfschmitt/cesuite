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
#include "OptionFinder.h"
#include "ParserImpl.h"

#include <algorithm>


using namespace Core;


ParserImpl::ParserImpl( const std::wstring& cmdLine, bool caseInsensitive )
    : m_Options(ParseComandLine(cmdLine)), m_CaseInsensitive(caseInsensitive) {
}


bool ParserImpl::HasOption( const std::wstring& option ) const 
{
    wstringlist::const_iterator it = 
        std::find_if(m_Options.begin(), m_Options.end(), 
            OptionFinder(option, m_CaseInsensitive));

    return it != m_Options.end();
}


std::wstring ParserImpl::GetOption( std::size_t index ) const 
{
    if(index < m_Options.size())
        return m_Options.at(index);

    throw ParserException(L"Index out of range");
}


std::size_t ParserImpl::GetOptionCount() const {
    return m_Options.size();
}


std::wstring ParserImpl::GetValue( const std::wstring& option ) const 
{
    wstringlist::const_iterator it = 
        std::find_if(m_Options.begin(), m_Options.end(), 
            OptionFinder(option, m_CaseInsensitive));

    if(it != m_Options.end() && ++it != m_Options.end())
        return *it;

    throw ParserException(L"Value not found");
}


std::wstring ParserImpl::GetValue( 
    const std::wstring& option, const std::wstring& defValue ) const
{
    return HasOption(option) ? GetValue(option) : defValue;
}


std::wstring ParserImpl::ParseQuotedOption( 
    const std::wstring& cmdLine, std::wstring::size_type& index )
{
    // Step over the first quoatation mark before searching.
    std::wstring::size_type next = cmdLine.find('"', ++index);

    if(next != std::wstring::npos)
    {
        std::swap(index, next);
        return cmdLine.substr(next, index - next);
    }

    throw ParserException(L"Unexpected end of option");
}


std::wstring ParserImpl::ParseSpacedOption( 
    const std::wstring& cmdLine, std::wstring::size_type& index )
{
    std::wstring::size_type next = cmdLine.find(' ', index);

    if(next == std::wstring::npos)
        next = cmdLine.size();

    std::swap(index, next);

    return cmdLine.substr(next, index - next);
}


ParserImpl::wstringlist ParserImpl::ParseComandLine( const std::wstring& cmdLine ) 
{
    wstringlist list;

    for(std::wstring::size_type index = 0; index < cmdLine.size(); ++index)
    {
        switch(cmdLine.at(index))
        {
        case ' ' :
            break;

        case '"' :
            list.push_back(ParseQuotedOption(cmdLine, index));
            break;

        default :
            list.push_back(ParseSpacedOption(cmdLine, index));
            break;
        }
    }

    return list;
}
