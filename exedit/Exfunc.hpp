#pragma once
#include <cstdint>

#include <aviutl/pixel.hpp>
#include <exedit/ObjectFilterIndex.hpp>
#include <exedit/Filter.hpp>
#include <exedit/FilterProcInfo.hpp>
#include <exedit/pixel.hpp>

namespace ExEdit {
    struct Exfunc {
        void (*x00)(ObjectFilterIndex idx);
        BOOL (*getvalue)(ObjectFilterIndex idx, void* struct_ptr);
        ObjectFilterIndex (*x08)(ObjectFilterIndex idx);
        ObjectFilterIndex (*x0c)(ObjectFilterIndex idx);
        ObjectFilterIndex (*get_start_idx)(ObjectFilterIndex idx);
        ObjectFilterIndex (*x14)(ObjectFilterIndex idx);
        int32_t (*count_section_num)(ObjectFilterIndex idx);
        ObjectFilterIndex (*x1c)(int32_t frame, int32_t layer, int32_t scene, const char* filter_name, int32_t flag);
        ObjectFilterIndex (*x20)(ObjectFilterIndex idx, LPCSTR str, int32_t flag);
        void (*x24)(uint32_t, int32_t, int32_t, int32_t, int32_t, int16_t, int16_t, int16_t, int16_t, int32_t, int32_t);
        void (*x28)(int32_t, int32_t, int32_t, int32_t, int16_t, int16_t, int16_t, int16_t, uint32_t);
        void (*x2c)(uint32_t, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, int16_t, int16_t, int16_t, int16_t, uint32_t, int32_t);
        void (*x30)(int32_t x, int32_t y, int32_t z, int32_t tx, int32_t ty, int32_t tz, int32_t rz, int32_t, int32_t ux1, int32_t ux2, int32_t uy1, int32_t uy2, int32_t uz1, int32_t uz2);
        int32_t (*draw)(void* dst, int32_t ox, int32_t oy, int32_t oz, int32_t rx, int32_t ry, int32_t rz, int32_t zoom, int32_t aspect, int32_t alpha, void* src, int32_t src_w, int32_t src_h, int32_t w, int32_t h, int32_t w_times2048, int32_t h_times2048, int32_t, uint32_t flag, FilterProcInfo::PolyData* polydata);
        int32_t (*load_image)(PixelYCA* buf, char* path, int32_t* w, int32_t* h, int32_t, uint32_t);
        char* (*get_loadable_image_extension)();
        void (*x40)(void* dst, uint32_t, int32_t, wchar_t* text, AviUtl::PixelBGR col1, AviUtl::PixelBGR col2, int32_t, HFONT hfont, int32_t* w, int32_t* h, int32_t type, int32_t speed, int32_t align, int32_t*, int32_t flag);
        BOOL (*bufcpy)(void* dst, int32_t dst_w, int32_t dst_h, void* src, int32_t src_w, int32_t src_h, int32_t w, int32_t h, int32_t alpha, int32_t flag);
        uint32_t (*fill)(void* ycp, int32_t wo, int32_t ho, int32_t w, int32_t h, int16_t y, int16_t cb, int16_t cr, int16_t a, int32_t flag);        
        HWND (*get_hwnd)(ObjectFilterIndex idx, int32_t type, int32_t idx2);
        BOOL (*x50)(ObjectFilterIndex idx, int32_t, int32_t, int32_t framex100, int32_t);
        BOOL (*rename_object)(ObjectFilterIndex idx, char* name);
        void (*x58)(void* dst, int32_t* array, int32_t n, void* obj, int32_t, int32_t flag);
        void (*yc2rgb)(void *dst, void *src, int32_t w, int32_t h, int32_t pixelsize, int32_t linesize);
        int32_t unused;
        BOOL (*calc_trackbar)(ObjectFilterIndex idx, int32_t frame, int32_t subframe, int32_t* result, char* name); //name は256未満の正数を入れても良い その場合は直接インデックス指定
        BOOL (*x68)(ObjectFilterIndex idx, int32_t);
        BOOL (*x6c)(Filter* efp, void* pixel, uint32_t flag);
        uint32_t (*get_object_length)(ObjectFilterIndex idx, int32_t, int32_t flag);    
        void (*x74)(void* struct_ptr);
        int32_t (*get_frame_a)();
        int32_t (*set_frame_a)(int32_t n);
        void (*set_undo)(ObjectFilterIndex idx, int32_t _unused_flag);
        BOOL (*x84)(ObjectFilterIndex idx);
    };
}
