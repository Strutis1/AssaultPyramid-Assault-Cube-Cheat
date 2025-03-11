#include <Windows.h>
#include <iostream>
#include "memoryOffsets.h"
#include <vector>



DWORD WINAPI CoolThread(HMODULE hModule){
    AllocConsole();
    FILE* console = freopen("CONOUT$", "w", stdout);
    printf("Internal test");

    Sleep(2000);

    DWORD moduleBase = (DWORD)GetModuleHandle(TEXT("ac_client.exe"));
    if (!moduleBase) {
        printf("Failed to get Assault Cube's module base!");
        return 0;
    }

    while(!GetAsyncKeyState(VK_NUMPAD0)){
        DWORD localPlayer = *(DWORD*)(moduleBase + mem::LocalPlayer);

        if (!localPlayer) {
            std::cout << "[-] Local Player Pointer is NULL! Skipping...\n";
            Sleep(100);
            continue;
        }


        int* health = (int*) (localPlayer + mem::Health_Value);
        if (health) {
            *health = 1000;
            std::cout << "[+] Health Changed to 1000\n";
        } else {
            std::cout << "[-] Failed to get Health Pointer!\n";
        }


        int* ammo = (int*)(localPlayer + mem::Submachine_Gun_Ammo);
        if (ammo) {
            *ammo = 1000;
            std::cout << "[+] Ammo Changed to 1000\n";
        } else {
            std::cout << "[-] Failed to get Ammo Pointer!\n";
        }
        Sleep(20);
    }
    std::cout<<"Exiting...";
    fclose(console);
    FreeConsole();
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