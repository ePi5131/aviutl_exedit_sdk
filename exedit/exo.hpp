#pragma once
#include <cstdint>

namespace ExEdit {
    struct ExoHeader {
        uint32_t flag;
        char* name;
        int32_t width;
        int32_t height;
        int32_t rate;
        int32_t scale;
        int32_t audio_rate;
        int32_t audio_ch;
    };
}
