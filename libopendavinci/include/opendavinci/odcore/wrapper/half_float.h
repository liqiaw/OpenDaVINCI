/**
 * OpenDaVINCI - Portable middleware for distributed components.
 * Copyright (C) 2015 Christian Berger
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef OPENDAVINCI_CORE_WRAPPER_HALF_FLOAT_H_
#define OPENDAVINCI_CORE_WRAPPER_HALF_FLOAT_H_

// Disable the warning level for the Eigen headers..

#ifndef WIN32
# if !defined(__OpenBSD__) && !defined(__NetBSD__)
#  pragma GCC diagnostic push
# endif
# pragma GCC diagnostic ignored "-Weffc++"
# pragma GCC diagnostic ignored "-Wshadow"
# pragma GCC diagnostic ignored "-Wlong-long"

//# if ((__GNUC__ * 100) + __GNUC_MINOR__) >= 600
//#  pragma GCC diagnostic ignored "-Wignored-attributes"
//#  pragma GCC diagnostic ignored "-Wmisleading-indentation"
//# endif
#endif

    #include "opendavinci/half.hpp"

#ifndef WIN32
# if !defined(__OpenBSD__) && !defined(__NetBSD__)
#  pragma GCC diagnostic pop
# endif
#endif

using namespace half_float;

#endif // OPENDAVINCI_CORE_WRAPPER_EIGEN_H_
