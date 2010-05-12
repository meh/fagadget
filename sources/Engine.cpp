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

#include "Engine.h"

namespace fagadget {

Engine::Engine (unsigned long long size)
{
    _runtime = JS_NewRuntime(size);
}

Engine::~Engine (void)
{
    JS_DestroyRuntime(_runtime);
}

bool
Engine::execute (const char* script)
{
    return false;
}

}
