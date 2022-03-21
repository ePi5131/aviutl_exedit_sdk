#pragma once
#include <cstdint>

#include <aviutl/flag.hpp>

namespace AviUtl {
	struct FileInfo {
		enum class Flag : uint32_t {
			Video = 1,
			Audio = 2,
		} flag;

		const char* name;
		int32_t w, h;
		int32_t video_rate, video_scale;

		int32_t audio_rate;
		int32_t audio_ch;

		int32_t frame_n;

		DWORD video_decode_format;
		int32_t video_decode_bit;

		int32_t audio_n;

		int32_t reserve[4];
	};
	
	template<> struct detail::flag::ops_def<FileInfo::Flag>: std::true_type {};
}
