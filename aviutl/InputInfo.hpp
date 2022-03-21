#pragma once
#include <cstdint>
#include <Windows.h>

#include <aviutl/flag.hpp>

namespace AviUtl{
    struct InputInfo{
        enum class Flag : uint32_t {
            Video = 1 << 0,
            Audio = 1 << 1,
            VideoRandomAccess = 1 << 3,
        } flag;
        
        int32_t rate,scale;
        int32_t n;
        BITMAPINFOHEADER* format;
        int32_t format_size;
        int32_t audio_n;
        WAVEFORMATEX* audio_format;
        int32_t audio_format_size;
        DWORD handler;

        int32_t reserve[7];
    };
    template<> struct detail::flag::ops_def<InputInfo::Flag>: std::true_type {};
}
