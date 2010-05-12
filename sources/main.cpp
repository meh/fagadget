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

#include <iostream>
#include <stdexcept>

#include "Utils/Options.h"
#include "Engine.h"
#include "Module.h"

using namespace fagadget;

int
main (int argc, char** argv)
{
    Utils::Options options(argc, argv);

    try {
        Engine engine(Utils::toInt(options["heap"]));
        Module module(options["toolkit"], options["modules"]);

        module.initialize(&argc, &argv);
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
