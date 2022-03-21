#pragma once
#include <Windows.h>

namespace ExEdit {
    using SpiGetPicture = int(PASCAL*)(LPSTR buf, long len, unsigned int flag, HANDLE *pHBInfo, HANDLE *pHBm, FARPROC lpPrgressCallback, long lData);
    using SpiGetPluginInfo = int(PASCAL*)(int infono, LPSTR buf, int buflen);

    struct SpiImageData {
        HLOCAL l_info;
        HLOCAL l_image;
        BITMAPINFO* p_info;
        void* p_image;
    };

    struct structSPI {
        HMODULE hmodule;
        char information[256];
        char extension[256];
        SpiGetPicture GetPicture;
    };
}
