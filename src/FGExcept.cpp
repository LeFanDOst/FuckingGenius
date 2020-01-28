#include "../include/FGExcept.hpp"
#include <iostream>

FGExcept::FGExcept(char const* message, char const* file, int line, char const* date, char const* time, char const* function) noexcept : RunExcept(message, file, line, date, time, function)
{
	std::ostringstream ossWhat;
	
	ossWhat << RunExcept::what() << "\n"
			<< "In file : " << this->inFile() << "\n"
			<< "In function : " << this->inFunction() << "\n"
			<< "At line : " << this->atLine() << "\n"
			<< "File compiled on '" << this->onDate() << "' at '" << this->atTime() << "'." << "\n";
	
	std::cout << ossWhat.str().c_str() << std::endl;
	
	m_message = ossWhat.str();
}

FGExcept::FGExcept(FGExcept const& src) noexcept : FGExcept(src.what(), src.inFile(), src.atLine(), src.onDate(), src.atTime(), src.inFunction()) {}

FGExcept::~FGExcept() noexcept {}