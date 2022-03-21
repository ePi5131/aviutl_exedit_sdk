#pragma once
#include <cstdint>

namespace AviUtl{
    struct PixelBGR {
        uint8_t b,g,r;
    };

    struct PixelYC {
        int16_t y,cb,cr;
    };
}
