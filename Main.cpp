#include <iostream>
#include "CWStd.hpp"
#include "CWUtest.hpp"
#include "SimpleLogging.hpp"
#include <string>

#define _CRTDBG_MAP_ALLOC


using namespace std;
using namespace cw;


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	string message1 = "log message 1 ...";
	string message2 = "log message 2 ...";
	int nNum = 10;
	SimpleLogging::Instance()->Log("message to be logged");
	SimpleLogging::Instance()->Log(message1);
	SimpleLogging::Instance()->Log("Message is:%s Number is:%d", message2.c_str(), nNum);
	SimpleLogging::Instance()->Log("Monster HP is %d", 15);

}