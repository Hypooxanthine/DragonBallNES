#include "Log.h"

HANDLE Log::s_Console = GetStdHandle(STD_OUTPUT_HANDLE);

void Log::info(const char* msg) { log(msg, LogLevel::LogLevelInfo); }

void Log::warning(const char* msg) { log(msg, LogLevel::LogLevelWarning); }

void Log::error(const char* msg) { log(msg, LogLevel::LogLevelError); }

void Log::log(const char* msg, LogLevel level)
{
	switch (level)
	{
	case LogLevel::LogLevelInfo:
		SetConsoleTextAttribute(s_Console, LogColorInfo);
		std::cout << "[Info] ";
		break;
	case LogLevel::LogLevelWarning:
		SetConsoleTextAttribute(s_Console, LogColorWarning);
		std::cout << "[Warning] ";
		break;
	case LogLevel::LogLevelError:
		SetConsoleTextAttribute(s_Console, LogColorWarning);
		std::cout << "[Error] ";
		break;
	}

	std::cout << msg << std::endl;
	SetConsoleTextAttribute(s_Console, LogColorInfo);
}
