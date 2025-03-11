#include <Windows.h>
#include <iostream>
#include "memoryOffsets.h"
#include <vector>


DWORD getPtrAddress(DWORD ptr, std::vector<DWORD> offsets){
    DWORD address = ptr;
    for (int i = 0; i < offsets.size(); ++i) {
        address = *(DWORD*) address;
        address += offsets[i];
    }
    return address;
}

DWORD WINAPI CoolThread(HMODULE hModule){
    AllocConsole();
    FILE* console = freopen("CONOUT$", "w", stdout);
    printf("Internal test");

    Sleep(2000);
    FreeConsole();

    DWORD moduleBase = (DWORD)GetModuleHandle(TEXT("ac_client.exe"));
    if (!moduleBase) {
        printf("Failed to get Assault Cube's module base!");
        return 0;
    }

    while(!GetAsyncKeyState(VK_NUMPAD0)){
       int* health = (int*)getPtrAddress(moduleBase + mem::Health, mem::health_offsets);
       *health = 1000;
       printf("Changing Health");
       int* ammo = (int*)getPtrAddress(moduleBase + mem::Ammo, mem::ammo_offsets);
       *ammo = 1000;
       printf("Changing Ammo");
    }

    if(GetAsyncKeyState(VK_NUMPAD0)){
        fclose(console);
    }

    FreeLibraryAndExitThread(hModule, 0);
    return 0;
}



BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    switch(ul_reason_for_call)
    {
        case DLL_PROCESS_ATTACH:
            CloseHandle(CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)CoolThread,hModule, 0, nullptr));

        case DLL_THREAD_ATTACH:

        case DLL_THREAD_DETACH:

        case DLL_PROCESS_DETACH:
            break;
    }
    return TRUE;
}