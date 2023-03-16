#include "StringUtils.h"

namespace CppUtils
{
	bool StringUtils::IsNumber(const string s)
	{
		std::string::const_iterator it = s.begin();

		while (it != s.end() && std::isdigit(*it))
		{
			++it;
		}

		return !s.empty() && it == s.end();
	}
}
