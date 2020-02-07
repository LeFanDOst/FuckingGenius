#ifndef DEF_WINDOW
#define DEF_WINDOW

#include "FGTypes/FGTypeStyle.hpp"
#include "FGTypes/FGBasicTypes.hpp"
#include "FGExcept.hpp"

typedef unsigned int uint;

class Window
{
	public:
		// Third argument, "FGWin& win", is useless as fuck, now
		// ... I guess
		Window(int style, FG::BS::Handler hand, FG::BS::Win& win, FG::BS::Title winName = "");
		Window(Window const& src);
		~Window();
		
		inline uint getWindowCount() const { return m_windowCount; }
		
		void showThisFuckingWindow();
	
	private:
		FG::BS::Title m_winName;
		FG::BS::Handler& m_handler;
		FG::BS::Win& m_mainWindow;
		#if defined(WINDOWS)
			HWND m_window;
			MSG m_message;
			WNDCLASS m_winClass;
		#endif
		static uint m_windowCount;
	
	protected:
		#if defined(WINDOWS)
			inline HWND getHandler() const { return m_window; }
		#endif
};

#endif // DEF_WINDOW