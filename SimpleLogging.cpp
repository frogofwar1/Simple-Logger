#include "SimpleLogging.hpp"
#include "Utilities.hpp"

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


void SimpleLogging::Log(const string& t_message)
{
	cout << Util::CurrentDateTime() << ":" << t_message << endl;
	m_logfile << Util::CurrentDateTime() << ":" << t_message << endl;
}

void SimpleLogging::Log(const char* format, ...)
{
	char* message = NULL;
	int nLength = 0;
	va_list args;
	va_start(args, format);
	nLength = _vscprintf(format, args) + 1;
	message = new char[nLength];
	vsprintf_s(message, nLength, format, args);
	//vsprintf(message, format, args);
	cout << Util::CurrentDateTime() << ":" << message << endl;
	m_logfile << Util::CurrentDateTime() << ":" << message << endl;
	va_end(args);

	delete[] message;
}



