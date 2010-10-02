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
 * \date   2010-10-02 22:16
 * \brief  OptionFinder functor.
 */

#if !defined(CORE_OPTIONFINDER_H)
#define CORE_OPTIONFINDER_H

#include <algorithm>
#include <cctype>

namespace Core
{
    /*!
     * \author  Johan Andersson <skagget77@gmail.com>
     * \date    2010-10-02 22:18
     * \ingroup Core
     * \brief   OptionFinder class.
     */
    class OptionFinder
    {
    public :
        /*!
         * Constructor.
         *
         * \param option Option to find.
         * \param caseInsensitive Tells whether finder should be case
         *        insensitive or not.
         */
        OptionFinder( const std::wstring& option, bool caseInsensitive )
            : m_Option(option), m_CaseInsensitive(caseInsensitive) 
        {
            if(m_CaseInsensitive)
                std::transform(m_Option.begin(), m_Option.end(), m_Option.begin(),
                    std::toupper);
        }

        /*!
         * Functor function operator, compares this option against the
         * specified option.
         *
         * \param  option Option to test equality against.
         * \return True if the two options are equal, false otherwise.
         */
        bool operator()( std::wstring option ) const
        {
            if(m_CaseInsensitive)
                std::transform(option.begin(), option.end(), option.begin(),
                    std::toupper);

            return option == m_Option;
        }

    private :
        std::wstring m_Option;
        bool m_CaseInsensitive;
    };
}

#endif  /* CORE_OPTIONFINDER_H */
