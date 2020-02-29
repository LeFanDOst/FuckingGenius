#ifndef WINDOWTYPES_HPP
#define WINDOWTYPES_HPP

#include "../System/OS.hpp"

#if defined(WINDOWS)
	#include <windows.h>
#endif

#if defined(WINDOWS)
	typedef HWND FGWin;
	typedef HINSTANCE FGHandler;
	typedef LPCTSTR FGTitle;
	/*struct GuiInfo
	{
		HINSTANCE window;
	};*/
#elif defined(LINUX)
    #define FGWin Window
	typedef unsigned char FGHandler;
	typedef char const* FGTitle;
	/*struct GuiInfo
	{
		int window;
	};*/
#endif

#endif // WINDOWTYPES_HPP
