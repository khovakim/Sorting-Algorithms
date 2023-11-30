void recursiveBubbleSort(int arr[], int size)
{
    if (size == 1) {
        return ;
    }

    bool swapped = false;

    for (int i = 0; i < size - 1; ++i) {
        if (arr[i] > arr[i + 1]) {
            int tmp = arr[i];

            arr[i]     = arr[i + 1];
            arr[i + 1] = tmp;

            swapped = true;
        }
    }

    if (swapped == false) {
        return ;
    }

    recursiveBubbleSort(arr, size - 1);
}
