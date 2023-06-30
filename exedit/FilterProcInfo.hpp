#pragma once
#include <cstdint>

#include <aviutl/pixel.hpp>
#include <aviutl/flag.hpp>
#include <exedit/pixel.hpp>
#include <exedit/Object.hpp>
#include <exedit/ObjectFilterIndex.hpp>

namespace ExEdit {
    struct FilterProcInfo {
        enum Flag : uint32_t {
            bit3         = 1 <<  3,
            bit6         = 1 <<  6, // efMovieFileなど
            fast_preview = 1 <<  9,
            early_filter = 1 << 10, // obj.effect()(引数なし) などを実行するときに設定される
            effect_noarg = 1 << 11, // obj_effect_noarg するときに設定される
            bit12        = 1 << 12, // video_func_main

        } flag;
        void* frame_edit;
        void* frame_temp;
        int32_t scene_w;
        int32_t scene_h;
        int32_t scene_line; // scene_maxw
        int32_t scene_maxh;
        int32_t frame;
        int32_t frame_n;
        int32_t project_w;
        int32_t project_h;
        int16_t* audio_p;
        int32_t audio_n;
        int32_t audio_ch;
        void* pixelp;
        void* editp;
        int32_t yc_size;
        int32_t line_size;
        int32_t unknown[24];
        int32_t frame_num; // タイムライン上の現在フレーム
        PixelYCA* obj_edit;
        PixelYCA* obj_temp;
        int32_t obj_w;
        int32_t obj_h;
        struct Geometry {
            int32_t ox, oy, oz;
            int32_t rx, ry, rz;
            int32_t cx, cy, cz;
            int32_t zoom;
            int32_t aspect;
            int32_t alpha;
        } obj_data;
        int32_t obj_line; // obj_max_w
        int32_t obj_max_h;
        int32_t xf4; // 直前オブジェクトが有効かどうか？
        enum class ObjectFlag {
            bit16 = 1 << 16
        } object_flag;
        int32_t framerate_nu;
        int32_t framerate_de;
        int16_t* audio_data;
        int16_t* audio_temp;
        int32_t audio_rate;
        int32_t add_frame; // frame_numに対して計算上の加算
        int32_t subframe; // 計算上の加算subframe
        int32_t object_start_frame;
        int32_t v_func_idx;
        int32_t obj_index;
        int32_t obj_num;
        int32_t* layer_clipping_flag; // 1:上のオブジェクト, 2:クリッピングするオブジェクト
        int32_t* layer_subframe; // 時間制御を考慮したsubframe
        Object** layer_effect_objectp;
        Object** layer_group_objectp;
        Object* obj_layerp;
        Object* objectp;
        int32_t unknown5;
        struct PolyData {
            int32_t x, y, z, u, v;
        }polydata[4];
        int32_t tick_count;
        ObjectFilterIndex scene_ofi;
        int32_t audio_milliframe;
        int32_t audio_use_milliframe_flag;
        int32_t sub_size_x; // (root_w - fpip->w) / 2
        int32_t sub_size_y; // (root_h - fpip->h) / 2
        int32_t clipping_data_exists;
    };
}
template<> struct AviUtl::detail::flag::ops_def<ExEdit::FilterProcInfo::Flag> : std::true_type {};
