#pragma once
#include <cstdint>

#include <exedit/scene.hpp>
#include <exedit/layer.hpp>
#include <exedit/Filter.hpp>

namespace ExEdit {
    struct SaveHeader {
        std::uint32_t magic;
        int32_t filter_n;
        int32_t object_n;
        int32_t x0c;
        int32_t timeline_zoom;
        int32_t timeline_frame;
        int32_t selecting_object_idx;
        size_t object_size;
        size_t track_max;
        size_t check_max;
        size_t filter_max;
        uint32_t exedit_version;
        int32_t grid;
        int32_t grid_tempo;
        int32_t grid_base;
        int32_t grid2d;
        int32_t grid2d_w;
        int32_t grid2d_h;
        int32_t grid3d;
        int32_t grid3d_size;
        int32_t grid3d_num;
        int32_t out_of_area;
        int32_t out_of_scale;
        int32_t grid_time;
        int32_t i10196764;
        int32_t selecting_scene;
        int32_t scene_n;
        int32_t layer_n;
        int32_t x70;
        int32_t x74;
        int32_t timeline_layer;
        int32_t trascript_n;
        int32_t reserved[32];
    };

    // func_project_save/load用データ
	struct FilterSave {
		using Flag = ExEdit::Filter::Flag;
		Flag flag;
		int32_t track_n;
		int32_t check_n;
		int32_t exdata_size;
		char filter_name[64];
		char unknown_s[32];
	};
    
	struct SceneSettingSave {
		using Flag = detail::SceneFlag;
		int32_t index;
		Flag flag;
		char name[64];
		int32_t width, height;
		int32_t max_frame;
		int32_t current_frame;
		int32_t timeline_scale;
		int32_t timeline_disp_begin_pos;
		int32_t selected_object;
		int32_t selected_frame_begin;
		int32_t selected_frame_end;
		BOOL disp_bpm_grid;
		int32_t bpm_grid_tempo;
		int32_t bpm_grid_base;
		BOOL disp_xy_grid;
		int32_t xy_grid_width;
		int32_t xy_grid_height;
		BOOL disp_camera_grid;
		int32_t camera_grid_size;
		int32_t camera_grid_num;
		BOOL disp_out_of_frame;
		int32_t out_of_frame_scale;
		int32_t bpm_grid_beat;
		int32_t disp_begin_layer;
		int32_t reserved[15];
	};

    struct LayerSettingSave {
        using Flag = detail::LayerFlag;
        int32_t scene;
        int32_t layer;
        Flag flag;
        char name[64];
    };
}
