
int maxElementInArray(int arr[], int size)
{
	int max = arr[0];

	for (int i = 1; i < size; ++i) {
		if (max < arr[i]) {
			max = arr[i];
		}
	}

	return max;
}

const int COUNT_OF_DIGIT = 10;

void countSort(int arr[], int size, int exp)
{
	int* countArr = new int[size]{0};

	for (int i = 0; i < size; ++i) {
		++countArr[(arr[i] / exp) % 10];
	}

	for (int i = 1; i < COUNT_OF_DIGIT; ++i) {
		countArr[i] += countArr[i - 1];
	}

	int* ret = new int[size]{0};

	for (int i = size - 1; i >= 0; --i) {
		ret[countArr[(arr[i] / exp) % 10] - 1] = arr[i];
		--countArr[(arr[i] / exp) % 10];
	}

	for (int i = 0; i < size; ++i) {
		arr[i] = ret[i];
	}

	delete[] ret;
	delete[] countArr;
}


void radixSort(int arr[], int size)
{
	if (size == 0 || size == 1) {
		return ;
	}

	int maxElem = maxElementInArray(arr, size);

	for (int exp = 1; exp < maxElem; exp *= 10) {
		countSort(arr, size, exp);
	}
}
