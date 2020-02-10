#include "../include/Types/KeyTypes.hpp"

int keyToInt(int key)
{
	unsigned int nb;
	std::stringstream ss;
	
	ss << std::hex << key;
	ss >> nb;
	
	return static_cast<int>(nb);
}

char keyToChar(int key)
{
	return static_cast<char>(keyToInt(key));
}