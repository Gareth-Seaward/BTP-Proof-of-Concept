#ifndef ENUMWINDOWSPROC_H
#define ENUMWINDOWSPROC_H

#include <windef.h>
#include "CallToManaged.h"
#include <msclr\auto_gcroot.h>

class EnumWindowsProc 
{
private:
	msclr::auto_gcroot<CallbackManager^> m_clr;

public:
	static BOOL CALLBACK fwd(HWND hwnd, LPARAM lParam);
	EnumWindowsProc(CallbackManager ^clr);
};

#endif
