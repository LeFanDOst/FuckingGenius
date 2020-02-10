#ifndef EVENTTYPES_HPP
#define EVENTTYPES_HPP

#include "../System/OS.hpp"

#if defined(WINDOWS)
	#include <windows.h>
#endif

namespace FG // FuckingGenius
{
	typedef enum
	{
		#if defined(WINDOWS)
			Destroy = WM_DESTROY,
			Create = WM_CREATE
		#elif defined(LINUX)
			Destroy = 0,
			Create = 1
		#endif
	} ET; // EventTypes
};

#endif // EVENTTYPES_HPP