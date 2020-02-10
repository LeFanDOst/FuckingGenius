#ifndef DEF_WINDOW
#define DEF_WINDOW

#include "Types/TypeStyle.hpp"
#include "Types/KeyTypes.hpp"
#include "FGExcept.hpp"

typedef unsigned int uint;

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
		Window(int style, FGTitle winName = "");
		Window(Window const& src);
		~Window();
		
		inline uint getWindowCount() const { return m_windowCount; }
		
		#if defined(WINDOWS)
			inline MSG getMessage() const { return m_message; }
		#elif defined(LINUX)
			inline bool getMessage() const { return true; }
		#endif
		
		void showThisFuckingWindow();
		void updateWindow();
	
	private:
		FGTitle m_winName;
		FGHandler/*&*/ m_handler;
		FGWin/*&*/ m_mainWindow;
		#if defined(WINDOWS)
			HWND m_window;
			MSG m_message;
			WNDCLASS m_winClass;
		#endif
		static uint m_windowCount;
};

#endif // DEF_WINDOW