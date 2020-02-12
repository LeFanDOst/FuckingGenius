#ifndef DEF_TEXT
#define DEF_TEXT

//#include "Window.hpp"
#include "RectDescription.hpp"
#include <sstream>
#include <string>

class Text
{
	public:
		Text();
		Text(char const* strC);
		Text(std::string str);
		virtual ~Text();
		
		inline std::string getString() const { return m_string; }
		
		#if defined(WINDOWS)
			inline RectDescription getPlacement() const { return m_rectPlacement; }
			inline FGBool getUnderlining() const { return m_underlining; }
			inline std::string getFont() const { return m_font; }
			inline FGColorType getColor() const { return m_color; }
		#endif
		
		inline void setString(std::string str) { m_string = str; }
		
		#if defined(WINDOWS)
			inline void setPlacement(RectDescription rp) { m_rectPlacement = rp; }
			inline void setUnderlining(FGBool underlining) { m_underlining = underlining; }
			inline void setFont(std::string font) { m_font = font; }
			inline void setColor(FGColorType color) { m_color = color; }
		#endif
		
		virtual void draw(FGWindow& win) const;
		inline std::string toString() const { return m_string; }
	
	private:
		std::string m_string;
		
		#if defined(WINDOWS)
			RectDescription m_rectPlacement;
			FGBool m_underlining;
			std::string m_font;
			FGColorType m_color;
		#endif
	
	protected:
		virtual void paintToWindow(FGWindow& win) const;
};

#endif // DEF_TEXT