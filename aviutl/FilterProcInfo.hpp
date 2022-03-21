#pragma once
#include <cstdint>

#include <aviutl/flag.hpp>
#include <aviutl/pixel.hpp>
#include <aviutl/EditHandle.hpp>

namespace AviUtl{
    struct FilterProcInfo {
        enum class Flag : uint32_t {
            InvertFieldOrder  = 1 << 16,
            InvertInterlace   = 1 << 17,
        } flag;

        void *ycp_edit, *ycp_temp;
        int32_t w, h;
        int32_t max_w, max_h;
        
        int32_t frame;
        int32_t frame_n;
        
        int32_t org_w, org_h;

        short* audiop;
        int32_t audio_n;
        int32_t audio_ch;

        [[deprecated("現在は使用されていません")]]
        PixelBGR* pixelp;
        EditHandle* editp;
        int32_t yc_size;
        int32_t line_size;
        uint32_t reserve[8];
    };

    template<> struct detail::flag::ops_def<FilterProcInfo::Flag>: std::true_type {};
}
