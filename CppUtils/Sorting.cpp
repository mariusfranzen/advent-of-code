#include "Sorting.h"
#include <utility>

namespace CppUtils
{
	void Sorting::QuickSort(int* arr, const int start, const int end)
	{
		if (start < end)
		{
			const int partition_index = Partition(arr, start, end);
			QuickSort(arr, start, partition_index - 1);
			QuickSort(arr, partition_index + 1, end);
		}
	}

	void Sorting::Reverse(int* arr, const int len)
	{
		for (int ix = 0; ix < len / 2; ix++)
		{
			const int t = arr[ix];
			arr[ix] = arr[len - ix - 1];
			arr[len - ix - 1] = t;
		}
	}

	int Sorting::Partition(int* arr, const int start, const int end)
	{
		const int pivot = arr[start];

		int count = 0;
		for (int i = start + 1; i <= end; i++)
		{
			if (arr[i] <= pivot)
				count++;
		}

		// Giving pivot element its correct position
		const int pivot_index = start + count;
		std::swap(arr[pivot_index], arr[start]);

		// Sorting left and right parts of the pivot element
		int i = start, j = end;

		while (i < pivot_index && j > pivot_index)
		{
			while (arr[i] <= pivot)
			{
				i++;
			}

			while (arr[j] > pivot)
			{
				j--;
			}

			if (i < pivot_index && j > pivot_index)
			{
				std::swap(arr[i++], arr[j--]);
			}
		}

		return pivot_index;
	}
}
