#pragma once
#include <cstdint>
#include <Windows.h>

namespace AviUtl {
    struct LangResources {
        HMODULE hmodule;
        int32_t param;
        char name[256];
        char path[256];
        char information[256];
    };
}
