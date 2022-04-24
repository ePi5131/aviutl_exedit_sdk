#pragma once
#include <exedit/variables_core.hpp>
#include <exedit/Filter.hpp>
#include <exedit/scene.hpp>
#include <exedit/layer.hpp>
#include <exedit/Object.hpp>
#include <exedit/CameraZBuffer.hpp>

namespace ExEdit {
	namespace Variables {

		using staticFilterTable = Variable<Filter*, true, 0x0A3E28, 0x0C0A78>;
		using aliasNameBuffer = Variable<char, true, 0x135C70, 0x18FDB8>;
		struct objectDialog {
			using commandTarget = Variable<int, false , 0x14965C, 0x25E97C>;
			using filterStatus = Variable<unsigned char, true, 0x158D38, 0x1C1310>;
			using objectIndex = Variable<int, false, 0x177A10, 0x1051C8>;
		};
		using sceneSetting = Variable<SceneSetting, true, 0x177A50, 0x1051D0>;
		using loadedFilterTable = Variable<Filter*, true, 0x187C98, 0x106490>;
		using layerSetting = Variable<LayerSetting, true, 0x188498, 0x0FB580>;
		using sceneDisplaying = Variable<int, false, 0x1A5310, 0x0EC098>;
		using textBuffer = Variable<wchar_t, true, 0x1A6BD0, 0x1158B8>;
		struct trackBarScript {
			using processingTrackBarIndex = Variable<int, false, 0x1B21F4, 0x1CD824>;
			using processingObjectIndex = Variable<int, false, 0x1B2B04, 0x1CD59C>;
		};
		using scriptProcessingFilter = Variable<Filter*, false, 0x1B2B10, 0x1CD6AC>;
#ifdef lua_h
		using luaState = Variable<lua_State, true, 0x1BACA8, 0x1CD560>;
#endif
		struct objectTable : Variable<Object[], false, 0x1E0FA4, 0x12BA58> {
			using size = Variable<int, false, 0x1E0FA0, 0x129A4C>;
		};
		struct sortedObjectTable : Variable<Object*, true, 0x168FA8, 0x1B2560> {
			using length = Variable<int, false, 0x146250, NULL>;
			using layerIndexBegin = Variable<int, false, 0x149670, 0x1A0360>;
			using layerIndexEnd = Variable<int, false, 0x135AC8, 0x1A0628>;
		};
		struct objectExtraData : Variable<void*, false, 0x1E0FA8, 0x125A2C> {
			using size = Variable<int, false, 0x1E0F9C, 0x12BA54>;
		};
		using cameraZBuffer = Variable<ZBufferElm[], false, 0x1EC7AC, 0x239658>;
		struct undo {
			struct buffer : Variable<void*, false, 0x244E0C, 0x248D00> {
				using size = Variable<unsigned int, false, 0x244E18, 0x23A298>;
				using objectNumber = Variable<int, false, 0x244E08, 0x13078C>;
				using writeOffset = Variable<unsigned int, false, 0x244E10, 0x23A23C>;
			};
			using currentID = Variable<int, false, 0x244E14, 0x23A290>;
		};

	}
}
