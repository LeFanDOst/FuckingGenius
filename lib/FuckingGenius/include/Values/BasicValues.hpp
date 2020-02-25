#ifndef BASICVALUES_HPP
#define BASICVALUES_HPP

#include "../System/OS.hpp"

#if defined(WINDOWS)
	#include <windows.h>
#endif

#if defined(WINDOWS)
	#define FG_TRUE TRUE
	#define FG_FALSE FALSE
#elif defined(LINUX)
	#define FG_TRUE true
	#define FG_FALSE false
#endif

#endif // BASICVALUES_HPP