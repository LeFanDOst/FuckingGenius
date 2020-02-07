#include "../include/Window.hpp"
#include <iostream>

uint Window::m_windowCount = 0;

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

Window::Window(int style, FG::BS::Handler hand, FG::BS::Win& win, FG::BS::Title winName) : m_winName(winName), m_handler(hand), m_mainWindow(win)
{
	++m_windowCount;
	
	#if defined(WINDOWS)
		std::string className;
		std::ostringstream ossCN;
		
		ossCN << "Window" << m_windowCount;
		
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
		m_winClass.lpszClassName = ossCN.str().c_str();
		
		if(!RegisterClass(&m_winClass))
			throw _RunExcept("ERROR : Cannot create a new window.");
			//throw _FGExcept("ERROR : Cannot create a new window.");
		
		m_mainWindow = CreateWindow(ossCN.str().c_str(), m_winName, FG::TS::DynamicPos, CW_USEDEFAULT, CW_USEDEFAULT, 400, 300, NULL, NULL, m_handler, NULL);
	#elif defined(LINUX)
		std::cout << style << " " << hand << " " << win << " " << winName << std::endl;
	#endif
}

Window::Window(Window const& src) : Window(src.m_winClass.style, src.m_handler, *(new FG::BS::Win(src.m_mainWindow))) {}

Window::~Window()
{
	--m_windowCount;
	
	#if defined(WINDOWS)
		delete[] m_winName;
		m_winName = nullptr;
	#endif
}


void Window::showThisFuckingWindow()
{
	#if defined(WINDOWS)
		ShowWindow(m_mainWindow, SW_SHOW);
	#endif
}