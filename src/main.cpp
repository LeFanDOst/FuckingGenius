#include <iostream>
#include "../include/Includes.hpp"

//int main()
THE_MAIN_IS
{
	KAY_SHUT_UP_WARNS
	FGWin thatsTheWindow;
	Window myWin(0, current, thatsTheWindow, "Fuck off, Win32 Fucking API");
	myWin.showThisFuckingWindow();
	
	std::cout << "1" << std::endl;
	
	std::cout << myWin.getWindowCount() << std::endl;
	
	Window otherWin(myWin);
	
	std::cout << "2" << std::endl;
	
	otherWin.showThisFuckingWindow();
	
	std::cout << "3" << std::endl;
	
	std::cout << myWin.getWindowCount() << std::endl;
	std::cout << otherWin.getWindowCount() << std::endl;
	
	//throw _FGExcept("ERREUR");
	throw _RunExcept("ERREUR");
	
	return 0;
}