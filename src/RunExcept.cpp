#include "../include/RunExcept.hpp"

RunExcept::RunExcept(char const* message, char const* file, int line, char const* date, char const* time, char const* function) noexcept : std::exception(), m_line(line)
{
	std::ostringstream ossFile;
	std::ostringstream ossDate;
	std::ostringstream ossTime;
	std::ostringstream ossFunction;
	std::ostringstream ossMessage;
	
	ossFile << file;
	ossDate << date;
	ossTime << time;
	ossFunction << function;
	ossMessage << message;
	
	m_file = ossFile.str();
	m_date = ossDate.str();
	m_time = ossTime.str();
	m_function = ossFunction.str();
	m_message = ossMessage.str();
}

RunExcept::RunExcept(RunExcept const& src) noexcept : RunExcept(src.m_message.c_str(), src.m_file.c_str(), src.m_line, src.m_date.c_str(), src.m_time.c_str(), src.m_function.c_str()) {}

RunExcept::~RunExcept() noexcept {}