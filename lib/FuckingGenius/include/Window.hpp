#ifndef DEF_WINDOW
#define DEF_WINDOW

#include "Types/WindowTypes.hpp"
#include "Types/TypeStyle.hpp"
#include "Types/KeyTypes.hpp"
#include "Types/TextTypes.hpp"
#include "Values/BasicValues.hpp"
#include "FGExcept.hpp"

#if defined(LINUX)
	#include <X11/Xlib.h>
#endif

#if !defined(None)
    #define None NULL
#endif

typedef unsigned int uint;

class FGWindow
{
	public:
		// Third argument, "FGWin& win", is useless as fuck, now
		// ... I guess
		FGWindow(int style, FGTitle winName = "");
		FGWindow(FGWindow const& src);
		~FGWindow();
		
		inline uint getWindowCount() const { return m_windowCount; }
		inline FGWin getWinPainting() const { return m_mainWindow; }
		
		#if defined(WINDOWS)
			inline MSG getMessage() const { return m_message; }
		#elif defined(LINUX)
			inline bool getMessage() const { return true; }
            Display* getWindowDisplayer();
		#endif
		
		void showThisFuckingWindow();
		void updateWindow();
		void drawText(std::string mig);
		void redraw();
	
	private:
		FGTitle m_winName;
		FGHandler/*&*/ m_handler;
		FGWin/*&*/ m_mainWindow;
		int m_style;
		#if defined(WINDOWS)
			HWND m_window;
			MSG m_message;
			WNDCLASS m_winClass;
		#elif defined(LINUX)
			Display*  m_displayer;
			int m_screen;
		#endif
		static uint m_windowCount;
};

#endif // DEF_WINDOW
