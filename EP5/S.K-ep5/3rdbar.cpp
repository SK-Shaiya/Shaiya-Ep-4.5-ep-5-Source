#include "pch.h"

int SkillBarValue = 0;
//https://github.com/SK-Shaiya
//if you get stuck :D just add me   [s.k#8903]

DWORD SkillBarMainJMP = 0x42430D;
DWORD SkillBarMainCall1 = 0x5CC96D;
DWORD SkillBarMainCall2 = 0x4DEAC0;
void __declspec(naked) skillbar_main() {
	__asm {

		xor eax, eax
		push 0x110
		call SkillBarMainCall1
		add esp, 0x04
		mov[esp + 0x10], eax
		mov byte ptr[esp + 0x1C], 0x1B
		cmp eax, edi
		je SkillBarMainJE
		push 0x02
		mov ecx, eax
		call SkillBarMainCall2
		mov[SkillBarValue], eax
		mov byte ptr[eax + 0x04], 0x00
		mov byte ptr[eax + 0x08], 0x78
		mov byte ptr[eax + 0x20], 0x00
		jmp SkillBarMainJMP2
		SkillBarMainJE :
		xor eax, eax
			SkillBarMainJMP2 :
		mov[esp + 0x1C], bl
			mov[esi + 0x204], eax
			mov eax, 0x021FDBFA
			mov byte ptr[eax], 02
			lea eax, [esi + 0x1A8]
			xor ecx, ecx
			jmp SkillBarMainJMP



	}
}


DWORD SkillBar1JMP = 0x492697;

DWORD skillbar_add1jnejmp = 0x4926EE;
DWORD skillbar_add1call = 0x4DE330;
void __declspec(naked) skillbar_add1() {
	__asm {

		mov cl, [edi + 0xE0]
		xor edx, edx
		mov dl, [edi + 0xE1]
		push ecx
		push edx
		mov ecx, [SkillBarValue]
		call skillbar_add1call
		test eax, eax
		jne skillbar_add1jnejmps
		mov ecx, [esp + 0x18]
		xor edx, edx
		jmp SkillBar1JMP

		skillbar_add1jnejmps :
		jmp skillbar_add1jnejmp


	}
}


DWORD skillbar_add2jmp = 0x492776;

DWORD skillbar_add2jmp2 = 0x49279E;
DWORD skillbar_add2call = 0x4DE330;

void __declspec(naked) skillbar_add2() {
	__asm {

		movzx ecx, byte ptr[edi + 0xE7]
		push ecx
		mov ecx, [SkillBarValue]
		push 0x64
		call skillbar_add2call
		test eax, eax
		je skillbar_add2jes
		jmp skillbar_add2jmp2
		skillbar_add2jes :
		mov cl, [edi + 0xE7]
			jmp skillbar_add2jmp



	}
}



DWORD skillbar_add3jmp = 0x4DEB87;

DWORD skillbar_add3jejmp = 0x4DEB9C;


void __declspec(naked) skillbar_add3() {
	__asm {


		mov al, [esp + 0x24]
		cmp byte ptr[esp + 0x24], 0x02
		jnl skillbar_add3jnls
		cmp byte ptr[esp + 0x24], 0x00
		je skillbar_add3jes
		jmp skillbar_add3jes
		skillbar_add3jnls :
		jmp skillbar_add3jmp

			skillbar_add3jes :
		jmp skillbar_add3jejmp




	}
}


DWORD skillbar_add4jmp = 0x4DF877;

DWORD skillbar_add4jejmp = 0x4DFA22;


void __declspec(naked) skillbar_add4() {
	__asm {

		cmp byte ptr[esi + 0x10C], 0x02
		je skillbar_add4jejmps
		mov ecx, 0x719968
		mov ecx, [ecx]
		jmp skillbar_add4jmp

		skillbar_add4jejmps :
		jmp skillbar_add4jejmp


	}
}



DWORD skillbar_add5jmp = 0x4E002C;

DWORD skillbar_add5jajmp = 0x4E0079;


void __declspec(naked) skillbar_add5() {
	__asm {

		mov al, [esi + 0x10C]
		cmp byte ptr[esi + 0x10C], 01
		ja skillbar_add5jas
		jmp skillbar_add5jmp

		skillbar_add5jas :
		jmp skillbar_add5jajmp


	}
}


DWORD skillbar_add6jmp = 0x4E006F;

void __declspec(naked) skillbar_add6() {
	__asm {

		mov byte ptr[esi + 0x109], 0x01
		cmp byte ptr[esi + 0x10C], 0x01
		jne skillbar_add6jnes
		cmp byte ptr[esi + 0x101], 0x00
		sete al
		mov esi, [SkillBarValue]
		mov[esi + 0x20], al
		skillbar_add6jnes :
		jmp skillbar_add6jmp


	}
}

DWORD skillbar_add7jmp = 0x4E054F;

DWORD skillbar_add7jejmp1 = 0x4E0605;
DWORD skillbar_add7jejmp2 = 0x4E064F;

void __declspec(naked) skillbar_add7() {
	__asm {

		cmp byte ptr[ebp + 0x10C], 0x00
		je skillbar_add7jes1
		cmp byte ptr[ebp + 0x10C], 0x02
		je skillbar_add7jes2
		jmp skillbar_add7jmp

		skillbar_add7jes2 :
		jmp skillbar_add7jejmp2

			skillbar_add7jes1 :
		jmp skillbar_add7jejmp1


	}
}

unsigned char BarFunc[] = { 0x3C, 0x02 };

void SkillBarFunc()
{
	Hook((void*)0x424307, skillbar_main, 6);
	Hook((void*)0x492691, skillbar_add1, 6);
	Hook((void*)0x492770, skillbar_add2, 6);
	Hook((void*)0x4DEB7F, skillbar_add3, 6);
	Hook((void*)0x4DF871, skillbar_add4, 6);
	Hook((void*)0x4E0022, skillbar_add5, 6);
	Hook((void*)0x4E0068, skillbar_add6, 7);
	Hook((void*)0x4E0549, skillbar_add7, 6);
	writeBytes((void*)0x4DF537, BarFunc, sizeof(BarFunc));
    //https://github.com/SK-Shaiya
	WriteNop((PVOID)(0x424353), 3);
}