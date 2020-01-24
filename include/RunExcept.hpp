#ifndef DEF_RUNEXCEPT
#define DEF_RUNEXCEPT

#include <sstream>
#include <string>
#include <exception>

class RunExcept : public std::exception
{
	public:
		RunExcept(char const* message, char const* file, int line, char const* date, char const* time, char const* function) noexcept;
		RunExcept(RunExcept const& src) noexcept;
		~RunExcept() noexcept;
		
		virtual inline char const* what() const noexcept override { return m_message.c_str(); }
		inline char const* inFile() const noexcept { return m_file.c_str(); }
		inline int atLine() const noexcept { return m_line; }
		inline char const* onDate() const noexcept { return m_date.c_str(); }
		inline char const* atTime() const noexcept { return m_time.c_str(); }
		inline char const* inFunction() const noexcept { return m_function.c_str(); }
	
	private:
		int m_line;
		std::string m_file;
		std::string m_date;
		std::string m_time;
		std::string m_function;
		std::string m_message;
};

#define _RunExcept( message ) RunExcept(message, __FILE__, __LINE__, __DATE__, __TIME__, __func__)

#endif // DEF_RUNEXCEPT