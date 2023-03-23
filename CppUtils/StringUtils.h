#pragma once
#include <string>
#include <vector>

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
		/**
		 * \brief Splits the given string into a vector of strings, split on the delimiters
		 * \param s The string to split
		 * \param delimiter The delimiter that splits the string
		 * \return Vector with each new string
		 */
		static std::vector<std::string> SplitString(const std::string& s, const std::string& delimiter);
	};
}
