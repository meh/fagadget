#include "Module.h"
#include <stdexcept>

namespace fagadget {

Module::Module (std::string name, std::string path)
{
    if (path.empty()) {
        path.assign("modules");
    }

    _path = path;
    _name = name;

    char* old = PR_GetLibraryPath();
    PR_SetLibraryPath(_path.c_str());

    _library = PR_LoadLibrary(name.c_str());

    PR_SetLibraryPath(old);
    PR_FreeLibraryName(old);

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
        throw std::runtime_error("The GTK module doesn't implement initialize.");
    }

    return ((int (*)(int*, char***)) callback)(argc, argv);
}

}
