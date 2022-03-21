#pragma once
#include <cstdint>

#include <aviutl/flag.hpp>

namespace ExEdit {
    namespace detail {
        enum class LayerFlag : uint32_t {
            UnDisp    = 1 << 0,
            Locked    = 1 << 1,
            CoordLink = 1 << 4,
            Clip      = 1 << 5
        };
    }

    struct LayerSetting {
        using Flag = detail::LayerFlag;
        Flag flag;
        const char* name;
    };
    
};

template<>struct AviUtl::detail::flag::ops_def<ExEdit::detail::LayerFlag>:std::true_type{};
