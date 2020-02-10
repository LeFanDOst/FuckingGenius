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