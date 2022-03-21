#pragma once

#include <aviutl/ColorPlugin.hpp>

namespace AviUtl {
    using GetColorPluginTable_t = ColorPluginDLL*(__stdcall*)();
    const char GetColorTableName[] = "GetColorPluginTable";

    using GetColorPluginTableYUY2_t = ColorPluginDLL*(__stdcall*)();
    const char GetColorTableYUY2Name[] = "GetColorPluginTableYUY2";
}
