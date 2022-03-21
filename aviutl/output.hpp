#pragma once

#include <aviutl/OutputInfo.hpp>
#include <aviutl/OutputPlugin.hpp>

namespace AviUtl{
    using GetOutputPluginTable_t = OutputPluginDLL*(__stdcall*)();
    constexpr char GetOutputPluginTableName[] = "GetOutputPluginTable";
}
