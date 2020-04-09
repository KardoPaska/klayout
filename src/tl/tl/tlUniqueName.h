
/*

  KLayout Layout Viewer
  Copyright (C) 2006-2020 Matthias Koefferlein

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

*/


#ifndef HDR_tlUniqueName
#define HDR_tlUniqueName

#include "tlCommon.h"

#include <string>

namespace tl
{

/**
 *  @brief An object delivering a unique name given a set of existing names
 *
 *  If no object with the given name exists, the original name is returned.
 *  Otherwise, the unique name is built from the original name plus
 *  the separator and an integer disambiguator.
 */
template <class Set>
TL_PUBLIC_TEMPLATE std::string unique_name (const std::string &org_name, const Set &present_names, const std::string &sep = "$", int max_length = -1);

/**
 *  @brief An object delivering a unique name given a set of existing names
 *
 *  This version is identical to the "unique_name" version, but already updates the "present_names"
 *  set by adding the new name.
 */
template <class Set>
TL_PUBLIC_TEMPLATE std::string unique_name_store (const std::string &org_name, Set &present_names, const std::string &sep = "$", int max_length = -1);

} // namespace tl

#endif

