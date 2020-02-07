#ifndef FGBASICTYPES_HPP
#define FGBASICTYPES_HPP

#include "../System/OS.hpp"

#if defined(WINDOWS)
	#include <windows.h>
#endif

namespace FG // FuckingGenius
{
	namespace BS // BasicTypes
	{
		#if defined(WINDOWS)
			typedef HWND Win;
			typedef HINSTANCE Handler;
			typedef LPCTSTR Title;
			typedef BOOL Bool;
			typedef LPMSG EventMessage;
			/*struct GuiInfo
			{
				HINSTANCE window;
			};*/
		#elif defined(LINUX)
			typedef int Win;
			typedef unsigned char Handler;
			typedef char const* Title;
			typedef bool Bool;
			typedef char const* EventMessage;
			/*struct GuiInfo
			{
				int window;
			};*/
		#endif
	};
};

#endif // FGBASICTYPES_HPP