#pragma once
#include <cstdint>

#include <aviutl/flag.hpp>

namespace AviUtl {
    struct FrameStatus {
        int32_t video;
        int32_t audio;
        enum class Interlace : uint32_t {
            Normal  = 0,
            Reverse = 1,
            Odd     = 2,
            Even    = 3,
            Mix     = 4,
            Auto    = 5,
        } inter;
        
        [[deprecated]]
        int32_t index24fps;

        int32_t config;
        int32_t vcm;

        enum class EditFlag : uint32_t {
            KeyFrame	= 1 << 0,
            MarkFrame	= 1 << 1,
            DelFrame	= 1 << 2,
            NullFrame	= 1 << 3,
        } edit_flag;

        uint32_t reserve[9];
    };
    template<> struct detail::flag::ops_def<FrameStatus::EditFlag>: std::true_type {};
}
