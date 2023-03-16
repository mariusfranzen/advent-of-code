#include "Sorting.h"
#include <utility>

namespace CppUtils
{
	void Sorting::QuickSort(int* arr, int start, int end)
	{
		if (start < end)
		{
			int partitionIndex = Partition(arr, start, end);
			QuickSort(arr, start, partitionIndex - 1);
			QuickSort(arr, partitionIndex + 1, end);
		}
		return;
	}

    void Sorting::Reverse(int* arr, int len)
    {
        for (int ix = 0; ix < len / 2; ix++)
        {
            int t = arr[ix];
            arr[ix] = arr[len - ix - 1];
            arr[len - ix - 1] = t;
        }
    }

	int Sorting::Partition(int* arr, int start, int end)
	{
        int pivot = arr[start];

        int count = 0;
        for (int i = start + 1; i <= end; i++)
        {
            if (arr[i] <= pivot)
                count++;
        }

        // Giving pivot element its correct position
        int pivotIndex = start + count;
        std::swap(arr[pivotIndex], arr[start]);

        // Sorting left and right parts of the pivot element
        int i = start, j = end;

        while (i < pivotIndex && j > pivotIndex)
        {

            while (arr[i] <= pivot)
            {
                i++;
            }

            while (arr[j] > pivot)
            {
                j--;
            }

            if (i < pivotIndex && j > pivotIndex)
            {
                std::swap(arr[i++], arr[j--]);
            }
        }

        return pivotIndex;
	}
}
