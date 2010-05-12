#include "Module.h"
#include <stdexcept>

#include <iostream>

namespace fagadget {

Module::Module (std::string name, std::string path)
{
    if (name.empty()) {
        throw std::runtime_error("What module should I load?");
    }

    if (path.empty()) {
        path.assign("modules/");
    }

    _path = path;
    _name = name;

    _library = PR_LoadLibrary(PR_GetLibraryName(_path.c_str(), _name.c_str()));

    if (_library == NULL) {
        throw std::runtime_error("Module " + _name + " not found.");
    }
}

Module::~Module (void)
{
    PR_UnloadLibrary(_library);
}

void*
Module::symbol (std::string name)
{
    return PR_FindSymbol(_library, name.c_str());
}

int
Module::initialize (int* argc, char*** argv)
{
    void* callback = this->symbol("initialize");

    if (callback == NULL) {
        throw std::runtime_error("The " + _name + " module doesn't implement initialize.");
    }

    return ((int (*)(int*, char***)) callback)(argc, argv);
}

}
