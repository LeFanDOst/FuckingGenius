#include <iostream>
#include "../include/Includes.hpp"

//int main()
THE_MAIN_IS
{
	KAY_SHUT_UP_WARNS
	FGWin thatsTheWindow;
	Window myWin(0, current, thatsTheWindow, "Fuck off, Win32 Fucking API");
	myWin.showThisFuckingWindow();
	
	myWin.updateWindow();
	
	#if defined(WINDOWS)
		MSG msg = myWin.getMessage();
		while(GetMessage(&msg, NULL, 0, 0))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	#elif defined(LINUX)
		
	#endif
	
	return 0;
}