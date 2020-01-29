#ifndef COMMAND_HPP
#define COMMAND_HPP

#include "OS.hpp"

// Macro definitions for DOS/Bash functions.
#if defined (WINDOWS)
	#define DEL "del" /*!< This macro defines the DOS function to deleting a file. */
	#define LIST "dir /b /s" /*!< This macro defines the DOS function to list files. */
#elif defined (LINUX) || defined (MACOS) // Macro LINUX or POSIX_ENV ? Dunno, have to test it.
	#define DEL "rm -f" /*!< This macro defines the BASH function to deleting a file. */
	#define LIST "ls -a" /*!< This macro defines the BASH function to list files. */
#endif

#include <sstream>
#include <cstdlib>

/*!< This macro delete a file with its filename. */
#define DELETEAFILEFORME( file ) \
		std::ostringstream ossDelFile; \
		ossDelFile << DEL << " " << file; \
		system(ossDelFile.str().c_str());

#endif // COMMAND_HPP