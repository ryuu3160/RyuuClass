/*+===================================================================
	File: OutPutLog.cpp
	Summary: �f�o�b�O�ȂǂŎg�p����֐��̎���
	Author: AT12C192 01 �ؗY��Y
	Date: 04/05/2024 ����쐬
===================================================================+*/
#include "OutPutLog.hpp"
#include <Windows.h>
#include <stdlib.h>
#include <sstream>

void Error(LPCSTR In_cMsg)
{
	MessageBoxA(NULL, In_cMsg, "Error", MB_OK | MB_ICONERROR);
}

void Error(HWND In_hWnd, LPCSTR In_cMsg)
{
	MessageBoxA(In_hWnd, In_cMsg, "Error", MB_OK | MB_ICONERROR);
}

void OutputDebug(std::string In_strDebugMsg)
{
	OutputDebugStringA(In_strDebugMsg.c_str());
}
