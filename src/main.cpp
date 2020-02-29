#include <iostream>
#include <thread>
#include <chrono>
#include "../include/Includes.hpp"

void wsh(FGWindow& win)
{
	#if defined(WINDOWS)
		//MSG msg = myWin.getMessage();
		MSG msg = win.getMessage();
		while(GetMessage(&msg, NULL, 0, 0))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			
			//msg = myWin.getMessage();
			msg = win.getMessage();
		}
	#elif defined(LINUX)
		
	#endif
}

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
<<<<<<< HEAD
	
	//myBeautifulText.setPlacement(RectDescription(0, 0, 50, 50));
	myBeautifulText.setX(50);
	myBeautifulText.setY(50);
	myBeautifulText.setHeight(50);
	myBeautifulText.setWidth(50);
=======

	myBeautifulText.setPlacement(RectDescription(0, 0, 300, 400));
>>>>>>> refs/remotes/origin/master
	myBeautifulText.setUnderlining(true);
	myBeautifulText.setFont("Arial");
	myBeautifulText.setColor(RGB(255, 0, 0));
	
	myBeautifulText.draw(myWin);
	//myWin.drawText("Hello, world !");

	myWin.redraw();
#endif	
	
	std::thread threadEventGestion(wsh, std::ref(myWin));
	
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
	std::chrono::steady_clock::time_point end;
	
	while(true)
	{
		end = std::chrono::steady_clock::now();
		
		if(std::chrono::duration_cast<std::chrono::seconds>(end - start).count() > 2)
		{
			myWin.redraw();
			
			start = std::chrono::steady_clock::now();
			//end = std::chrono::steady_clock::now();
		}
	}
	
	return 0;
}
