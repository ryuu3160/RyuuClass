//OutPutLog.cpp
#include "OutPutLog.h"
#include <Windows.h>
#include <stdlib.h>
#include <sstream>

namespace RYUU
{
void Error(LPCSTR msg)
{
	MessageBox(NULL, msg, "Error", MB_OK);
}

void OutputDebug(std::string DebugMsg)
{
	OutputDebugString(DebugMsg.c_str());
}
}