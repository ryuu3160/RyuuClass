/*+===================================================================
	File: OutPutLog.cpp
	Summary: デバッグなどで使用
	Author: AT12C192 01 青木雄一郎
	Date: 04/05/2024 初回作成
			/10 関数の追加 [IntegerSort]
			/11 関数の追加 [SetStrArrayData,StringSort]
===================================================================+*/
#include "OutPutLog.hpp"
#include <Windows.h>
#include <stdlib.h>
#include <sstream>

void Error(LPCSTR msg)
{
	MessageBox(NULL, msg, "Error", MB_OK | MB_ICONERROR);
}

void Error(HWND hWnd, LPCSTR msg)
{
	MessageBox(hWnd, msg, "Error", MB_OK | MB_ICONERROR);
}

void OutputDebug(std::string DebugMsg)
{
	OutputDebugString(DebugMsg.c_str());
}
