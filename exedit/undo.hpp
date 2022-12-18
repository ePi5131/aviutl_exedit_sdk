#pragma once
#include <cstdint>
#include <cstddef>

namespace ExEdit {

    struct UndoData {
        int32_t data_id;
        int32_t object_id;
        int32_t data_size;
        int32_t object_flag_opt;
        int32_t object_layer_disp_opt;
        int32_t object_frame_begin_opt;
        int32_t object_frame_end_opt;
        std::byte data[1];
    };
}
