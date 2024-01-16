#include <iostream>

static int partition(int arr[], const int start, const int end)
{
	int pivot = arr[end];

	int pivotIndex = start - 1;

	for (int i = start; i <= end; ++i) {
		if (arr[i] < pivot) {
			++pivotIndex;
			std::swap(arr[pivotIndex], arr[i]);
		}
	}
	++pivotIndex;
	std::swap(arr[pivotIndex], arr[end]);

	return pivotIndex;
}

void quickSort(int arr[], const int start, const int end)
{
	if (start >= end) {
		return ;
	}

	int p = partition(arr, start, end);

	quickSort(arr, start, p - 1);
	quickSort(arr, p + 1, end);
}