#include "../include/Window.hpp"
#include <iostream>

#define None NULL

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
			case WM_CHAR:
			{
				switch(wParam)
				{
					case FG::KT::A :
						std::cout << keyToInt(FG::KT::A) << std::endl;
					break;
					case FG::KT::a :
						std::cout << keyToInt(FG::KT::a) << std::endl;
					break;
					default:
					break;
				}
			}
			return 0;
			break;
			case FG::KT::A:
				std::cout << keyToInt(FG::KT::A) << std::endl;
				return 0;
			break;
			default:
				return DefWindowProc(win, msg, wParam, lParam);
			break;
		}
	}
#endif

Window::Window(int style, FGTitle winName) : m_winName(winName), m_handler(GetModuleHandle(NULL)), m_mainWindow(None)
{
	++m_windowCount;
	
	#if defined(WINDOWS)
		std::string className;
		std::ostringstream ossCN;
		
		//m_handler = GetModuleHandle(NULL);
		
		ossCN << "Window" << m_windowCount;
		
		//m_mainWindow = None;
		
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
	#endif
}

//Window::Window(Window const& src) : Window(src.m_winClass.style, src.m_handler, *(new FGWin(src.m_mainWindow))) {}
Window::Window(Window const& src) : Window(src.m_winClass.style) {}

Window::~Window()
{
	--m_windowCount;
}


void Window::showThisFuckingWindow()
{
	#if defined(WINDOWS)
		ShowWindow(m_mainWindow, SW_SHOW);
	#endif
}

void Window::updateWindow()
{
	#if defined(WINDOWS)
		UpdateWindow(m_mainWindow);
	#endif
}