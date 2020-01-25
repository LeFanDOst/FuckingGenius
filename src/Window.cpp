#include "../include/Window.hpp"

#if defined(WINDOWS)
	LRESULT CALLBACK WinConstructCB(HWND win, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		switch(msg)
		{
			case WM_CREATE:
				return 0;
			break;
			case WM_DESTROY:
				PostQuitMessage(0);
				return 0;
			break;
			default:
				return DefWindowProc(win, msg, wParam, lParam);
			break;
		}
	}
#endif

Window::Window(int style, FGHandler hand, FGWin& win, FGTitle winName) : m_winName(winName), m_handler(hand), m_mainWindow(win)
{
	#if defined(WINDOWS)
		m_mainWindow = win;
		
		m_winClass.style = style;
		m_winClass.lpfnWndProc = WinConstructCB;
		m_winClass.cbClsExtra = 0;
		m_winClass.cbWndExtra = 0;
		m_winClass.hInstance = m_handler;
		m_winClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		m_winClass.hCursor = LoadCursor(NULL, IDC_ARROW);
		m_winClass.hbrBackground = (HBRUSH)(1 + COLOR_BTNFACE);
		m_winClass.lpszMenuName = NULL;
		m_winClass.lpszClassName = "Window";
		
		if(!RegisterClass(&m_winClass))
			throw _RunExcept("ERROR : Cannot create a new window.");
			//throw _FGExcept("ERROR : Cannot create a new window.");
		
		m_mainWindow = CreateWindow("Window", m_winName, FG::TS::DynamicPos, CW_USEDEFAULT, CW_USEDEFAULT, 400, 300, NULL, NULL, m_handler, NULL);
	#endif
}

Window::Window(Window const& src) : Window(src.m_winClass.style, src.m_handler, *(new FGWin(src.m_mainWindow)), src.m_winName) {}

Window::~Window() {}


void Window::showThisFuckingWindow()
{
	#if defined(WINDOWS)
		ShowWindow(m_mainWindow, SW_SHOW);
	#endif
}