#include "pch.h"
//https://github.com/SK-Shaiya
//if you get stuck :D just add me   [s.k#8903]
DWORD dwFPSBoostRetn = 0x54F420;
DWORD dwFPSBoostJump = 0x54F4BC;


__declspec(naked) void FPSBoost()
{
	_asm
	{
		cmp byte ptr[DLL.ICT], 0x1
		je part1
		push ebx
		mov ebx, 0x70BB90
		jmp dwFPSBoostRetn
		part1 :
		jmp dwFPSBoostJump
	}
}

void FpsSettings() {
	Hook((LPVOID)0x54F414, FPSBoost, 6);
}