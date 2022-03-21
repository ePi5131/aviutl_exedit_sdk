#pragma once

#include <aviutl/InputPlugin.hpp>

namespace AviUtl{
    using GetInputPluginTable_t = InputPluginDLL*(__stdcall*)();
    constexpr char GetInputPluginTableName[] = "GetInputPluginTable";
}
