#ifndef TYPESTYLE_HPP
#define TYPESTYLE_HPP

#include "../System/OS.hpp"

#if defined(WINDOWS)
	#include <windows.h>
#endif

namespace FG // FuckingGenius
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
};

#endif // TYPESTYLE_HPP