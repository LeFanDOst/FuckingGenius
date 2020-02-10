#ifndef KEYTYPES_HPP
#define KEYTYPES_HPP

#include "../System/OS.hpp"

#if defined(WINDOWS)
	#include <windows.h>
#endif

#include <sstream>

// https://docs.microsoft.com/fr-fr/windows/win32/inputdev/using-keyboard-input
// https://docs.microsoft.com/fr-fr/windows/win32/inputdev/virtual-key-codes
// 

namespace FG // FuckingGenius
{
	typedef enum
	{
		// Capital letters
		A = 0x0041,
		B = 0x0042,
		C = 0x0043,
		D = 0x0044,
		E = 0x0045,
		F = 0x0046,
		G = 0x0047,
		H = 0x0048,
		I = 0x0049,
		J = 0x004A,
		K = 0x004B,
		L = 0x004C,
		M = 0x004D,
		N = 0x004E,
		O = 0x004F,
		P = 0x0050,
		Q = 0x0051,
		R = 0x0052,
		S = 0x0053,
		T = 0x0054,
		U = 0x0055,
		V = 0x0056,
		W = 0x0057,
		X = 0x0058,
		Y = 0x0059,
		Z = 0x005A,
		// Small letters
		a = 0x0061,
		b = 0x0062,
		c = 0x0063,
		d = 0x0064,
		e = 0x0065,
		f = 0x0066,
		g = 0x0067,
		h = 0x0068,
		i = 0x0069,
		j = 0x006A,
		k = 0x006B,
		l = 0x006C,
		m = 0x006D,
		n = 0x006E,
		o = 0x006F,
		p = 0x0070,
		q = 0x0071,
		r = 0x0072,
		s = 0x0073,
		t = 0x0074,
		u = 0x0075,
		v = 0x0076,
		w = 0x0077,
		x = 0x0078,
		y = 0x0079,
		z = 0x007C,
		// F[num] keys
		F1 = 0xFFBE,
		F2 = 0xFFBF,
		F3 = 0xFFC0,
		F4 = 0xFFC1,
		F5 = 0xFFC2,
		F6 = 0xFFC3,
		F7 = 0xFFC4,
		F8 = 0xFFC5,
		F9 = 0xFFC6,
		F10 = 0xFFC7,
		F11 = 0xFFC8,
		F12 = 0xFFC9,
		// Maj keys
		LeftMaj = 0xFFE1,
		RightMaj = 0xFFE2,
		// Ctrl keys
		LeftCtrl = 0xFFE3,
		RightCtrl = 0xFFE4,
		CapsLock = 0xFFE5,
		// Signs keys
		Asterisk = 0x002A,
		Plus = 0x002B,
		Comma = 0x002C,
		Minus = 0x002D,
		Dot = 0x002E,
		Slash = 0X002F,
		// Number keys
		Zero = 0x0030,
		One = 0x0031,
		Two = 0x0032,
		Three = 0x0033,
		Four = 0x0034,
		Five = 0x0035,
		Six = 0x0036,
		Seven = 0x0037,
		Eight = 0x0038,
		Nine = 0x0039
	} KT; // KeyTypes
};

int keyToInt(int key);
char keyToChar(int key);

#endif // KEYTYPES_HPP