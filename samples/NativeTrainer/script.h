#include "..\..\inc\natives.h"
#include "..\..\inc\types.h"
#include "..\..\inc\enums.h"

#include "..\..\inc\main.h"
#include <Psapi.h>

void ScriptMain();




/*MODULEINFO g_MainModuleInfo = { 0 };




DWORD64 TunablesPointer()
{
	return *reinterpret_cast<DWORD64*>(DWORD64(g_MainModuleInfo.lpBaseOfDll) + *reinterpret_cast<int*>(Pattern::Scan(g_MainModuleInfo, "48 8B 8C C2 ? ? ? ? 48 85 C9 74 19") + 4) + 8) + 8;
}

void SetName(char* name);
DWORD64 TunablesPointer();

template <typename T> void SetTunable(int index, T value)
{
	static DWORD64 tunablesPointer = TunablesPointer();
	*reinterpret_cast<T*>(tunablesPointer + index * 8) = value;
}

template <typename T> T GetTunable(int index)
{
	static DWORD64 tunablesPointer = TunablesPointer();
	return *reinterpret_cast<T*>(tunablesPointer + index * 8);
}
*/