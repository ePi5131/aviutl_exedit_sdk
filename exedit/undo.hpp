#pragma once
#include <cstdint>
#include <cstddef>

namespace ExEdit {

    struct UndoData {
        int32_t data_id;
        int32_t object_od;
        int32_t data_size;
        void* data;
    };
}
