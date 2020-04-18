
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


#include "tlUniqueName.h"
#include "tlString.h"

#include <set>

namespace tl
{

template <class Set>
std::string unique_name (const std::string &org_name, const Set &present_names, const std::string &sep, int max_length)
{
  if (max_length > 0 && org_name.size () > size_t (max_length)) {
    return unique_name (std::string (org_name, 0, size_t (max_length)), present_names, sep, max_length);
  }

  if (present_names.find (org_name) == present_names.end ()) {
    return org_name;
  }

  if (max_length > 0 && org_name.size () + sep.size () + 10 /*max # of chars for unsigned int*/ > size_t (max_length)) {

    //  can't use binary search in case of a potential size limit, 
    //  because we may eat a varying number of chars from the original name stem 
    
    std::string b;

    unsigned int j = 0;
    do {

      j += 1;
      tl_assert (j != 0); //  overflow check

      std::string disambiguator = sep + tl::to_string (j);
      if (max_length > 0 && org_name.size () + disambiguator.size () > size_t (max_length)) {
        tl_assert (disambiguator.size () <= size_t (max_length));
        b = std::string (org_name, 0, max_length - disambiguator.size ()) + disambiguator;
      } else {
        b = org_name + disambiguator;
      }

    } while (present_names.find (b) != present_names.end ());

    return b;

  } else {

    std::string b;

    unsigned int j = 0;
    for (unsigned int m = (unsigned int) 1 << (sizeof (unsigned int) * 8 - 2); m > 0; m >>= 1) {

      j += m;

      std::string disambiguator = sep + tl::to_string (j);
      b = org_name + disambiguator;

      if (present_names.find (b) == present_names.end ()) {
        j -= m;
      }

    }

    return org_name + sep + tl::to_string (j + 1);

  }
}

template <class Set>
std::string unique_name_store (const std::string &org_name, Set &present_names, const std::string &sep, int max_length)
{
    std::string s = unique_name (org_name, present_names, sep, max_length);
    present_names.insert (s);
    return s;
}

//  explicit instantiations
template std::string unique_name (const std::string &org_name, const std::set<std::string> &present_names, const std::string &sep, int max_length);
template std::string unique_name_store (const std::string &org_name, std::set<std::string> &present_names, const std::string &sep, int max_length);

} // namespace tl


