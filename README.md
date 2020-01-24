# FuckingGenius
Development of a cross-plateform GUI library in C++.

## What's that ?

FuckingGenius is a cross-plateform GUI library, in development in C++. This library
is developped in parallel on Windows 10 and on Ubuntu. Also, a complete compatibility
isn't sure on all Windows versions or all Linux distributions.

## Compilation

The compilation of this library is realized with a Makefile (which use GNU make).

### Compilation on Linux

To compile the current project (a temporary form of the library) on Linux, you have to
open the Makefile and set the value of the `Linux` variable at `yes`, before type the command
`make` in a terminal placed in the "root directory".

### Compile on Windows

To compile the current project (a temporary form of the library) on Linux, you have to
open the Makefile and set the value of the `Linux` variable at `no`, before type the command
`make` in a terminal placed in the "root directory".

### Note about the Makefile

At the beginning of the Makefile, you can see some variables, like `Linux`, `Debug`, `CppVersion`
or other. You can set their values at `yes` or `no`, depending of your compilation usage.
See the [GNU Compiler documentation](https://gcc.gnu.org/onlinedocs/gcc/) to have an idea of the
compilers options used in the Makefile.

## Is the library finished ?

Clearly not. It's just beginning. And all your help is welcome. But I have some strict restrictions
dues to a fixed idea of this library.

So, my idea, for this library, is :

	* No use of CMake (just a Makefile, or a few sub-Makefiles)
	* No installation required (one of the reasons of the only use of Makefiles)
	* A cross-plateform library, usable no less than Windows and Linux
	* No dependencies, or no one which require any installation or a usage of CMake (so don't use Qt or SFML, for example)
	* A library which is a little bit complete (like window creation, event management, use of keys and mouse event, perhaps audio, etc.