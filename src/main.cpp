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
		
	#endif
	
	return 0;
}
