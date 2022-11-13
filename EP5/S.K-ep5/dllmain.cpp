#include "pch.h"
Shaiya DLL;
//https://github.com/SK-Shaiya
//if you get stuck :D just add me   [s.k#8903]
extern  "C"  __declspec(dllexport) void __cdecl Main()
{
    DLL.Title = AY_OBFUSCATE("Shaiya AC");
    DLL.Error = AY_OBFUSCATE("Security validation failed.");
}

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:

        // DLL INJECTION 
        Main();

        // FEATURES PART
        StatPoints();
        SkillBarFunc();
       
        FpsSettings();
        ShaiyaServer();
        Init();
        MiniIcon();
       
      
     

        

    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

