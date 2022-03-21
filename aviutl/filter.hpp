#pragma once

#include <aviutl/FilterPlugin.hpp>

namespace AviUtl{
    using GetFilterTable_t = FilterPluginDLL*(__stdcall*)();
    constexpr char GetFilterTableName[] = "GetFilterTable";
    using GetFilterTableList_t = FilterPluginDLL**(__stdcall*)();
    constexpr char GetFilterTableListName[] = "GetFilterTableList";

    using GetFilterTableYUY2_t = FilterPluginDLL*(__stdcall*)();
    constexpr char GetFilterTableYUY2Name[] = "GetFilterTableYUY2";
    using GetFilterTableListYUY2_t = FilterPluginDLL**(__stdcall*)();
    constexpr char GetFilterTableListYUY2Name[] = "GetFilterTableListYUY2";
}
