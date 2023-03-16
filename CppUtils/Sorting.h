#pragma once

namespace CppUtils
{
	class Sorting
	{
	public:
		static void QuickSort(int* arr, int start, int end);
		static void Reverse(int* arr, int len);
	private:
		static int Partition(int* arr, int start, int end);
	};
}
