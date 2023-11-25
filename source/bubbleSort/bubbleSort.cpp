void bubbleSort(int arr[], int size)
{
	bool swapped;

    for (int i = 0; i < size; ++i) {
        swapped = false;

        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];

                arr[j]     = arr[j + 1];
                arr[j + 1] = tmp;

                swapped = true;
            }
        }

        if (swapped == false) {
            return ;
        }
    }
}
