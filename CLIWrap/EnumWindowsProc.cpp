#include "stdafx.h"
//#include <windef.h>
#include <windows.h>
#include "EnumWindowsProc.h"

EnumWindowsProc::EnumWindowsProc(CallbackManager ^clr)
{
	m_clr = clr;
}

BOOL CALLBACK EnumWindowsProc:: fwd(HWND hwnd, LPARAM lParam)
{
	return static_cast<EnumWindowsProc*>((void *)lParam)->m_clr->OnEnum((int)hwnd) ? TRUE : FALSE;
}