#include <iostream>
#include "../include/Includes.hpp"

//int main()
//THE_MAIN_IS
int main()
{
	//KAY_SHUT_UP_WARNS
	FGWindow myWin(0, "Fuck off, Win32 Fucking API");
	myWin.showThisFuckingWindow();
	
	myWin.updateWindow();
	
#if defined(WINDOWS)
	Text myBeautifulText("Hello, world !");

	myBeautifulText.setPlacement(RectDescription(0, 0, 300, 400));
	myBeautifulText.setUnderlining(true);
	myBeautifulText.setFont("Arial");
	myBeautifulText.setColor(RGB(255, 0, 0));
	
	myBeautifulText.draw(myWin);
	//myWin.drawText("Hello, world !");

	myWin.redraw();
#endif	
	
	#if defined(WINDOWS)
		MSG msg = myWin.getMessage();
		while(GetMessage(&msg, NULL, 0, 0))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			
			msg = myWin.getMessage();
		}
	#elif defined(LINUX)
		XEvent evmt;XSelectInput(myWin.getWindowDisplayer(),myWin.getWinPainting(),ButtonPressMask| EnterWindowMask| LeaveWindowMask);
		for (;;)
		{
			XNextEvent(myWin.getWindowDisplayer(), &evmt);
			switch(evmt.type)
			{
				case ButtonPress :
					exit(0);
				case EnterNotify:
					XSetWindowBorderWidth(myWin.getWindowDisplayer(),myWin.getWinPainting(),4);
				break;
				case LeaveNotify:
					XSetWindowBorderWidth(myWin.getWindowDisplayer(),myWin.getWinPainting(),2);
				break;
			}
		}
	#endif
	
	return 0;
}
