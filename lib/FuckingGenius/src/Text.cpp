#include "../include/Text.hpp"

Text::Text() : m_string("") {}

Text::Text(char const* strC)
{
	std::ostringstream oss;
	
	oss << strC;
	
	m_string = oss.str();
}

Text::Text(std::string str) : Text(str.c_str()) {}

Text::~Text() {}


void Text::draw(FGWindow& win) const
{
	this->paintToWindow(win);
}


void Text::paintToWindow(FGWindow& win) const
{
	#if defined(WINDOWS)
		/*// Previous declarations.
		LOGFONT fontStruct;
		PAINTSTRUCT ps;
		HFONT font;
		HDC dc;
		
		// LOGFONT filling.
		ZeroMemory(&fontStruct, sizeof(LOGFONT));
		strcpy(fontStruct.lfFaceName, m_font.c_str());
		fontStruct.lfHeight = (m_rectPlacement.getTop() - m_rectPlacement.getBottom());
		fontStruct.lfWidth = 400;
		fontStruct.lfUnderline = m_underlining;
		
		// Font creation.
		font = CreateFontIndirect(&fontStruct);
		
		// Drawing surface recuperation.
		dc = BeginPaint(win.getWinPainting(), &ps);
		
		// Having a transparent background.
		SetBkMode(dc, TRANSPARENT);
		// Apply font to dc text.
		SelectObject(dc, font);
		// Apply text color to dc
		SetTextColor(dc, m_color);
		
		// Text displaying.
		TextOut(dc, m_rectPlacement.getLeft(), m_rectPlacement.getTop(), m_string.c_str(), m_string.length());
		
		// Surface and dc liberation.
		EndPaint(win.getWinPainting(), &ps);*/
		
		HDC hdc;
		PAINTSTRUCT ps;
		LOGFONT fontStruct;
		HFONT font;
		
		hdc = GetWindowDC(win.getWinPainting());
		
		ZeroMemory(&fontStruct, sizeof(LOGFONT));
		strcpy(fontStruct.lfFaceName, m_font.c_str());
		fontStruct.lfHeight = (m_rectPlacement.getTop() - m_rectPlacement.getBottom());
		fontStruct.lfWidth = 400;
		fontStruct.lfUnderline = m_underlining;
		
		font = CreateFontIndirect(&fontStruct);
		
		hdc = BeginPaint(win.getWinPainting(), &ps);
		
		SetBkMode(hdc, TRANSPARENT);
		SelectObject(hdc, font);
		SetTextColor(hdc, m_color);
		
		//TextOut(hdc, 10, 10, m_string.c_str(), strlen(m_string.c_str()));
		TextOut(hdc, m_rectPlacement.getLeft(), m_rectPlacement.getTop(), m_string.c_str(), m_string.length());
		
		EndPaint(win.getWinPainting(), &ps);
    #elif defined(LINUX)
        if(sizeof(win)!=0)
        {}
	#endif
}
