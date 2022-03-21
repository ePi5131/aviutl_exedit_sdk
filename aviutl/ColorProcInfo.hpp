#pragma once
#include <cstdint>
#include <Windows.h>

#include <aviutl/flag.hpp>
#include <aviutl/pixel.hpp>
#include <aviutl/MultiThreadFunc.hpp>

namespace AviUtl {
    struct ColorProcInfo {
        enum class Flag : uint32_t {
            InvertHeight = 1 << 0,
            UseSSE       = 1 << 8,
            UseSSE2      = 1 << 9,
        } flag;

        PixelYC* ycp;
        void* pixelp;
        DWORD format;
        int32_t w, h;
        int32_t line_size;
        int32_t yc_size;
        BOOL (*exec_multi_thread_func)(MultiThreadFunc func, void* param1, void* param2);

        int32_t reserve[16];
    };
    template<> struct detail::flag::ops_def<ColorProcInfo::Flag>: std::true_type {};
}
