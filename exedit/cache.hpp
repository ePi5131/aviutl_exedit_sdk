#pragma once
#include <Windows.h>

namespace ExEdit {
    struct CacheDataInfo { // size = 276
        uint32_t w;
        uint32_t h;
        uint32_t bitcount;
        void* ptr;
        char name[260];
    };
    struct CacheInfo { // size = 9120
        uint32_t priority;
        CacheDataInfo main;
        uint32_t offset;
        uint32_t sub_num;
        CacheDataInfo sub[32];
    };
}
