#pragma once
#include <cstdint>

#include <aviutl/flag.hpp>
#include <aviutl/Color.hpp>
#include <aviutl/aviutl_window_info_t.hpp>

namespace AviUtl {
	struct SAV3 {
		char name[260];
		byte unknown1[16380];
		int32_t int_4100;
		byte unknown2[32];
	};

	struct EditHandle {
		enum class Flag : uint32_t {
			Editing          = 1,
			FilterWindowDisp = 2,
			Saving           = 5,
			bit4             = 1 << 4,
			
		} flag;
		char edit_filename[260];
		char output_filename[260];
		char project_filename[260];
		int32_t w, h;
		int32_t frame_n;
		int32_t select_frame_start, select_frame_end;
		int32_t field_324;
		int32_t w1, h1;
		int32_t disp_frame;
		PixelYC* ycp_edit;
		int32_t field_338;
		int32_t w2, h2;
		int32_t field_344;
		DWORD format;
		int32_t field_34c[8];
		aviutl_window_info_t aviutl_window_info;
		int32_t field_3bc;
		int32_t field_3c0_flag;
		int32_t fleld_3c4[6];
		int16_t field_3dc;
		uint16_t video_decode_bit;
		DWORD video_decode_format;
		int32_t field_3e4[5];
		int16_t field_3f8;
		uint16_t audio_ch;
		int32_t audio_rate;
		int32_t field_400[3];
		void* unknown_input_struct;
		int32_t field_410[23];
		int32_t video_scale;
		int32_t video_rate;
		int32_t field_470[25008];
		byte sav_1[24704];
		byte sav_2[8548];
		int32_t field_20d14;
		char some_paths[96][260];
		int32_t field_26e98[1093758];
		int32_t field_453090;
		int32_t field_453094[107329];
		HGLOBAL some_hglobals[256];
		int32_t field_4bc198[193];
		SAV3 sav_3;
		int32_t field_4c05c0[256];
		int32_t* video;
		int32_t* audio;
		int32_t* field_4c09c8;
		int32_t* field_4c09cc;
		byte* inter;
		byte* index24fps;
		byte* edit_flag;
		byte* config;
		byte* vcm;
		byte* field_4c09e4;
	};
	template<>struct detail::flag::ops_def<EditHandle::Flag>:std::true_type{};
}
