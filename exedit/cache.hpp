#pragma once
#include <Windows.h>

namespace ExEdit {
    struct Cache {
        uint32_t global_idx;
        uint32_t w;
        uint32_t h;
        uint32_t bitcount;
        void* ptr;
        char name[260];
        uint32_t offset;
        uint32_t local_num; // Piece count
        struct Piece {
            uint32_t w; // 0x120
            uint32_t h;
            uint32_t bitcount;
            void* ptr; // maybe pointer
            char name[260];
        } piece[32];
    };
}
