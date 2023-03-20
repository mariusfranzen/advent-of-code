#pragma once

namespace CppUtils
{
	class Sorting
	{
	public:
		/**
		 * \brief Sorts an int array with QuickSort
		 * \param arr the array to sort
		 * \param start starting index for sorting
		 * \param end end index for sorting
		 */
		static void QuickSort(int* arr, int start, int end);
		/**
		 * \brief Inverses an array
		 * \param arr The array to reverse
		 * \param len Length of array
		 */
		static void Reverse(int* arr, int len);
	private:
		static int Partition(int* arr, int start, int end);
	};
}
