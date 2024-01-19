#pragma once
#include <cstdint>
#include <Windows.h>

#include <aviutl/flag.hpp>
#include <aviutl/filter.hpp>
#include <exedit/ObjectFilterIndex.hpp>
#include <exedit/exdata.hpp>

namespace ExEdit {
    struct Exfunc;
    struct FilterProcInfo;
    struct Object;
    struct Filter {
        enum class Flag : uint32_t {
            Input        = 1 << 3,
            Output       = 1 << 4,
            Effect       = 1 << 5,
            Unputable    = 1 << 7, // タイムライン配置メニューには出てこない
            Unaddable    = 1 << 8, // タイムライン配置メニューにのみ出現、エフェクト追加メニューには出てこない
            Unknown1     = 1 << 9, // これを外すとマスク、ディスプレイスメントマップでシーンが使えなくなる。拡張色設定で色が変化しなくなる。
            HasExdata    = 1 << 10,
            BasicEffect  = 1 << 15,
            Audio        = 1 << 21,
            Control      = 1 << 24,
            ExEditFilter = 1 << 26,

            Unknown3     = 1 << 30,
        } flag;
        int32_t x, y;
        const char* name;

        int32_t track_n;
        char** track_name;
        int32_t* track_default;  // -1:ボタン化 -2:ドロップダウンリスト化
        int32_t *track_s, *track_e;
        
        int32_t check_n;
        char** check_name;
        int32_t* check_default;

        BOOL(*func_proc)(Filter* efp, FilterProcInfo* efpip);
        BOOL(*func_init)(Filter* efp);
        BOOL(*func_exit)(Filter* efp);
        BOOL(*func_update)(Filter* efp, int32_t status);
        BOOL(*func_WndProc)(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam, AviUtl::EditHandle* editp, Filter* efp);
        
        int32_t* track;
        int32_t* check;
        void* exdata_ptr;
        int32_t exdata_size;
        char* information;
        int(*func_window_init)(HINSTANCE hinstance, HWND hwnd, int32_t y, int32_t base_id, int32_t sw_param, Filter* efp);
        BOOL(*func_window_hide)(); // save_end
        AviUtl::ExFunc* aviutl_exfunc;
        Exfunc* exfunc;
        void* dll_hinst;
        void* exdata_def;

        using ExdataUse = ExdataUse;
        const ExdataUse* exdata_use;
        struct TrackExtra {
            int32_t* track_scale;
            int32_t* track_link;
            int32_t* track_drag_min;
            int32_t* track_drag_max;
        }*track_extra;
        struct TrackGuiIdx {
            static const int32_t invalid = -1;

            int32_t bx, by, bz;
            int32_t rx, ry, rz;
            int32_t cx, cy, cz;
            int32_t zoom;
            int32_t aspect;
            int32_t alpha;
        }*track_gui;
        int32_t unknown;
        char* unknown_str;
        int32_t unknown3[18];
        int32_t* track_scale;
        int32_t* track_link;
        int32_t* track_drag_min;
        int32_t* track_drag_max;
        AviUtl::FilterPlugin* exedit_fp;
        Object* objectp;
        ObjectFilterIndex processing;
        ObjectFilterIndex objdlg;
        int32_t frame_start;
        int32_t frame_end;
        int32_t* track_value_left;
        int32_t* track_value_right;
        int32_t* track_mode;
        int32_t* check_value;
        void* exdata2;
        int32_t* track_param;
        int32_t unknown2[3];
        int32_t frame_start_chain;
        int32_t frame_end_chain;
        int32_t layer_set;
        int32_t scene_set;
    };
}
template<> struct AviUtl::detail::flag::ops_def<ExEdit::Filter::Flag> : std::true_type {};
