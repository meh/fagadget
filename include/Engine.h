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

#ifndef _FAGADGET_ENGINE_H
#define _FAGADGET_ENGINE_H

#include <jsapi.h>

namespace fagadget {

class Engine
{
  public:
    Engine (unsigned long long size = 8L * 1024L * 1024);

    virtual ~Engine (void);

    bool execute (const char* script);

  private:
    JSRuntime* _runtime;
};

}

#endif
