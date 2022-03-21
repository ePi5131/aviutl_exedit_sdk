#pragma once
#include <cstdint>
#include <Windows.h>

#include <aviutl/flag.hpp>

namespace ExEdit {
	namespace detail {
		enum class SceneFlag : uint32_t {
			Disped = 1 << 0,
			Alpha  = 1 << 1,
		};
	}

	struct SceneSetting {
		using Flag = detail::SceneFlag;
		Flag flag;
		const char* name;
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
	};
}

template<>struct AviUtl::detail::flag::ops_def<ExEdit::detail::SceneFlag>:std::true_type{};
