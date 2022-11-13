#include "pch.h"
//https://github.com/SK-Shaiya
//if you get stuck :D just add me   [s.k#8903]
BOOL Hook(void* pAddr, void* pNAddr, int len)
{
	if (len < 5)
		return FALSE;

	DWORD curProtect;
	VirtualProtect(pAddr, len, PAGE_EXECUTE_READWRITE, &curProtect);
	memset(pAddr, 0x90, len);
	DWORD relativeAddress = ((DWORD)pNAddr - (DWORD)pAddr) - 5;
	*(BYTE*)pAddr = 0xE9;
	*(DWORD*)((DWORD)pAddr + 1) = relativeAddress;
	DWORD temp;
	VirtualProtect(pAddr, len, curProtect, &temp);
	return TRUE;
}

BOOL writeBytes(void* pAddr, void* value, int size)
{
	DWORD dwOldProtect;
	VirtualProtect(pAddr, size, PAGE_READWRITE, &dwOldProtect);
	WriteProcessMemory(GetCurrentProcess(), pAddr, value, size, NULL);
	VirtualProtect(pAddr, size, dwOldProtect, &dwOldProtect);
	return TRUE;
}

void WriteNop(LPVOID lpAddress, INT nSize) {
	DWORD d, ds;
	VirtualProtect(lpAddress, nSize, PAGE_EXECUTE_READWRITE, &d);
	memset(lpAddress, NOP, nSize); VirtualProtect(lpAddress, nSize, d, &ds);
}