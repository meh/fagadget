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

#ifndef _FAGADGET_MODULE_H
#define _FAGADGET_MODULE_H

#include <string>
#include <prlink.h>

namespace fagadget {

class Module
{
  public:
    Module (std::string name, std::string path = "");

    virtual ~Module (void);

    void* symbol (std::string name);

    int initialize (int* argc, char*** argv);

  private:
    std::string _name;
    std::string _path;

    PRLibrary*  _library;
};

}

#endif
