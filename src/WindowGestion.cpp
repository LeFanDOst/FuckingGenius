#include "../include/WindowGestion.hpp"
#include <iostream>

class EventWindow;

#if defined(WINDOWS)
	#define EVTFUNC(evtMsg, win) GetMessage(&evtMsg, win.getHandler(), 0, 0)
#elif defined(LINUX)
	#define EVTFUNC(evtMsg, win)  \
		std::cout << evtMsg << " " << win.getNbCount() << std::endl; \
		true
#endif

class EventWindow : public Window
{
	public:
		EventWindow(int style, FG::BS::Handler hand, FG::BS::Win& win, FG::BS::Title winName = "") : Window(style, hand, win, winName) {}
		
		EventWindow(Window const& src) : Window(src) {}
		
		EventWindow(EventWindow const& src) : Window(src) {}
		
		~EventWindow() {}
		
		#if defined(WINDOWS)
			inline HWND getHandler() const { return Window::getHandler(); }
		#endif
};

FG::BS::Bool eventLoop(FG::BS::EventMessage evtMsg, Window win)
{
	EventWindow evtWin(win);
	
	#if defined(WINDOWS)
		return GetMessage(&evtMsg, NULL, 0, 0);//here
	#elif defined(LINUX)
		EVTFUNC(evtMsg, evtWin);
	#else
		#warning "This OS isn't supported by the GUI library."
		EVTFUNC(evtMsg, evtWin);
	#endif
}