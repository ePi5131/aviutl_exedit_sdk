#pragma once
#include <cstdint>
#include <Windows.h>

namespace ExEdit {
    enum class ObjectFilterIndex : uint32_t {};
    
    inline uint16_t& object(ObjectFilterIndex& val) { return *reinterpret_cast<uint16_t*>(&val); }
    inline uint16_t& filter(ObjectFilterIndex& val) { return *(reinterpret_cast<uint16_t*>(&val) + 1); }
    inline bool is_valid(ObjectFilterIndex val) { return static_cast<uint32_t>(val) != 0; }
}
