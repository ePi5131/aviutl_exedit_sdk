#pragma once
#include <cstdint>
#include <Windows.h>

#include <aviutl/pixel.hpp>
#include <aviutl/AviFileHandle.hpp>
#include <aviutl/MultiThreadFunc.hpp>
#include <aviutl/EditHandle.hpp>
#include <aviutl/FrameStatus.hpp>
#include <aviutl/FileInfo.hpp>
#include <aviutl/SysInfo.hpp>
#include <aviutl/SharedMemory.hpp>

namespace AviUtl{

    struct FilterPlugin;

    struct ExFunc {
        [[deprecated("use get_ycp_source_cache.")]]
        void (*get_ycp_ofs)(EditHandle* editp, int32_t n, int32_t ofs);
        
        [[deprecated("use get_ycp_source_cache.")]]
        void* (*get_ycp)(EditHandle* editp, int32_t n);
        
        void* (*get_pixelp)(EditHandle* editp, int32_t n);

        int32_t (*get_audio)(EditHandle* editp, int32_t n, void* buf);

        BOOL (*is_editing)(EditHandle* editp);

        BOOL (*is_saving)(EditHandle* editp);

        int32_t (*get_frame)(EditHandle* editp);

        int32_t (*get_frame_n)(EditHandle* editp);

        BOOL (*get_frame_size)(EditHandle* editp, int32_t* w, int32_t* h);

        int32_t (*set_frame)(EditHandle* editp, int32_t n);

        int32_t (*set_frame_n)(EditHandle* editp, int32_t n);

        BOOL (*copy_frame)(EditHandle* editp, int32_t d, int32_t s);

        BOOL (*copy_video)(EditHandle* editp, int32_t d, int32_t s);

        BOOL (*copy_audio)(EditHandle* editp, int32_t d, int32_t s);

        BOOL (*copy_clip)(HWND hwnd, PixelBGR* pixelp, int32_t w, int32_t h);

        BOOL (*paste_clip)(HWND hwnd, EditHandle* editp, int32_t n);

        BOOL (*get_frame_status)(EditHandle* editp, int32_t n, FrameStatus* fsp);

        BOOL (*set_frame_status)(EditHandle* editp, int32_t n, FrameStatus* fsp);

        BOOL (*is_saveframe)(EditHandle* editp, int32_t n);

        BOOL (*is_keyframe)(EditHandle* editp, int32_t n);

        BOOL (*is_recompress)(EditHandle* editp, int32_t n);
        
        BOOL (*filter_window_update)(FilterPlugin* fp);

        BOOL (*is_filter_window_disp)(FilterPlugin* fp);

        BOOL (*get_file_info)(EditHandle* editp, FileInfo* fip);

        LPSTR (*get_config_name)(EditHandle* editp, int32_t n);

        BOOL (*is_filter_active)(FilterPlugin* fp);

        BOOL (*get_pixel_filtered)(EditHandle* editp, int32_t n, PixelBGR* pixelp, int32_t* w, int32_t* h);

        int32_t (*get_audio_filtered)(EditHandle* editp, int32_t n, void* buf);

        BOOL (*get_select_frame)(EditHandle* editp, int32_t* s, int32_t* e);
        
        BOOL (*set_select_frame)(EditHandle* editp, int32_t s, int32_t e);

        BOOL (*rgb2yc)(PixelYC* ycp, PixelBGR* pixelp, int32_t w);

        BOOL (*yc2rgb)(PixelYC* pixelp, PixelBGR* ycp, int32_t w);

        BOOL (*dlg_get_load_name)(LPSTR name, LPCSTR filter, LPCSTR def);

        BOOL (*dlg_get_save_name)(LPSTR name, LPCSTR filter, LPCSTR def);

        int32_t (*ini_load_int)(FilterPlugin* fp, LPCSTR key, int32_t n);
        
        int32_t (*ini_save_int)(FilterPlugin* fp, LPCSTR key, int32_t n);

        BOOL (*ini_load_str)(FilterPlugin* fp, LPCSTR key, LPSTR str, LPCSTR def);

        BOOL (*ini_save_str)(FilterPlugin* fp, LPCSTR key, LPCSTR str);

        BOOL (*get_source_file_info)(EditHandle* editp, FileInfo* fip, int32_t source_file_id);

        BOOL (*get_source_video_number)(EditHandle* editp, int32_t n, int32_t* source_file_id, int32_t* source_video_number);
        
        BOOL (*get_sys_info)(EditHandle* editp, SysInfo* sip);

        FilterPlugin* (*get_filterp)(int32_t filter_id);

        [[deprecated("use get_ycp_filtering_cache_ex.")]]
        void* (*get_ycp_filtering)(FilterPlugin* fp, EditHandle* editp, int32_t n, void* reserve);

        int32_t (*get_audio_filtering)(FilterPlugin* fp, EditHandle* editp, int32_t n, int16_t* buf);
        
        BOOL (*set_ycp_filtering_cache_size)(FilterPlugin* fp, int32_t w, int32_t h, int32_t d, int32_t flag);

        [[deprecated("use get_ycp_filtering_cache_ex.")]]
        void* (*get_ycp_filtering_cache)(FilterPlugin* fp, EditHandle* editp, int32_t n);

