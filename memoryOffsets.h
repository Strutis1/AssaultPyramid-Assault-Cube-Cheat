#ifndef MEMORY_OFFSETS_H
#define MEMORY_OFFSETS_H

#include <Windows.h>
#include <vector>

//got these values through cheat engine's pointer map and scan

namespace mem
{
    DWORD Ammo = 0x187C0C;
    DWORD Health = 0x0017B0B8;
    std::vector<DWORD> health_offsets = {0xEC};
    std::vector<DWORD> ammo_offsets = {0x364, 0x14, 0x0};
}




#endif