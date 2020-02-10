#ifndef INCLUDES_HPP
#define INCLUDES_HPP

#include <iostream>
#include "Events.hpp"

#if defined(WINDOWS)
	#include <windows.h>
	#define THE_MAIN_IS int WinMain(FGHandler current, FGHandler before, LPSTR command, int viewMode)
	#define KAY_SHUT_UP_WARNS std::cout << current << " " << before << " " << command << " " << viewMode << std::endl;
#elif defined(LINUX)
	#define THE_MAIN_IS int main(int argc, char** argv)
	#define KAY_SHUT_UP_WARNS std::cout << argc << " " << argv[0] << std::endl;
#else
	#warning "This OS isn't supported by the GUI library."
	#define THE_MAIN_IS int main(int argc, char** argv)
	#define KAY_SHUT_UP_WARNS std::cout << argc << " " << argv[0] << std::endl;
#endif

#endif // INCLUDES_HPP