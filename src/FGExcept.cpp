#include "../include/FGExcept.hpp"

FGExcept::FGExcept(char const* message, char const* file, int line, char const* date, char const* time, char const* function) noexcept : RunExcept(message, file, line, date, time, function)
{
	std::ostringstream ossWhat;
	
	ossWhat << RunExcept::what() << std::endl
			<< "In file : " << this->inFile() << std::endl
			<< "In function : " << this->inFunction() << std::endl
			<< "At line : " << this->atLine() << std::endl
			<< "File compiled on '" << this->onDate() << "' at '" << this->atTime() << "'." << std::endl;
	
	m_message = ossWhat.str();
}

FGExcept::FGExcept(FGExcept const& src) noexcept : FGExcept(src.what(), src.inFile(), src.atLine(), src.onDate(), src.atTime(), src.inFunction()) {}

FGExcept::~FGExcept() noexcept {}