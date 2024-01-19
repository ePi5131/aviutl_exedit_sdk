#pragma once
#include <cstdint>
#include <Windows.h>

#include <aviutl/flag.hpp>
#include <aviutl/EditHandle.hpp>
#include <aviutl/FilterProcInfo.hpp>
#include <aviutl/Exfunc.hpp>

namespace AviUtl{
    namespace detail{
        enum class FilterPluginFlag : uint32_t {
            Active           = 1 << 0,
            WindowActive     = 1 << 1,  // フィルタの設定ウィンドウが表示されている時 ON になる.
            AlwaysActive     = 1 << 2,
            ConfigPopup      = 1 << 3,
            ConfigCheck      = 1 << 4,
            ConfigRadio      = 1 << 5,
            Unknown          = 1 << 8,  // 42416a
            Exdata           = 1 << 10,
            PriorityHighest  = 1 << 11,
            PriorityLowest   = 1 << 12,
            WindowThickFrame = 1 << 13,
            WindowSize       = 1 << 14,
            DispFilter       = 1 << 15,
            MultiFilter      = 1 << 16, // 1つのファイルで複数のフィルタを登録するとき,2つ目以降のFilterPluginに設定される.
            Redraw           = 1 << 17,
            ExInformation    = 1 << 18,
            Information      = 1 << 19,
            NoConfig         = 1 << 20,
            AudioFilter      = 1 << 21,
            RadioButton      = 1 << 22,
            WindowHScrool    = 1 << 23,
            WindowVScrool    = 1 << 24,
            Builtin          = 1 << 25, // AviUtl 本体に組み込まれているフィルタなら ON になっている.
            InterlaceFilter  = 1 << 26,
            NoInitData       = 1 << 27,
            Import           = 1 << 28,
            Export           = 1 << 29,
            MainMessage      = 1 << 30,
        };
        template<>struct detail::flag::ops_def<FilterPluginFlag>:std::true_type{};

        enum class FilterPluginUpdateStatus : uint32_t {
            All   = 0,
            Track = 1 << 16,
            Check = 1 << 17,
        };
        template<>struct detail::flag::ops_def<FilterPluginUpdateStatus>:std::true_type{};

        // 変更されたトラックバー/チェックボックスのインデックスを返す
        // 全項目が変更された場合は0
        inline constexpr int32_t get_updated_idx(FilterPluginUpdateStatus status) {
            constexpr auto mask = ~(FilterPluginUpdateStatus::Track | FilterPluginUpdateStatus::Check);
            return static_cast<int32_t>(status & mask);
        }

        struct FilterPluginWindowMessage {
            constexpr static inline UINT Update          = WM_USER + 100; // 464H 1124
            constexpr static inline UINT FileOpen        = WM_USER + 101; // 465H 1125
            constexpr static inline UINT FileClose       = WM_USER + 102; // 466H 1126
            constexpr static inline UINT Init            = WM_USER + 103; // 467H 1127
            constexpr static inline UINT Exit            = WM_USER + 104; // 468H 1128
            constexpr static inline UINT SaveStart       = WM_USER + 105; // 469H 1129
            constexpr static inline UINT SaveEnd         = WM_USER + 106; // 46AH 1130
            constexpr static inline UINT Import          = WM_USER + 107; // 46BH 1131
            constexpr static inline UINT Export          = WM_USER + 108; // 46CH 1132
            constexpr static inline UINT ChangeActive    = WM_USER + 109; // 46DH 1133
            constexpr static inline UINT ChangeWindow    = WM_USER + 110; // 46EH 1134
            constexpr static inline UINT ChangeParam     = WM_USER + 111; // 46FH 1135
            constexpr static inline UINT ChangeEdit      = WM_USER + 112; // 470H 1136
            constexpr static inline UINT Command         = WM_USER + 113; // 471H 1137
            constexpr static inline UINT FileUpdate      = WM_USER + 114; // 472H 1138
            
            constexpr static inline UINT MainMouseDown   = WM_USER + 120; // 478H 1144
            constexpr static inline UINT MainMouseUp     = WM_USER + 121; // 479H 1145
            constexpr static inline UINT MainMouseMove   = WM_USER + 122; // 47AH 1146
            constexpr static inline UINT MainKeyDown     = WM_USER + 123; // 47BH 1147
            constexpr static inline UINT MainKeyUp       = WM_USER + 124; // 47CH 1148
            constexpr static inline UINT MainMoveSize    = WM_USER + 125; // 47DH 1149
            constexpr static inline UINT MainMouseDblclk = WM_USER + 126; // 47EH 1150
            constexpr static inline UINT MainMouseRDown  = WM_USER + 127; // 47FH 1151
            constexpr static inline UINT MainMouseRUp    = WM_USER + 128; // 480H 1152
            constexpr static inline UINT MainMouseWheel  = WM_USER + 129; // 481H 1153
            constexpr static inline UINT MainContextMenu = WM_USER + 130; // 482H 1154
        };
    }

    struct FilterPlugin;

    struct FilterPluginDLL {
        using Flag = detail::FilterPluginFlag;
        using UpdateStatus = detail::FilterPluginUpdateStatus;
        using WindowMessage = detail::FilterPluginWindowMessage;

