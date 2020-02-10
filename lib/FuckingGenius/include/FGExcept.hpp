#ifndef DEF_FGEXCEPT
#define DEF_FGEXCEPT

#include "RunExcept.hpp"

class FGExcept : public RunExcept
{
	public:
		FGExcept(char const* message, char const* file, int line, char const* date, char const* time, char const* function) noexcept;
		FGExcept(FGExcept const& src) noexcept;
		~FGExcept() noexcept;
		
		virtual inline char const* what() const noexcept override { return m_message.c_str(); }
	
	private:
		std::string m_message;
};

#define _FGExcept( message ) FGExcept(message, __FILE__, __LINE__, __DATE__, __TIME__, __func__)

#endif // DEF_FGEXCEPT