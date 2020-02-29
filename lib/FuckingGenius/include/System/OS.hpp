#ifndef OS_HPP
#define OS_HPP

/*! \page page1 OS macros
 * \par Use of these macros :
 * 		These macros are used to detect the Operating System used by the platform where the code is compiled. It permit to use the conditional compilation.
 * \par List of the differents macros :
 * 		A table of the defined macros will be give later. But the macros defines these OS/Standards :
 * 		- Unix Environment
 * 		- Linux
 * 		- POSIX Systems
 * 		- Windows
 * 		- MacOS
 * 		- Etc.
 * 		The table of the macros is :
 * 		| Name of the macro | OS supported     |
 * 		| :---------------: | :--------------: |
 * 		| WINDOWS           | Windows          |
 * 		| UNIX_ENVIRONMENT  | Unix environment |
 * 		| LINUX             | Linux kernel     |
 * 		| MACOS             | MacOS            |
 * 		| BSD_ENV           | BSD environment  |
 * 		| BSD_OS            | BSD OS           |
 * 		| AMIGAOS           | AmigaOS          |
 * 		| ANDROID           | Android          |
 * 		| :---------------: | :--------------: |
 *
 * 		| Name of the macro | Standard supported |
 * 		| :---------------: | :----------------: |
 * 		| POSIX_ENV         | POSIX environment  |
 * 		| POSIX_SYSTEM      | POSIX system       |
 * 		| CYGWIN_SYS        | Cygwin             |
 */

/*! \file OS.hpp
 * \brief Define some OS macros.
 * \details This file define differents macros to detect which Operating System is used on a system (i.e. a computer).
 * \author LeFan D'ost.
 * \date 29-01-2020.
 * \version 0.2
 */

// Macro definitions to conditional compilation, depending on the OS.
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(WINDOWS) || defined(__WINDOWS__) || defined(_Windows) || defined(_WIN64) || defined(_WIN16) || defined(__TOS_WIN__)
	#ifndef WINDOWS
		#define WINDOWS /*!< This macro is defined by compiler if the OS is Windows. */
	#endif // WINDOWS
#elif defined(__linux__) || defined(linux) || defined(__linux) // WARNING : the macros "linux" and "__linux" are obsolete because not POSIX compliant.
	#ifndef LINUX
		#define LINUX /*!< This macro is defined by compiler if the OS is based on a Linux kernel. */
	#endif
#elif defined(unix) || defined(UNIX) || defined(__UNIX__) || defined(__unix__) || defined(__unix)
	#ifndef UNIX_ENVIRONMENT
		#define UNIX_ENVIRONMENT /*!< This macro is defined by compiler if the OS is a Unix environment. */
	#endif
#elif defined(__APPLE__) || defined(__MACH__) || defined(Macintosh) || defined(macintosh)
	#ifndef MACOS
		#define MACOS /*!< This macro is defined by compiler if the OS is a MacOS system. */
	#endif
#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__bsdi__) || defined(__DragonFly__) || defined(_SYSTYPE_BSD)
	#ifndef BSD_ENV
		#define BSD_ENV /*!< This macro is defined by compiler if the OS is a BSD environment. */
	#endif
#elif defined(__bsdi__)
	#ifndef BSD_OS
		#define BSD_OS /*!< This macro is defined by compiler if the OS is BSD/OS. */
	#endif
#elif defined(AMIGA) || defined(__amigaos__)
	#ifndef AMIGAOS
		#define AMIGAOS /*!< This macro is defined by compiler if the OS is AmigaOS. */
	#endif
#elif defined(__ANDROID__)
	#ifndef ANDROID
		#define ANDROID /*!< This macro is defined by compiler if the OS is Android. */
	#endif
#endif

// Macro definitions to conditional compilation, depending on the
// standard/system.
#if defined(POSIX) || defined(__POSIX__)
	#ifndef POSIX_SYSTEM
		#define POSIX_SYSTEM /*!< This macro is defined by compiler if the OS is a Posix system. */
	#endif
#endif

#if defined(CYGWIN)
	#ifndef CYGWIN_SYS
		#define CYGWIN_SYS /*!< This macro is defined by compiler if the OS is Cygwin. */
	#endif
#endif

#if defined(POSIX_SYSTEM) || defined(UNIX_ENVIRONMENT) || defined(__linux__)
	#ifndef POSIX_ENV
		#define POSIX_ENV
	#endif
#endif

#endif // OS_HPP
