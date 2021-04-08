#pragma once

#include <vector>
#include <Windows.h>
#include <TlHelp32.h>

DWORD GetProcId(const wchar_t* procName);

uintptr_t GetModuleBaseAddress(DWORD procId, const wchar_t* modName);

uintptr_t FindDMAAddy(HANDLE hProc, uintptr_t ptr, std::vector<unsigned int>);



dzien=int(input("Wprowadz dzien rozpoczecia: "))
miesiac=int(input("Wprowadz miesiac rozpoczecia: "))
rok=int(input("Wprowadz rok rozpoczecia: "))
godzina_rozp=int(input("Wprowadz godzine rozpoczecia: "))
minuta_rozp=int(input("Wprowadz minute rozpoczecia: "))

minuty=int(input("Ile minut bedzie trwalo wydarzenie: "))

tmp_rok=minuty//60//24//30//12
minuty-=tmp_rok*60*24*30*12

tmp_miesiac=minuty//60//24//30
minuty-=tmp_miesiac*60*24*30

tmp_dni=minuty//60//24
minuty-=tmp_dni*24*60

tmp_godziny=minuty//60
minuty-=tmp_godziny*60

tmp_minuty=minuty

print(tmp_minuty)



if tmp_minuty>0:
    minuty+=tmp_minuty
    if minuty/60>0:
        godzina_rozp+=minuty//60
        minuty-=(minuty//60)*60

if tmp_godziny>0:
    godzina_rozp+=tmp_godziny
    if godzina_rozp/24>0:
        dzien+=godzina_rozp//24
        godzina_rozp-=(godzina_rozp//24)*24

if tmp_dni>0:
    dzien+=tmp_dni
    if dzien/30>0:
        miesiac+=dzien//30
        dzien-=(dzien//30)*30

if tmp_miesiac/30>0:
    miesiac+=tmp_miesiac
    if miesiac>12:
        rok+=miesiac//12
        miesiac-=(miesiac//12)*12


print("Wydarzenie zakonczy sie: ",dzien,".",miesiac,".",rok," o godzinie: ",godzina_rozp,":",minuta_rozp)