        Flag flag;
        
        static const int32_t WindowSizeClient	= 0x10000000;
        static const int32_t WindowSizeAdd		= 0x30000000;
        
        int32_t x, y;

        const char* name;

        int32_t track_n;
        const char** track_name;
        int32_t* track_default;
        int32_t *track_s, *track_e;
        
        int32_t check_n;
        const char** check_name;
        int32_t* check_default;

        BOOL (*func_proc)(FilterPlugin* fp, FilterProcInfo* fpip);
        BOOL (*func_init)(FilterPlugin* fp);
        BOOL (*func_exit)(FilterPlugin* fp);
        BOOL (*func_update)(FilterPlugin* fp, UpdateStatus status);

        // check_defaultに-1を指定してボタンにした際,n番目のボタン(配列上の位置ではない 1-indexed)が押されたときに
        // msg に WM_COMMAND, wparam に MidFilterButton+n-1 がfunc_WndProcへ渡される.
        static const int32_t MidFilterButton = 12004;

        BOOL (*func_WndProc)(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam, EditHandle* editp, FilterPlugin* fp);

        int32_t* track;
        int32_t* check;

        void* ex_data_ptr;
        int32_t ex_data_size;

        const char* information;

        BOOL (*func_save_start)(FilterPlugin* fp, int32_t s, int32_t e, EditHandle* editp);

        BOOL (*func_save_end)(FilterPlugin* fp, EditHandle* editp);

        ExFunc* exfunc;
        HWND hwnd;
        HINSTANCE dll_hinst;

        void* ex_data_def;

        BOOL(*func_is_saveframe)(FilterPlugin* fp, EditHandle* editp, int32_t saveno, int32_t frame, int32_t fps, int32_t edit_flag, int32_t inter);
        
        BOOL(*func_project_load)(FilterPlugin* fp, EditHandle* editp, void* data, int32_t size);

        BOOL(*func_project_save)(FilterPlugin* fp, EditHandle* editp, void* data, int32_t* size);

        BOOL(*func_modify_title)(FilterPlugin* fp, EditHandle* editp, int32_t frame, LPSTR title, int32_t max_title);
        
        char* path;

        int32_t reserve[2];
    };

    struct FilterPlugin {
        using Flag = detail::FilterPluginFlag;
        using UpdateStatus = detail::FilterPluginUpdateStatus;
        using WindowMessage = detail::FilterPluginWindowMessage;

        Flag flag;
        int32_t x, y;
        const char* name;
        int32_t track_n;
        const char** track_name;
        int32_t* track_default;
        int32_t *track_s, *track_e;
        int32_t check_n;
        const char** check_name;
        int32_t* check_default;
        BOOL (*func_proc)(FilterPlugin* fp, FilterProcInfo* fpip);
        BOOL (*func_init)(FilterPlugin* fp);
        BOOL (*func_exit)(FilterPlugin* fp);
        BOOL (*func_update)(FilterPlugin* fp, UpdateStatus status);
        static const int32_t MidFilterButton = 12004;
        BOOL (*func_WndProc)(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam, EditHandle* editp, FilterPlugin* fp);
        int32_t* track;
        int32_t* check;
        void* ex_data_ptr;
        int32_t ex_data_size;
        const char* information;
        BOOL (*func_save_start)(FilterPlugin* fp, int32_t s, int32_t e, EditHandle* editp);
        BOOL (*func_save_end)(FilterPlugin* fp, EditHandle* editp);
        ExFunc* exfunc;
        HWND hwnd;
        HINSTANCE dll_hinst;
        void* ex_data_def;
        BOOL(*func_is_saveframe)(FilterPlugin* fp, EditHandle* editp, int32_t saveno, int32_t frame, int32_t fps, int32_t edit_flag, int32_t inter);
        BOOL(*func_project_load)(FilterPlugin* fp, EditHandle* editp, void* data, int32_t size);
        BOOL(*func_project_save)(FilterPlugin* fp, EditHandle* editp, void* data, int32_t* size);
        BOOL(*func_modify_title)(FilterPlugin* fp, EditHandle* editp, int32_t frame, LPSTR title, int32_t max_title);
        struct{
            char path[260];
            HMENU menu1;
            HMENU menu2;
        } *path;
        int32_t reserve[2];
        int32_t menu_index;
        HWND hwnd_parent;
        HWND unknown_hwnd;
        HWND track_trackbar_hwnd[32];
        HWND track_edit_hwnd[32];
        HWND track_aviutlbutton1_hwnd[32];
        HWND track_aviutlbutton2_hwnd[32];
        HWND track_static_hwnd[32];
        HWND check_hwnd[32];
        int32_t track_array[32];
        int32_t check_array[32];
        HMENU hmenu;
        int32_t unknown;
        HINSTANCE hinst_parent;
        PixelYC* cache_edit;
        PixelYC* cache_temp;
        void* cache_ptr;
        int32_t cache_w, cache_h;
        int32_t cache_d;
        int32_t cache_flag;
        DWORD mode_yuy2;

        inline static constexpr int32_t get_updated_idx(UpdateStatus status) {
            return detail::get_updated_idx(status);
        }
    };
}
