#pragma once
#include <cstdint>

#include <aviutl/AviFileHandle.hpp>
#include <aviutl/FileInfo.hpp>
namespace ExEdit {

    // exedit92 + 0x0d4748 array[32]
    struct AviFileHandleInfo {
        AviUtl::AviFileHandle* afh;
        int32_t id_and_count;
        int32_t tickcount;
        int32_t priority;
        int32_t flag;
        AviUtl::FileInfo fi;
        char path[260];
    };
} // namespace ExEdit