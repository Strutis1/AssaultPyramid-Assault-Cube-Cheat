#ifndef MEMORY_OFFSETS_H
#define MEMORY_OFFSETS_H

#include <Windows.h>
#include <vector>


namespace mem
{

DWORD LocalPlayer = 0x0017B0B8;
DWORD Entity_List = 0x18AC04;
DWORD FOV = 0x18A7CC;
DWORD PlayerCount = 0x18AC0C;

DWORD Position_X = 0x2C;
DWORD Position_Y = 0x30;
DWORD Position_Z = 0x28;

DWORD Head_Position_X = 0x4;
DWORD Head_Position_Y = 0xC;
DWORD Head_Position_Z = 0x8;

DWORD Player_Camera_X = 0x34;
DWORD Player_Camera_Y = 0x38;

DWORD Assault_Rifle_Ammo = 0x140;
DWORD Submachine_Gun_Ammo  = 0x138;
DWORD Sniper_Ammo  = 0x13C;
DWORD Shotgun  = 0x134;
DWORD Pistol_Ammo = 0x12C;
DWORD Grenade_Ammo = 0x144;

DWORD Fast_fire_Assault_Rifle = 0x164;
DWORD Fast_fire_Sniper = 0x160;
DWORD Fast_fire_Shotgun = 0x158;

DWORD Auto_shoot = 0x204;
DWORD Health_Value = 0xEC;
DWORD Armor_Value = 0xF0;
DWORD Player_Name = 0x205;
    



//got these through cheat engine and worked
    // DWORD Ammo = 0x187C0C;
    // DWORD Health = 0x0017B0B8;
    // std::vector<DWORD> health_offsets = {0xEC};
    // std::vector<DWORD> ammo_offsets = {0x364, 0x14, 0x0};
}





#endif