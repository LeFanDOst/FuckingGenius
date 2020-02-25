#ifndef TEXTTYPES_HPP
#define TEXTTYPES_HPP

#include "../System/OS.hpp"

#if defined(WINDOWS)
	#include <windows.h>
#endif

// https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-drawtext

namespace FG // FuckingGenius
{
	typedef enum
	{
		#if defined(WINDOWS)
			Bottom = DT_BOTTOM,
			Center = DT_CENTER,
			Left = DT_LEFT,
			Right = DT_RIGHT,
			Top = DT_TOP,
			SingleLine = DT_SINGLELINE,
			VerticalCenter = DT_VCENTER
		#elif defined(LINUX)
			Bottom = 0,
			Center = 1,
			Left = 2,
			Right = 3,
			Top = 4,
			SingleLine = 5,
			VerticalCenter = 6
		#endif
	} STT; // StyleTextTypes
};

#endif // TEXTTYPES_HPP