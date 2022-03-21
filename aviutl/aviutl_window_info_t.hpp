#pragma once
#include <cstdint>
#include <Windows.h>

#include "flag.hpp"

namespace AviUtl {

    struct aviutl_window_info_t {
        enum class Flag {
            AudioWave       = 1 <<  3,
            Preview         = 1 <<  4, // 0x2391
            DeleteFrame     = 1 <<  5, // 0x2392
            Overray         = 1 <<  9, // 0x2397
            AlwaysTop       = 1 << 11, // 0x2399 HWND_NOTOPMOST / HWND_TOPMOST
            AviKeyframe     = 1 << 12, // 0x2395
            RecompressFrame = 1 << 13, // 0x2396
            Time            = 1 << 14, // 0x239a
            Nofilter        = 1 << 15, // 0x1418
            DataRate        = 1 << 16, // 0x239b
            SizeAuto        = 1 << 19, // 0x239c
        } flag;
        int32_t x, y, w, h;
        int32_t zoom;
        HWND main_window;
        HWND time_trackbar;
        HWND back;
        HWND forward;
        HWND in;
        HWND out;
        HWND hwnd1;
        int32_t x2, y2, w2, h2;
        HWND hwnd2;
        HWND hwnd3;
        HWND play;
    };
    template<>struct detail::flag::ops_def<aviutl_window_info_t::Flag>:std::true_type{};
}
