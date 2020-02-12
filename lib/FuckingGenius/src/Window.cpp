#include "../include/Window.hpp"
#include <iostream>

#if defined(WINDOWS)
	#ifndef PAINT_EVENT
		#define PAINT_EVENT WM_PAINT
	#endif
#endif

//Text txt;
std::string message = "";

FGHandler getAnHandler()
{
	#if defined(WINDOWS)
		return GetModuleHandle(NULL);
	#elif defined(LINUX)
		return 'a';
	#endif
}

FGWin returnAWin()
{
	#if defined(WINDOWS)
		return None;
	#elif defined(LINUX)
		return 0;
	#endif
}

#if defined(WINDOWS)
	void UpdateGraph(HWND hwnd, HDC dc)
	{
		RECT rc;
		GetClientRect(hwnd, &rc);
		//DrawText(dc, "Hello !", -1, &rc, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		std::cout << "message = " << message << std::endl;
		DrawText(dc, message.c_str(), -1, &rc, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
	
	
	
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
			case WM_PAINT:
			{
				RECT rToPaint;
				if(!GetUpdateRect(win, &rToPaint, FALSE))
				{
					return 0;
					break;
				}
				
				PAINTSTRUCT ps;
				BeginPaint(win, &ps);
				
				UpdateGraph(win, ps.hdc);
				
				EndPaint(win, &ps);
				
				return 0;
			}
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
					case FG::KT::Asterisk :
						PostMessage(win, PAINT_EVENT, 0, 0);
						std::cout << "Asterisk message = " << message << std::endl;
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

uint FGWindow::m_windowCount = 0;

FGWindow::FGWindow(int style, FGTitle winName) : m_winName(winName), m_handler(getAnHandler()), m_mainWindow(returnAWin()), m_style(style)
{
	++m_windowCount;
	
	style = style;
	
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
	#elif defined(LINUX)
		m_displayer = XOpenDisplay(NULL);
		
		if(m_displayer == NULL)
			throw _FGExcept("Holy shit");
		
		m_screen = DefaultScreen(m_displayer);
		
		m_mainWindow = XCreateSimpleWindow(m_displayer, RootWindow(m_displayer, m_screen), 10, 10, 100, 100, 1, BlackPixel(m_displayer, m_screen), WhitePixel(m_displayer, m_screen));
	#endif
}

//FGWindow::FGWindow(FGWindow const& src) : FGWindow(src.m_winClass.style, src.m_handler, *(new FGWin(src.m_mainWindow))) {}
FGWindow::FGWindow(FGWindow const& src) : FGWindow(src.m_style) {}

FGWindow::~FGWindow()
{
	--m_windowCount;
}


void FGWindow::showThisFuckingWindow()
{
	#if defined(WINDOWS)
		ShowWindow(m_mainWindow, SW_SHOW);
	#endif
}

void FGWindow::updateWindow()
{
	#if defined(WINDOWS)
		UpdateWindow(m_mainWindow);
	#endif
}

void FGWindow::drawText(std::string mig)
{
	#if defined(WINDOWS)
		/*if(mig == "")
			mig = mig;*/
		
		message = mig;
		/*// Previous declarations.
		LOGFONT fontStruct;
		PAINTSTRUCT ps;
		HFONT font;
		HDC dc;
		
		// LOGFONT filling.
		ZeroMemory(&fontStruct, sizeof(LOGFONT));
		strcpy(fontStruct.lfFaceName, "Arial");
		fontStruct.lfHeight = 32;
		//fontStruct.lfWidth = 400;
		fontStruct.lfUnderline = FG_TRUE;
		
		// Font creation.
		font = CreateFontIndirect(&fontStruct);
		
		// Drawing surface recuperation.
		dc = BeginPaint(m_mainWindow, &ps);
		
		// Having a transparent background.
		SetBkMode(dc, TRANSPARENT);
		// Apply font to dc text.
		SelectObject(dc, font);
		// Apply text color to dc
		SetTextColor(dc, RGB(255, 0, 0));
		
		// Text displaying.
		TextOut(dc, 10, 400, text.c_str(), text.length());
		
		// Surface and dc liberation.
		EndPaint(m_mainWindow, &ps);*/
		
		
	#endif
}