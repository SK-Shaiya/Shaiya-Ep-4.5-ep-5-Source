#include "pch.h"
//https://github.com/SK-Shaiya
//if you get stuck :D just add me   [s.k#8903]


DWORD SmallBuffReturn1 = 0x4C051D;
DWORD SmallBuffReturn2 = 0x4C052D;
DWORD SmallBuffReturn3 = 0x4C055D;
DWORD SmallBuffReturn4 = 0x4C0576;
DWORD SmallBuffReturn5 = 0x4A1933;
DWORD SmallBuffReturn6 = 0x4A2FC3;
DWORD SmallBuffReturn7 = 0x4A2FFD;
DWORD SmallBuffReturn8 = 0x4A1906;


__declspec(naked) void SmallBuffHook1()
{
	_asm
	{
		cmp byte ptr[DLL.ICO], 0x1
		je _minicon
		lea ecx, [edi + 0x20] // Size
		cmp eax, ecx
		jmp SmallBuffReturn1

		_minicon :
		lea ecx, [edi + 0x16] // Size
			cmp eax, ecx
			jmp SmallBuffReturn1

	}
}

__declspec(naked) void SmallBuffHook2()
{
	_asm
	{
		cmp byte ptr[DLL.ICO], 0x1
		je _minicon
		lea edx, [ebx + 0x20] // Size
		cmp eax, edx
		jmp SmallBuffReturn2

		_minicon :
		lea edx, [ebx + 0x16] // Size
			cmp eax, edx
			jmp SmallBuffReturn2
	}
}

__declspec(naked) void SmallBuffHook3()
{
	_asm
	{
		cmp byte ptr[DLL.ICO], 0x1
		je _minicon
		push 0x20 // Size
		push 0x20 // Size
		push ebx
		jmp SmallBuffReturn3

		_minicon :
		push 0x16 // Size
			push 0x16 // Size
			push ebx
			jmp SmallBuffReturn3

	}
}

__declspec(naked) void SmallBuffHook4()
{
	_asm
	{
		cmp byte ptr[DLL.ICO], 0x1
		je _minicon
		add edi, 0x28  // distance between two buffs
		cmp eax, 0x0A  // number of side-by-side buffs
		jmp SmallBuffReturn4

		_minicon :
		add edi, 0x18  // distance between two buffs
			cmp eax, 0x0A  // number of side-by-side buffs
			jmp SmallBuffReturn4

	}
}

__declspec(naked) void SmallBuffHook5()
{
	_asm
	{

		cmp esi, 0x3C // Check for skill level text
		jne originalcode
		cmp byte ptr[DLL.ICO], 0x1
		je _minicon
		add esi, 0x0F
		push esi
		add ebp, 0x0C
		jmp SmallBuffReturn5

		_minicon :
		add esi, 0x09  // Location
			push esi
			add ebp, 0x06  // Location
			jmp SmallBuffReturn5

			originalcode :
		add esi, 0x0F
			push esi
			add ebp, 0x0C
			jmp SmallBuffReturn5


	}
}


__declspec(naked) void SmallBuffHook6()
{
	_asm
	{
		cmp byte ptr[DLL.ICO], 0x1
		je _minicon
		push 0x20 // Size of bar
		add esi, 0x20  // Location of bar
		jmp SmallBuffReturn6

		_minicon :
		push 0x16 // Size of bar
			add esi, 0x16  // Location of bar
			jmp SmallBuffReturn6
	}
}

__declspec(naked) void SmallBuffHook7()
{
	_asm
	{
		cmp byte ptr[DLL.ICO], 0x1
		je _minicon
		fmul dword ptr ds : [0x6BC870] // Size of yellow bar
		jmp SmallBuffReturn7

		_minicon :
		fmul dword ptr ds : [0x6BC890] // Size of yellow bar
			jmp SmallBuffReturn7
	}
}

__declspec(naked) void SmallBuffHook8()
{
	_asm
	{

		cmp byte ptr[esp + 0x20], -0x6B // Check for skills
		jne originalcode
		cmp byte ptr[DLL.ICO], 0x1
		je _minicon
		push 0x20
		push 0x20
		push esi
		jmp SmallBuffReturn8

		_minicon :
		push 0x16 // Size
			push 0x16 // Size
			push esi
			jmp SmallBuffReturn8
			originalcode :
		push 0x20
			push 0x20
			push esi
			jmp SmallBuffReturn8
	}
}

void MiniIcon() {

	Hook((void*)0x4C0518, SmallBuffHook1, 5);
	Hook((void*)0x4C0528, SmallBuffHook2, 5);
	Hook((void*)0x4C0558, SmallBuffHook3, 5);
	Hook((void*)0x4C0570, SmallBuffHook4, 5);
	Hook((void*)0x4A192C, SmallBuffHook5, 5);
	Hook((void*)0x4A2FBE, SmallBuffHook6, 5);
	Hook((void*)0x4A2FF7, SmallBuffHook7, 6);
	Hook((void*)0x4A1901, SmallBuffHook8, 5);

}