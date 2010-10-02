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
 * \date   2010-10-01 15:46
 * \brief  CoreException definition.
 */

#if !defined(CORE_COREEXCEPTION_H)
#define CORE_COREEXCEPTION_H

#include <string>

namespace Core
{
    /*!
     * \author  Johan Andersson <skagget77@gmail.com>
     * \date    2010-10-01 15:47
     * \ingroup Core
     * \brief   CoreException class.
     */
    class CORE_API CoreException
    {
    public :
        /*!
         * Constructor.
         *
         * \param details Detailed message.
         */
        CoreException( const std::wstring& details );

        /*!
         * Destructor.
         */
        virtual ~CoreException();

        /*!
         * Returns the detailed message describing the exception.
         * 
         * \return Detailed message.
         */
        std::wstring GetDetails() const;

    private :
        std::wstring m_Details;
    };
}

#endif  // CORE_COREEXCEPTION_H
