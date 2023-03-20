#pragma once
#include <string>

namespace CppUtils
{
	class StringUtils
	{
	public:
		/**
		 * \brief Checks if a string consists of only numbers
		 * \param s String to check
		 * \return true if string is number
		 */
		static bool IsNumber(const std::string& s);
	};
}
