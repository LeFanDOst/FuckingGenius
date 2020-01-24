#ifndef DEF_WINDOW
#define DEF_WINDOW

#include "TypeStyle.hpp"
#include "FGExcept.hpp"

#if defined(WINDOWS)
	typedef HWND FGWin;
	typedef HINSTANCE FGHandler;
	typedef LPCTSTR FGTitle;
	/*struct GuiInfo
	{
		HINSTANCE window;
	};*/
#elif defined(POSIX)
	typedef int FGWin;
	typedef unsigned char FGHandler;
	typedef char const* FGTitle;
	/*struct GuiInfo
	{
		int window;
	};*/
#endif

class Window
{
	public:
		// Third argument, "FGWin& win", is useless as fuck, now
		// ... I guess
		Window(int style, FGHandler hand, FGWin& win, FGTitle winName);
		//Window(Window const& src);
		~Window();
		
		void showThisFuckingWindow();
	
	private:
		FGTitle m_winName;
		FGHandler& m_handler;
		FGWin& m_mainWindow;
		#if defined(WINDOWS)
			HWND m_window;
			MSG m_message;
			WNDCLASS m_winClass;
		#endif
};

#endif // DEF_WINDOW