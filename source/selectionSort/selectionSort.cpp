void selectionSort(int arr[], int size)
{
	int indexOfMinElem;

	for (int i = 0; i < size; ++i) {
		indexOfMinElem = i;
		for (int j = i + 1; j < size; ++j) {
			if (arr[j] < arr[indexOfMinElem]) {
				indexOfMinElem = j;
			}
		}

		if (i != indexOfMinElem) {
			int tmp             = arr[i];
			arr[i]              = arr[indexOfMinElem];
			arr[indexOfMinElem] = tmp;
		}
	}
}
