#pragma once
#include <cstdint>
#include <aviutl/pixel.hpp>

namespace ExEdit{
    using PixelBGR = AviUtl::PixelBGR;
    using PixelYC = AviUtl::PixelYC;

    struct PixelBGRA;
    struct PixelYCA;

    struct PixelBGRA {
        uint8_t b,g,r,a;
        PixelBGRA& operator=(const PixelBGR& bgr) { this->b=bgr.b;this->g=bgr.g;this->r=bgr.r;this->a=255;return *this; }
        constexpr operator PixelYCA() const;
    };
    struct PixelYCA {
        int16_t y,cb,cr,a;
        PixelYCA& operator=(const PixelYC& yc) { this->y=yc.y;this->cb=yc.cb;this->cr=yc.cr;this->a=4096;return *this; }
        constexpr operator PixelBGRA() const {
            return {
                 static_cast<uint8_t>((3+((y*16320)>>16)+((cb*28919)>>16)                  )>>2),
                 static_cast<uint8_t>((3+((y*16320)>>16)+((cb*-5616)>>16)+((cr*-11655)>>16))>>2),
                 static_cast<uint8_t>((3+((y*16320)>>16)+                 ((cr* 22881)>>16))>>2),
                 static_cast<uint8_t>((3+((a*16320)>>16)                                   )>>2)
            };
        }
    };

    inline constexpr PixelBGRA::operator PixelYCA() const {
        auto r_ = (r << 6) + 18;
        auto g_ = (g << 6) + 18;
        auto b_ = (b << 6) + 18;
        auto a_ = (a << 6) + 1;
        return {
            static_cast<int16_t>(((r_* 4918)>>16)+((g_* 9655)>>16)+((b_* 1875)>>16)-3),
            static_cast<int16_t>(((r_*-2775)>>16)+((g_*-5449)>>16)+((b_* 8224)>>16)+1),
            static_cast<int16_t>(((r_* 8224)>>16)+((g_*-6887)>>16)+((b_*-1337)>>16)+1),
            static_cast<int16_t>( (a_*16448)>>16                                     )
        };
    }
}
