#pragma once
#include <cstdint>
#include <Windows.h>

#include <aviutl/flag.hpp>
#include <aviutl/OutputInfo.hpp>

namespace AviUtl{
    namespace detail {
        enum class OutputPluginFlag : uint32_t {
            Video   = 1 << 0,
            Audio   = 1 << 1,
            Builtin = 1 << 20,
        };
        template<> struct flag::ops_def<OutputPluginFlag>: std::true_type {};
    }

    struct OutputPluginDLL {
        using Flag = detail::OutputPluginFlag;
        Flag flag;
        char const * name;
        char const * filefilter;
        char const * information;

        BOOL (*func_init)() = nullptr;
        BOOL (*func_exit)() = nullptr;
        BOOL (*func_output)(OutputInfo* oip);
        BOOL (*func_config)(HWND hwnd, HINSTANCE dll_hinst);
        int32_t (*func_config_get)(void* data, int32_t size);
        int32_t (*func_config_set)(void* data, int32_t size);
        int32_t reserve[16];
    };
    struct OutputPlugin {
        using Flag = detail::OutputPluginFlag;
        Flag flag;
        char const* name;
        char const* filefilter;
        char const* information;

        BOOL (*func_init)();
        BOOL (*func_exit)();
        BOOL (*func_output)(OutputInfo* oip);
        BOOL (*func_config)(HWND hwnd, HINSTANCE dll_hinst);
        int32_t (*func_config_set)(void* data, int32_t size);
        int32_t (*func_config_get)(void* data, int32_t size);
        int32_t reserve[16];
        int32_t unknown;
        char path[260];
        char name2[260];
        char filefilter2[260];
        char information2[260];
    };
}
