#pragma once

#ifdef _DEBUG
	#define LOG_INFO(x) Log::info(x)
	#define LOG_WARNING(x) Log::warning(x)
	#define LOG_ERROR(x) Log::error(x)
#else
	#define LOG_INFO(x)
	#define LOG_WARNING(x)
	#define LOG_ERROR(x)
#endif

#include <iostream>
#include <Windows.h>

class Log
{
public: //Constructors
	Log() = delete;

public: //Public methods
	static void info(const char* msg);
	static void warning(const char* msg);
	static void error(const char* msg);

private: //Private enums
	enum class LogLevel { LogLevelInfo, LogLevelWarning, LogLevelError };
	enum LogColor { LogColorInfo = 15, LogColorWarning = 14, LogColorError = 12 };

private: //Private attributes
	static HANDLE s_Console;

private: //Private methods
	static void log(const char* msg, LogLevel level);
};

