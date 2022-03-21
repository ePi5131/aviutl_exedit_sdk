#pragma once
#include <cstdint>

namespace ExEdit
{
    struct BackupFileHandler{
        uint32_t version1,version2;
        int32_t frame_num;
        int32_t w,h;
        int32_t framerate_nu,framerate_de;
        int32_t audiorate;
        int32_t size;
    };
} // namespace ExEdit
