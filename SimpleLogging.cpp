#include "SimpleLogging.hpp"
#include "Utilities.hpp"
#include "CWStd.hpp"


const string SimpleLogging::m_filename = "Log.txt";
SimpleLogging* SimpleLogging::instance_ = nullptr;
ofstream SimpleLogging::m_logfile;

SimpleLogging::SimpleLogging()
{

}

SimpleLogging* SimpleLogging::Instance() {
	if (instance_ == NULL) {
		instance_ = new SimpleLogging();
		m_logfile.open(m_filename.c_str(), ios::out | ios::app);
	}
	return instance_;
}


void SimpleLogging::Log(LogLevel t_logLevel, const string& t_message)
{
	string logLevel;

	switch (t_logLevel)
	{
	case SimpleLogging::ERROR: logLevel = "ERROR"; break;
	case SimpleLogging::WARNING: logLevel = "WARNING"; break;
	case SimpleLogging::INFO: logLevel = "INFO"; break;
	default:
		break;
	}
	
	cout << "[" << logLevel << "] " << Util::CurrentDateTime() << " : " << t_message << endl;
	m_logfile << "[" << logLevel << "] " << Util::CurrentDateTime() << " : " << t_message << endl;
	
}

void SimpleLogging::Log(LogLevel t_logLevel, const char* t_format, ...)
{
	string logLevel;
	char* message = NULL;
	int nLength = 0;
	va_list args;
	va_start(args, t_format);
	nLength = _vscprintf(t_format, args) + 1;
	message = new char[nLength];
	vsprintf_s(message, nLength, t_format, args); 

	switch (t_logLevel)
	{
	case SimpleLogging::ERROR: logLevel = "ERROR"; break;
	case SimpleLogging::WARNING: logLevel = "WARNING"; break;
	case SimpleLogging::INFO: logLevel = "INFO"; break;
	default:
		break;
	}

	cout << "[" << logLevel << "] " << Util::CurrentDateTime() << " : " << message << endl;
	m_logfile << "[" << logLevel << "] " << Util::CurrentDateTime() << " : " << message << endl;
	va_end(args);

	delete[] message;
}



