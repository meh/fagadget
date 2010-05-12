/*
* Copyleft The Authors
*
* This file is part of fagadget.
*
* fagadget is free software: you can redistribute it and/or modify
* it under the terms of the GNU Affero General Public License as published
* by the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* fagadget is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Affero General Public License for more details.
*
* You should have received a copy of the GNU Affero General Public License
* along with fagadget. If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _FAGADGET_UTILS_OPTIONS_H
#define _FAGADGET_UTILS_OPTIONS_H

#include "Utils.h"

#include <map>
#include <string>

namespace fagadget {

namespace Utils {

class Options
{
  public:
    Options (int argc, char** argv);

    std::string& operator [] (std::string name);

  private:
    std::map<std::string, std::string> _options;
};

}

}

#endif
