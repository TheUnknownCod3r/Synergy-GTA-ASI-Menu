// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once
#pragma warning(disable : 4996)
#define WIN32_LEAN_AND_MEAN
//#define __DEBUG

// Windows Header Files:
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <intrin.h>
#include <string>
#include <vector>
#include <sstream>
#include <Psapi.h>
#include <iostream>
#include <fstream>
#include <timeapi.h>

#pragma comment(lib, "winmm.lib")

extern MODULEINFO g_MainModuleInfo;

// Mine

#include "Pattern.h"



// Main
#include "script.h"



#define version 1301

void Tick();
void Run();
void RunUnreliable();