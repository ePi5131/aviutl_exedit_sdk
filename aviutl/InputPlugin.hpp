#pragma once
#include <cstdint>
#include <Windows.h>

#include <aviutl/InputInfo.hpp>
#include <aviutl/InputHandle.hpp>

namespace AviUtl{
    namespace detail {
        enum class InputPluginFlag : uint32_t {
            Video     = 1 << 0,
            Audio     = 1 << 1,
            HasConfig = 1 << 8,
            Builtin   = 1 << 20,
            VFPlugin  = 1 << 22,
        };
        template<> struct flag::ops_def<InputPluginFlag>: std::true_type {};
    }

    struct InputPluginDLL {
        using Flag = detail::InputPluginFlag;

        Flag flag;
        const char* name;
        const char* filefilter;
        const char* information;
        BOOL (*func_init)();
        BOOL (*func_exit)();
        InputHandle (*func_open)(const char* file);
        BOOL (*func_close)(InputHandle ih);
        BOOL (*func_info_get)(InputHandle ih, InputInfo* iip);
        int32_t (*func_read_video)(InputHandle ih, int32_t frame, void* buf);
        int32_t (*func_read_audio)(InputHandle ih, int32_t start, int32_t length, void* buf);
        BOOL (*func_is_keyframe)(InputHandle ih, int32_t frame);
        BOOL (*func_config)(HWND hwnd, HINSTANCE dll_hinst);
        int32_t reserve[16];
    };
    
    struct InputPlugin {
        using Flag = detail::InputPluginFlag;

        Flag flag;
        const char* name;
        const char* filefilter;
        const char* information;
        BOOL (*func_init)();
        BOOL (*func_exit)();
        InputHandle (*func_open)(const char* file);
        BOOL (*func_close)(InputHandle ih);
        BOOL (*func_info_get)(InputHandle ih, InputInfo* iip);
        int32_t (*func_read_video)(InputHandle ih, int32_t frame, void* buf);
        int32_t (*func_read_audio)(InputHandle ih, int32_t start, int32_t length, void* buf);
        BOOL (*func_is_keyframe)(InputHandle ih, int32_t frame);
        BOOL (*func_config)(HWND hwnd, HINSTANCE dll_hinst);
        int32_t reserve[16];
        char path[260];
        char name2[256];
        char filefilter2[256];
        char information2[256];
        HMODULE hmodule;
        int32_t ref_count;
        int32_t index;
        int32_t unknown1;
        int32_t unknown2;
        FARPROC proc;
        int32_t unknown3[3];
    };
}
