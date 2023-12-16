static void merge(int arr[], const int begin, const int mid, const int end)
{
	const int subArrOne = mid - begin + 1;
	const int subArrTwo = end - mid;

	int* leftArr  = new int[subArrOne];
	int* rightArr = new int[subArrTwo];

	for (int i = 0; i < subArrOne; ++i) {
		leftArr[i] = arr[begin + i];
	}

	for (int i = 0; i < subArrTwo; ++i) {
		rightArr[i] = arr[mid + i + 1];
	}

	int idxOfSubArrOne = 0;
	int idxOfSubArrTwo = 0;
	int idxOfMergeArr  = begin;

	while (idxOfSubArrOne < subArrOne && idxOfSubArrTwo < subArrTwo) {
		if (rightArr[idxOfSubArrTwo] > leftArr[idxOfSubArrOne]) {
			arr[idxOfMergeArr] = leftArr[idxOfSubArrOne];
			++idxOfSubArrOne;
		} else {
			arr[idxOfMergeArr] = rightArr[idxOfSubArrTwo];
			++idxOfSubArrTwo;
		}
		++idxOfMergeArr;
	}

	while (idxOfSubArrOne < subArrOne) {
		arr[idxOfMergeArr] = leftArr[idxOfSubArrOne];
		++idxOfMergeArr;
		++idxOfSubArrOne;
	}

	while (idxOfSubArrTwo < subArrTwo) {
		arr[idxOfMergeArr] = rightArr[idxOfSubArrTwo];
		++idxOfMergeArr;
		++idxOfSubArrTwo;
	}

	delete[] leftArr;
	delete[] rightArr;
}

void mergeSort(int arr[], const int begin, const int end)
{
	if (begin >= end) {
		return ;
	}

	int mid = begin + (end - begin) / 2;
	mergeSort(arr, begin, mid);
	mergeSort(arr, mid + 1, end);
	merge(arr, begin, mid, end);
}