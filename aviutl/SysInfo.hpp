#pragma once
#include <cstdint>
#include <Windows.h>

#include <aviutl/flag.hpp>

namespace AviUtl {
	struct SysInfo {
		enum class Flag {
			Edit	= 1,
			VFAPI	= 2,
			UseSSE	= 4,
			UseSSE2	= 8,
		} flag;

		const char* info;
		int32_t filter_n;
		int32_t min_w, min_h;
		int32_t max_w, max_h;
		int32_t max_frame;
		const char* edit_name;
		const char* project_name;
		const char* output_name;
		int32_t vram_w, vram_h;
		int32_t vram_yc_size;
		int32_t vram_line_size;
		HFONT hfont;
		int32_t build;
		int32_t reserve[2];
	};

	template<> struct detail::flag::ops_def<SysInfo::Flag>: std::true_type {};
}
