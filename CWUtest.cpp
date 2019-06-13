#include "CWUtest.hpp"

namespace cw
{
	CWUtest::CWUtest() : m_passCases(0), m_allCases(0)
	{

	}


	CWUtest::~CWUtest()
	{
	}

	void CWUtest::init(const std::string& t_testName) {
		m_testName = t_testName;
		std::cout << m_testName << std::endl;
	}

	void CWUtest::test(const std::string& t_details, const bool t_condition) {
		if (t_condition)
		{
			//counting pass cases
			m_passCases++;
		}
		/*else
		{
			m_failCases++;
		}*/

		// counting test cases
		// print the message and the condition
		m_allCases++;
		std::cout << t_details << (t_condition ? "Pass" : "Fail") << std::endl;
	}

	void CWUtest::report() const{
		std::cout << "all pass case :" << m_passCases << std::endl;
		std::cout << "all fail case :" << m_allCases - m_passCases << std::endl;
		std::cout << "all case :" << m_allCases << std::endl;
		//std::cout << __FILE__ << " " << __FUNCTION__  << " " << __LINE__ << std::endl;
	}
}

