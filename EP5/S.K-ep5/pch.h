//https://github.com/SK-Shaiya
//if you get stuck :D just add me   [s.k#8903]
#ifndef PCH_H
#define PCH_H
#define NOP 0x90
#define WIN32_LEAN_AND_MEAN    

#include <windows.h>
#include <WinUser.h>
#include <iostream>
#include <string>
#include <wininet.h>
#include <fstream>
#include <algorithm>
#include <time.h>
#include <conio.h>
#include <stdio.h>
#include <tchar.h>
#include <math.h>
#include <stdlib.h>
#include <direct.h>
#include <fcntl.h>
#include <io.h>
#include <vector>
#include <rpc.h>
#include <rpcdce.h>
#include <iomanip>
#include <cstdlib>
#include <tlhelp32.h>
#include <process.h>
#include <shellapi.h>
#include <sstream>
#include <array>
#include <time.h>
#include <chrono>
#include <clocale>
#include <locale.h>
#include "obfuscate.h"
#include "ini.h"	



BOOL Hook(void* pAddr, void* pNAddr, int len = 5);
BOOL writeBytes(void* pAddr, void* value, int size);
void WriteNop(LPVOID lpAddress, INT nSize);

#define FIRE 1
#define WATER 2
#define EARTH 3
#define WIND 4

#endif 

extern  "C"  __declspec(dllexport) void __cdecl Main();

void SkillBarFunc();

void FpsSettings();
void ShaiyaServer();
void Init();
void StatPoints();

void MiniIcon();






using namespace std;

class Shaiya
{
public:
	const char* Title;
	const char* Error;
	bool AntiCheat;
	bool Game;
	bool Interface;
	int MouseX, MouseY, iFontSize;
	char cFont[255], cFontSize[255];

	char iNameValue;
	char cName[255];
	string stColor1 = "WHITE";
	string stColor2 = "BLUE";
	string stColor3 = "YELLOW";
	string stColor4 = "ORANGE";
	string stColor5 = "PINK";

	char szLocationX[255], szLocationY[255], newLocationX[255], newLocationY[255];
	int LocationX, LocationY, oldLocationX, oldLocationY;

	char QuickSlotExtraX[255], QuickSlotExtraY[255], QuickSlotExtra[255], QuickSlotExtraChange[255];
	int iQuickSlotExtraX, iQuickSlotExtraY, QuickSlotExtraValue, QuickSlotExtraChangeValue;
	const char* cQUICKSLOTCONFIG = "QUICKSLOT";
	const char* cQUICKSLOTEXTRA = "QUICKSLOTEXTRA";
	const char* cQUICKSLOTEXTRACHANGE = "QUICKSLOTEXTRA_CHANGE";
	const char* cQUICKSLOTEXTRA_POS_X = "QUICKSLOTEXTRA_POS_X";

	char cEFT[255], cICO[255], cCMD[255], cICT[255];
	int EFT, ICO, CMD, ICT, LMT, xFPS;
	const char* ccEFT = "EFFECT";
	const char* ccICO = "SMALLICON";
	const char* ccICT = "FPS";
	const char* ccCMD = "AUTOCOMMAND";
	string stTRUE = "TRUE";

};
extern Shaiya DLL;

#ifndef Duno_Dump_H
#define Dump_Dump_H

#define MAX_DUMP_OFFSETS 2  // << Maksimum dump miktari
#define MAX_DUMP_SIZE 8      // << dump boyutu
#define MAX_PROCESS_DUMP 2  // << Maksimum dump miktari

typedef struct ANITHACK_PROCDUMP {
	unsigned int m_aOffset;
	unsigned char m_aMemDump[MAX_DUMP_SIZE];
} *PANITHACK_PROCDUMP;

extern ANITHACK_PROCDUMP g_ProcessesDumps[MAX_PROCESS_DUMP];


#endif




