#pragma once


namespace AviUtl {
    struct SharedMemoryInfo {
        HANDLE hFileMappingObject;
        void* mem_ptr;
        SIZE_T size;
        SharedMemoryInfo** this_handle_ptr;
        int key1;
        int key2;
        int id;
    };
}
