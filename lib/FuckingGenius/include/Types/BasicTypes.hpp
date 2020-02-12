#ifndef BASICTYPES_HPP
#define BASICTYPES_HPP

#include "../System/OS.hpp"

#if defined(WINDOWS)
	#include <windows.h>
#endif

/*namespace FG // FuckingGenius
{
	typedef enum
	{
		#if defined(WINDOWS)
			DynamicPos = WS_OVERLAPPEDWINDOW,
			VisibleStyle = WS_VISIBLE
		#elif defined(POSIX)
			DynamicPos = 0,
			VisibleStyle = 1
		#endif
	} TS; // TypeStyle
};*/

#if defined(WINDOWS)
	typedef BOOL FGBool;
	typedef LPMSG FGEventMessage;
	typedef UINT FGUint;
	typedef LONG FGLong;
	typedef COLORREF FGColorType;
	#define FG_NULL_HANDLE NULL
#elif defined(LINUX) || defined(__arm__)
	typedef bool FGBool;
	typedef char const* FGEventMessage;
	typedef unsigned int FGUint;
	typedef long FGLong;
	typedef unsigned int FGColorType;
	#define FG_NULL_HANDLE 0
#endif

#endif // BASICTYPES_HPP