        void* (*get_ycp_source_cache)(EditHandle* editp, int32_t n, int32_t ofs);

        void* (*get_disp_pixelp)(EditHandle* editp, DWORD format);
        
        BOOL (*get_pixel_source)(EditHandle* editp, int32_t n, void* pixelp, DWORD format);

        BOOL (*get_pixel_filtered_ex)(EditHandle* editp, int32_t n, void* pixelp, int32_t* w, int32_t* h, DWORD format);
        
        PixelYC* (*get_ycp_filtering_cache_ex)(FilterPlugin* fp, EditHandle* editp, int32_t n, int32_t* w, int32_t* h);

        BOOL (*exec_multi_thread_func)(MultiThreadFunc func, void* param1, void* param2);
        
        PixelYC* (*create_yc)();

        void (*delete_yc)(PixelYC* ycp);
        
        enum class LoadImageFlag : uint32_t {
            None = 0
        };
        BOOL(*load_image)(PixelYC* ycp, LPSTR file, int32_t* w, int32_t* h, LoadImageFlag flag);

        void (*resize_yc)(PixelYC* ycp, int32_t w, int32_t h, PixelYC* ycp_src, int32_t sx, int32_t sy, int32_t sw, int32_t sh);

        void (*copy_yc)(PixelYC* ycp, int32_t x, int32_t y, PixelYC* ycp_src, int32_t sx, int32_t sy, int32_t sw, int32_t sh, int32_t tr);

        void (*draw_text)(PixelYC* ycp, int32_t x, int32_t y, LPSTR text, int32_t r, int32_t g, int32_t b, int32_t tr, HFONT hfont, int32_t* w, int32_t* h);
        
        enum class AVIFileOpenFlag : uint32_t {
            VideoOnly = 1 <<  4,
            AudioOnly = 1 <<  5,
            ForceAVI  = 1 <<  6, // private 強制的にAVIs_File_Readerに食わせる
            YUY2      = 1 << 16,
            RGB24     = 1 << 17,
            RGB32     = 1 << 18,
        };
        AviFileHandle* (*avi_file_open)(LPSTR file, FileInfo* fip, AVIFileOpenFlag flag);

        void (*avi_file_close)(AviFileHandle* afh);
        BOOL (*avi_file_read_video)(AviFileHandle* afh, PixelYC* ycp, int32_t n);

        int32_t (*avi_file_read_audio)(AviFileHandle* afh, void* buf, int32_t n);
        
        void* (*avi_file_get_video_pixelp)(AviFileHandle* afh, int32_t n);

        enum class GetAVIFileFilterType : uint32_t {
            Video = 0,
            Audio = 1,
        };
        const char* (*get_avi_file_filter)(GetAVIFileFilterType type);

        int32_t (*avi_file_read_audio_sample)(AviFileHandle* afh, int32_t start, int32_t length, int16_t* buf);
        
        int32_t (*avi_file_set_audio_sample_rate)(AviFileHandle* afh, int32_t audio_rate, int32_t audio_ch);

        enum class FrameStatusType : uint32_t {
            EditFlag = 0,
            Inter = 1
        };
        BYTE* (*get_frame_status_table)(EditHandle* editp, FrameStatusType type);

        BOOL (*set_undo)(EditHandle* editp);

        enum class AddMenuItemFlag : uint32_t {
            None  = 0,
            Shift = 1,
            Ctrl  = 2,
            Alt   = 4,
        };
        BOOL (*add_menu_item)(FilterPlugin* fp, LPCSTR name, HWND hwnd, int32_t id, int32_t def_key, AddMenuItemFlag flag);
        
        enum class EditOpenFlag : uint32_t {
            None    = 0,
            Add     = 1 <<  1,
            Flag_0x2= 1 <<  2,
            Audio   = 1 <<  4,
            Project = 1 <<  9,
            Dialog  = 1 << 16,
        };
        BOOL (*edit_open)(EditHandle* editp, LPSTR file, EditOpenFlag flag);

        BOOL (*edit_close)(EditHandle* editp);
        
        enum class EditOutputFlag : uint32_t {
            NoDialog = 1 << 1,
            Wav      = 1 << 2
        };
        BOOL (*edit_output)(EditHandle* editp, const char* file, int32_t flag, const char* type);

        BOOL (*set_config)(EditHandle* editp, int32_t n, LPSTR name);
        
        void* (*create_shared_mem)(int32_t key1, int32_t key2, int32_t size, SharedMemoryInfo** handle_ptr);

        void* (*get_shared_mem)(int32_t key1, int32_t key2, SharedMemoryInfo* handle);

        void (*delete_shared_mem)(int32_t key1, SharedMemoryInfo* handle);

        int32_t reserve[4];
    };
    template<> struct detail::flag::ops_def<ExFunc::LoadImageFlag>: std::true_type {};
    template<> struct detail::flag::ops_def<ExFunc::AVIFileOpenFlag>: std::true_type {};
    template<> struct detail::flag::ops_def<ExFunc::AddMenuItemFlag>: std::true_type {};
    template<> struct detail::flag::ops_def<ExFunc::EditOpenFlag>: std::true_type {};
    template<> struct detail::flag::ops_def<ExFunc::EditOutputFlag>: std::true_type {};
}
