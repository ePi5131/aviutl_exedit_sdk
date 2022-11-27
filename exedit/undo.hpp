#pragma once
#include <cstdint>
#include <cstddef>

namespace ExEdit {

#pragma warning(push)
#pragma warning(disable: 4200)
    struct UndoData {
        int32_t data_id;
        int32_t object_id;
        int32_t data_size;
        int32_t object_flag;
        int32_t object_layer_disp;
        int32_t object_frame_begin;
        int32_t object_frame_end;
        std::byte data[];
    };
#pragma warning(pop)
}
