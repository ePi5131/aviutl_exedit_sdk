#pragma once
#include <cstdint>

#include <exedit/pixel.hpp>

namespace ExEdit {
    struct ZBufferElm {
        static constexpr uint32_t distance_base = 2000000000;
        static constexpr uint32_t rotate_max = 0x4000;

        uint32_t distance;
        uint32_t rotate;
        uint32_t overlapped;
        PixelYCA color;
    };
    static_assert(sizeof(ZBufferElm) == 20U);
}
