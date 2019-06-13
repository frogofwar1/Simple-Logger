#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>

namespace cw 
{
	class CWUtest
	{
	public:
		CWUtest();
		~CWUtest();

		void init(const std::string& t_testName);
		void test(const std::string& t_details, const bool t_condition);
		void report() const;

	private:
		std::string m_testName;
		//std::vector<const std::string&> m_detailsList;
		//std::vector<const bool> m_conditionList;
		unsigned int m_passCases;
		//unsigned int m_failCases;
		unsigned int m_allCases;
	};
}


