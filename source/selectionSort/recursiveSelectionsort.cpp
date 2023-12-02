int minIndex(int arr[], int i, int j)
{
	int k = i;

	for (; i < j; ++i) {
		if (arr[k] > arr[i]) {
			k = i;
		}
	}

	return k;
}

void recursiveSelectionSort(int arr[], int size, int index = 0)
{
	if (index == size) {
		return ;
	}

	int k = minIndex(arr, index, size);

	if (k != index) {
		int tmp    = arr[k];
		arr[k]     = arr[index];
		arr[index] = tmp;
	}

	recursiveSelectionSort(arr, size, index + 1);
}
