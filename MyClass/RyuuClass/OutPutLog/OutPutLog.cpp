/*+===================================================================
	File: OutPutLog.cpp
	Summary: �f�o�b�O�ȂǂŎg�p
	Author: AT12C192 01 �ؗY��Y
	Date: 04/05/2024 ����쐬
			/10 �֐��̒ǉ� [IntegerSort]
			/11 �֐��̒ǉ� [SetStrArrayData,StringSort]
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
