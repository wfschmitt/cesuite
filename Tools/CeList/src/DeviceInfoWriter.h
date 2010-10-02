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
 * \date   2010-10-02 23:22
 * \brief  DeviceInfoWriter functor.
 */

#if !defined(CELIST_DEVICEINFOWRITER_H)
#define CELIST_DEVICEINFOWRITER_H

#include <iostream>

namespace CeList
{
    /*!
     * \author  Johan Andersson <skagget77@gmail.com>
     * \date    2010-10-02 23:25
     * \ingroup CeList
     * \brief   DeviceInfoWriter class.
     */
    class DeviceInfoWriter
    {
    public :
        /*!
         * Constructor.
         *
         * \param out Output stream.
         */
        DeviceInfoWriter( std::wostream& out )
            : m_Out(out) {
        }

        /*!
         * Functor function operator, writes information about a remote device.
         *
         * \param device Device to write information about. 
         */
        void operator()( Remote::IDevicePtr device ) const
        {
            m_Out << device->GetId() << std::endl
                << device->GetName() << std::endl
                << device->GetPlatform() << std::endl
                << device->GetVersion() << std::endl;
        }

    private :
        DeviceInfoWriter& operator=( const DeviceInfoWriter& );
        std::wostream& m_Out;
    };
}

#endif  /* CELIST_DEVICEINFOWRITER_H */
