#pragma once

#include <Windows.h>

namespace ExEdit {
    namespace CommandId {
        inline static constexpr const DWORD FRAME_MOVE_BEGIN    = 1102; // ICON_LL
        inline static constexpr const DWORD FRAME_MOVE_END      = 1103; // ICON_RR

        inline static constexpr const DWORD FILTER_INIT         = 1105;

        inline static constexpr const DWORD FILTER_SET_DEFVALUE = 1108;
        inline static constexpr const DWORD FILTER_MAKE_ALIAS   = 1109;

        inline static constexpr const DWORD FILTER_MOVEUP       = 1116;
        inline static constexpr const DWORD FILTER_MOVEDOWN     = 1117;
        
        inline static constexpr const DWORD id1106              = 1106;
        inline static constexpr const DWORD id1107     = 1107; // ICON_PL

        inline static constexpr const DWORD id1115     = 1115; // ICON_CH
        
        inline static constexpr const DWORD id1120     = 1120; // ICON_CA0
        inline static constexpr const DWORD id1121     = 1121; // ICON_CL0

        inline static constexpr const DWORD FILTER_DELETE       = 4300;

        inline static constexpr const DWORD FILTER_VALIDATE     = 4400;

        inline static constexpr const DWORD FILTER_FOLD         = 4500;


    }
}
