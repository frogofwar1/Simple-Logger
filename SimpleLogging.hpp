#pragma once
#include <fstream>
#include <iostream>
#include <cstdarg>
#include <string>

using namespace std;

class SimpleLogging
{
public:

	void Log(const string& message);
	void Log(const char* format, ...);

	static SimpleLogging* Instance();

private:

	SimpleLogging();
	
	static const string m_filename;
	static SimpleLogging* instance_;
	static ofstream m_logfile;

};

