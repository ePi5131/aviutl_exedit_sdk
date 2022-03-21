#pragma once
#include <cstdint>
#include <cstddef>

namespace ExEdit {

#pragma warning(push)
#pragma warning(disable: 4200)
    struct UndoData {
        int32_t data_id;
        int32_t object_od;
        int32_t data_size;
        std::byte data[];
    };
#pragma warning(pop)
}
