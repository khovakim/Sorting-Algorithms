void recursiveInsertionSort(int* arr, int size)
{
	if (size <= 1) {
		return ;
	}

	recursiveInsertionSort(arr, size - 1);

	int j    = size - 2;
	int elem = arr[size - 1];

	while (j >= 0 && arr[j] > elem) {
		arr[j + 1] = arr[j];
		--j;
	}
	arr[j + 1] = elem;
}