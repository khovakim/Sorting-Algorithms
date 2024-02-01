#include <iostream>

void countingSort(int arr[], const int size)
{
	int M{};

	for (int i = 0; i < size; ++i) {
		//M = M > arr[i] ? M : arr[i];
		M = std::max(M, arr[i]);
	}

	int* countArr = new int [M + 1]{0};

	for (int i = 0; i < size; ++i) {
		++countArr[arr[i]];
	}

	for (int i = 1; i <= M; ++i) {
		countArr[i] += countArr[i - 1];
	}

	int* newArr = new int [size];

	for (int i = size - 1; i >= 0; --i) {
		newArr[countArr[arr[i]] - 1] = arr[i];
		--countArr[arr[i]];
	}

	for (int i = 0; i < size; ++i) {
		arr[i] = newArr[i];
	}

	delete [] newArr;
	delete [] countArr;
}
