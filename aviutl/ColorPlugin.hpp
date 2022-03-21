#pragma once
#include <cstdint>
#include <Windows.h>

#include <aviutl/flag.hpp>
#include <aviutl/ColorProcInfo.hpp>

namespace AviUtl {
    namespace detail {
        enum class ColorPluginFlag : uint32_t {
            None = 0,
            Builtin = 1 << 28,
        };
    }

    struct ColorPlugin {
        using Flag = detail::ColorPluginFlag;
        Flag flag;
        const char* name;
        const char* information;
        BOOL (*func_init)();
        BOOL (*func_exit)();
        BOOL (*func_pixel2yc)(ColorProcInfo* cpip);
        BOOL (*func_yc2pixel)(ColorProcInfo* cpip);

        int reserve[16];

        HMODULE dll_hinst;
        char path[260];
    };

    struct ColorPluginDLL {
        using Flag = detail::ColorPluginFlag;
        Flag flag;
        const char* name;
        const char* information;
        BOOL (*func_init)(); 
        BOOL (*func_exit)();
        
        BOOL (*func_pixel2yc)(ColorProcInfo* cpip);

        BOOL (*func_yc2pixel)(ColorProcInfo* cpip);

        uint32_t reserve[16];
    };
    template<> struct detail::flag::ops_def<detail::ColorPluginFlag>: std::true_type {};
}
