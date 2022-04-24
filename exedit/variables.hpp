#pragma once
#include <exedit/variables_core.hpp>
#include <exedit/Filter.hpp>
#include <exedit/scene.hpp>
#include <exedit/layer.hpp>
#include <exedit/Object.hpp>
#include <exedit/CameraZBuffer.hpp>

#define _OFFSET(exedit_version) static inline constexpr unsigned int offset##exedit_version

namespace ExEdit {
	namespace Variables {

		struct staticFilterTable : Variable<Filter*, true> {
			_OFFSET(092) = 0x0A3E28;
			_OFFSET(093rc1) = 0x0C0A78;
		};

		struct aliasNameBuffer : Variable<char, true> {
			_OFFSET(092) = 0x135C70;
			_OFFSET(093rc1) = 0x18FDB8;
		};

		struct objectDialog {
			struct commandTarget : Variable<int> {
				_OFFSET(092) = 0x14965C;
				_OFFSET(093rc1) = 0x25E97C;
			};

			struct filterStatus : Variable<unsigned char, true> {
				_OFFSET(092) = 0x158D38;
				_OFFSET(093rc1) = 0x1C1310;
			};

			struct objectIndex : Variable<int> {
				_OFFSET(092) = 0x177A10;
				_OFFSET(093rc1) = 0x1051C8;
			};
		};

		struct sceneSetting : Variable<SceneSetting, true> {
			_OFFSET(092) = 0x177A50;
			_OFFSET(093rc1) = 0x1051D0;
		};

		struct loadedFilterTable : Variable<Filter*, true> {
			_OFFSET(092) = 0x187C98;
			_OFFSET(093rc1) = 0x106490;
		};

		struct layerSetting : Variable<LayerSetting, true> {
			_OFFSET(092) = 0x188498;
			_OFFSET(093rc1) = 0x0FB580;
		};

		struct sceneDisplaying : Variable<int> {
			_OFFSET(092) = 0x1A5310;
			_OFFSET(093rc1) = 0x0EC098;
		};

		struct textBuffer : Variable<wchar_t, true> {
			_OFFSET(092) = 0x1A6BD0;
			_OFFSET(093rc1) = 0x1158B8;
		};

		struct trackBarScript {
			struct processingTrackBarIndex : Variable<int> {
				_OFFSET(092) = 0x1B21F4;
				_OFFSET(093rc1) = 0x1CD824;
			};

			struct processingObjectIndex : Variable<int> {
				_OFFSET(092) = 0x1B2B04;
				_OFFSET(093rc1) = 0x1CD59C;
			};
		};

		struct scriptProcessingFilter : Variable<Filter*> {
			_OFFSET(092) = 0x1B2B10;
			_OFFSET(093rc1) = 0x1CD6AC;
		};

#ifdef lua_h
		struct luaState : Variable<lua_State, true> {
			_OFFSET(092) = 0x1BACA8;
			_OFFSET(093rc1) = 0x1CD560;
		};
#endif

		struct objectTable : Variable<Object[]> {
			_OFFSET(092) = 0x1E0FA4;
			_OFFSET(093rc1) = 0x12BA58;

			struct size : Variable<int> {
				_OFFSET(092) = 0x1E0FA0;
				_OFFSET(093rc1) = 0x129A4C;
			};
		};

		struct sortedObjectTable : Variable<Object*, true> {
			_OFFSET(092) = 0x168FA8;
			_OFFSET(093rc1) = 0x1B2560;

			struct length : Variable<int> {
				_OFFSET(092) = 0x146250;
			};

			struct layerIndexBegin : Variable<int> {
				_OFFSET(092) = 0x149670;
				_OFFSET(093rc1) = 0x1A0360;
			};

			struct layerIndexEnd : Variable<int> {
				_OFFSET(092) = 0x135AC8;
				_OFFSET(093rc1) = 0x1A0628;
			};
		};

		struct objectExtraData : Variable<void*> {
			_OFFSET(092) = 0x1E0FA8;
			_OFFSET(093rc1) = 0x125A2C;

			struct size : Variable<int> {
				_OFFSET(092) = 0x1E0F9C;
				_OFFSET(093rc1) = 0x12BA54;
			};
		};

		struct cameraZBuffer : Variable<ZBufferElm[]> {
			_OFFSET(092) = 0x1EC7AC;
			_OFFSET(093rc1) = 0x239658;
		};

		struct undo {
			struct buffer : Variable<void*> {
				_OFFSET(092) = 0x244E0C;
				_OFFSET(093rc1) = 0x248D00;

				struct size : Variable<unsigned int> {
					_OFFSET(092) = 0x244E18;
					_OFFSET(093rc1) = 0x23A298;
				};

				struct objectNumber : Variable<int> {
					_OFFSET(092) = 0x244E08;
					_OFFSET(093rc1) = 0x13078C;
				};

				struct writeOffset : Variable<unsigned int> {
					_OFFSET(092) = 0x244E10;
					_OFFSET(093rc1) = 0x23A23C;
				};
			};

			struct currentID : Variable<int> {
				_OFFSET(092) = 0x244E14;
				_OFFSET(093rc1) = 0x23A290;
			};
		};

	}
}

#undef _OFFSET
