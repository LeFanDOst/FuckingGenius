#ifndef OS_HPP
#define OS_HPP

// Macro definitions to conditional compilation, depending on the OS.
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(WINDOWS) || defined(__WINDOWS__) || defined(_Windows) || defined(_WIN64) || defined(_WIN16) || defined(__TOS_WIN__)
	#ifndef WINDOWS
		#define WINDOWS /*!< This macro is defined by compiler if the OS is Windows. */
	#endif // WINDOWS
#elif defined(unix) || defined(UNIX) || defined(__UNIX__) || defined(POSIX) || defined(__POSIX__) || defined(CYGWIN) || defined(linux) || defined(__linux__) || defined(__linux)
	#ifndef POSIX
		#define POSIX /*!< This macro is defined by compiler if the OS is a Posix system. */
	#endif // POSIX
#elif defined(__APPLE__) || defined(__MACH__) || defined(Macintosh) || defined(macintosh)
	#ifndef MACOS
		#define MACOS /*!< This macro is defined by compiler if the OS is a MacOS system. */
	#endif // MACOS
#endif // WIN32 _WIN32 __WIN32__ WINDOWS __WINDOWS__ _Windows _WIN64 _WIN16 __TOS_WIN__ unix UNIX __UNIX__ POSIX __POSIX__ CYGWIN linux __linux__ __linux __APPLE__ __MACH__ Macintosh macintosh

#endif // OS_HPP