#include "StringUtils.h"

namespace CppUtils
{
	bool StringUtils::IsNumber(const std::string& s)
	{
		auto it = s.begin();

		while (it != s.end() && std::isdigit(*it))
		{
			++it;
		}

		return !s.empty() && it == s.end();
	}

	std::vector<std::string> StringUtils::SplitString(const std::string& s, const std::string& delimiter)
	{
		size_t start = 0;
		size_t end;

		std::vector<std::string> result;

		while ((end = s.find(delimiter, start)) != std::string::npos)
		{
			std::string token = s.substr(start, end - start);
			start = end + delimiter.length();
			result.push_back(token);
		}

		result.push_back(s.substr(start));
		return result;
	}
}
