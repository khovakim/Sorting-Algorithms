#include <iomanip>
#include <iostream>

#include "utils.h"
#include "sortingAlgorithms.h"

//const int SIZE = 10;
const int SIZE = 100;
//const int SIZE = 1000;
//const int SIZE = 10000;
//const int SIZE = 100000;

typedef void (*Sort)(int[], int);

//	static void test(const char* message, void (*mySort)(int[], int))

static void test(const char* message, Sort mySort)
{
	double timeTaken;
	int arr[SIZE]{};

	inputArray(arr, SIZE);
	printArray(arr, SIZE);

	time_t start;
	time_t end;

	time(&start);
	mySort(arr, SIZE);
	time(&end);

	timeTaken = double(end - start);

	printArray(arr, SIZE);
	std::cout << "Time taken by program is : "
			<< std::fixed << std::setprecision(10) << timeTaken
			<< " sec: " << message << std::endl << std::endl << std::endl;
}





int main()
{
	test("Sorting by -> Bubble Sort", bubbleSort);
	test("Sorting by -> Recursion Bubble Sort", recursionBubbleSort);
	test("Sorting by -> Insertion Sort", insertionSort);

	return 0;
}
