#include "utils.h"

const int MAX_NUMBER_IN_ARR = 1501;

void inputArray(int arr[], int size)
{
	srand(time(0));

	for (int i = 0; i < size; ++i) {
		arr[i] = rand() % MAX_NUMBER_IN_ARR;
	}
}
