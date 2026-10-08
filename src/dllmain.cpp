#include <Windows.h>
#include "Hook.h"

static HMODULE g_module=nullptr;
BOOL APIENTRY DllMain(HMODULE hModule,DWORD reason,LPVOID){
    if(reason==DLL_PROCESS_ATTACH){g_module=hModule;DisableThreadLibraryCalls(hModule);Hook::Start(hModule);}
    return TRUE;
}
