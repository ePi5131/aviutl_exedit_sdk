#pragma once
#include <Windows.h>

#include <exedit/Object.hpp>

namespace ExEdit {
    struct struct_exfunc0x04 {
        int32_t* frame_begin;
        int32_t* frame_end;
        int32_t* frame_value_left;
        int32_t* frame_value_right;
        Object::TrackMode* track_mode;
        int32_t* check_value;
        int32_t something_exdata;
        int32_t* track_param;
    };

    struct struct_exfunc0x74 {
        int32_t field_0x0;
        int32_t exedit_max_w;
        int32_t exedit_max_h;
        int32_t exedit_max_w_add_8;
        int32_t exedit_max_h_add_8;
        int32_t exedit_max_w_add_8_times_8;
        int32_t frame_n;
        int32_t framerate_nu;
        int32_t framerate_de;
        int32_t field_0x24;
        int32_t field_0x28;
    };

    struct TrackbarData {
        DWORD track_val;
        DWORD field_0x4;
        DWORD field_0x8;
        int32_t field_0xc;
        DWORD field_0x10;
        HWND field_0x14;
        HWND field_0x18;
        HWND field_0x1c;
        DWORD field_0x20;
        DWORD field_0x24;
    };

    struct CheckboxData {
        DWORD check_val;
        DWORD field_0x4;
        HWND hwnd_bt1;
        HWND hwnd_st;
        HWND hwnd_bt2;
        HWND hwnd_cb;
    };
}
