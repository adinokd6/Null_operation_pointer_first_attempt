#include <iostream>
#include <vector>
#include <Windows.h>
#include "proc.h"
#include "mem.h"



int main()
{
	HANDLE hProcess = 0;
	uintptr_t moduleBase = 0, localPlayerPtr = 0, dmg_addr = 0;
	bool b_dmg = false;

	DWORD procId = GetProcId(L"eurotrucks2.exe");
	const int newValue = 0;
	if (procId)
	{
		hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, procId);

		moduleBase = GetModuleBaseAddress(procId, L"eurotrucks2.exe");

		localPlayerPtr = moduleBase + 0x0127D710;

		dmg_addr = FindDMAAddy(hProcess, localPlayerPtr, { 0x18,0x68,0x3e8,0x18,0x8,0x10 });
	}
	else
	{
		std::cout << "Process eurotrucks2.exe not found\n";
		getchar();
		return 0;
	}

	DWORD dwExit = 0;

	

	while(true)
	{

		if (GetAsyncKeyState(VK_NUMPAD1) & 1)
		{
			b_dmg = !b_dmg;
			if (b_dmg)
			{
				std::cout << "Dupa";
				getchar();
				mem::PatchEx((BYTE*)dmg_addr, (BYTE*)&newValue, sizeof(newValue), hProcess);
			}
		}


		if (GetAsyncKeyState(VK_INSERT) & 1)
		{
			return 0;
		}

		Sleep(10);
	}

	std::cout << "Process not found";
	return 0;
}