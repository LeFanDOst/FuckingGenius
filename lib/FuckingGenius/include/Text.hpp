#ifndef DEF_TEXT
#define DEF_TEXT

#include "Window.hpp"
#include "RectDescription.hpp"
#include <sstream>
#include <string>

class Text
{
	public:
		Text();
		Text(char const* strC);
		Text(std::string str);
		~Text();
		
		inline RectDescription getPlacement() const { return m_rectPlacement; }
		
		inline void setPlacement(RectDescription rp) { m_rectPlacement = rp; }
		inline void setString(std::string str) { m_string = str; }
		
		virtual void draw(FGWindow& win) const;
		inline std::string toString() const { return m_string; }
	
	private:
		std::string m_string;
		RectDescription m_rectPlacement;
};

#endif // DEF_TEXT