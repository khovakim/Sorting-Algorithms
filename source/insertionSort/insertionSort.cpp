void insertionSort(int arr[], int size)
{
	for (int i = 1; i < size; ++i) {
		int j = i - 1;
		int elem = arr[i];

		while (j >= 0 && arr[j] > elem) {
			arr[j + 1] = arr[j];
			--j;
		}

		arr[j + 1] = elem;
	}
}
