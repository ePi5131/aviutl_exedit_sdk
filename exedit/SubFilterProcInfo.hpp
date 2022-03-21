#pragma once
#include <cstdint>

namespace ExEdit {
    struct SubFilterProcInfo {
        int32_t flag; // 0x100 アルファ有無
        void* buf_edit;
        void* buf_temp;
        int32_t w, h;
        int32_t max_w, max_h;
        int32_t frame, frame_n;
        int32_t org_w, org_h;
        int32_t audiop;
        int32_t audio_n, audio_ch;
        int32_t pixelp;
        int32_t editp;
        int32_t yc_size;
        int32_t line_size;
        int32_t reserve[8];
    };
}
