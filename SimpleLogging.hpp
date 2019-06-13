#pragma once
#include <fstream>
#include <iostream>
#include <cstdarg>
#include <string>

using namespace std;



class SimpleLogging
{
public:

	enum LogLevel {
		ERROR, WARNING, INFO
	};

	void Log(LogLevel t_logLevel, const string& t_message);
	void Log(LogLevel t_logLevel, const char* t_format, ...);

	static SimpleLogging* Instance();

	

private:

	SimpleLogging();
	
	static const string m_filename;
	static SimpleLogging* instance_;
	static ofstream m_logfile;

};

