#include <ctime>
#include <chrono>
#include <iomanip>
#include <iostream>

#include "utils.h"
#include "sortingAlgorithms.h"

// const int SIZE = 10;
// const int SIZE = 100;
const int SIZE = 1000;
// const int SIZE = 10000;
// const int SIZE = 100000;

typedef void (*Sort)(int[], int);

//	static void test(const char* message, void (*mySort)(int[], int))
static void test(const char* message, Sort mySort)
{
	int             arr[SIZE]{};
	struct timespec start;
	struct timespec end;

	inputArray(arr, SIZE);
	std::cout << "Unsorted array :" << std::endl << std::endl;
	printArray(arr, SIZE);
	std::cout << std::endl;

	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
	mySort(arr, SIZE);
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);

	long   nanoseconds = end.tv_nsec - start.tv_nsec;
	long   seconds     = end.tv_sec - start.tv_sec;
	double elapsed     = seconds + (nanoseconds * 1e-9);


	std::cout << "Sorted array :" << std::endl << std::endl;
	printArray(arr, SIZE);
	std::cout << "Time taken by program is : "
			<< std::fixed << std::setprecision(10) << elapsed
			<< " sec: " << message << std::endl << std::endl << std::endl;
}


static void test(const char* message, void (*mySort)(int[], int, int), int n)
{
	int             arr[SIZE]{};
	struct timespec start;
	struct timespec end;

	inputArray(arr, SIZE);
	std::cout << "Unsorted array :" << std::endl << std::endl;
	printArray(arr, SIZE);
	std::cout << std::endl;

	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
	mySort(arr, SIZE, n);
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);

	long   nanoseconds = end.tv_nsec - start.tv_nsec;
	long   seconds     = end.tv_sec - start.tv_sec;
	double elapsed     = seconds + (nanoseconds * 1e-9);


	std::cout << "Sorted array :" << std::endl << std::endl;
	printArray(arr, SIZE);
	std::cout << "Time taken by program is : "
			<< std::fixed << std::setprecision(10) << elapsed
			<< " sec: " << message << std::endl << std::endl << std::endl;
}

static void test(const char* message, void (*mySort)(int[], int, int))
{
	int             arr[SIZE]{};
	int             begin{0};
	int             end = (sizeof(arr) / sizeof(int)) - 1;
	struct timespec start;
	struct timespec end_t;

	inputArray(arr, SIZE);
	std::cout << "Unsorted array :" << std::endl << std::endl;
	printArray(arr, SIZE);
	std::cout << std::endl;

	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
	mySort(arr, begin, end);
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end_t);

	long   nanoseconds = end_t.tv_nsec - start.tv_nsec;
	long   seconds     = end_t.tv_sec - start.tv_sec;
	double elapsed     = seconds + (nanoseconds * 1e-9);


	std::cout << "Sorted array :" << std::endl << std::endl;
	printArray(arr, SIZE);
	std::cout << "Time taken by program is : "
			<< std::fixed << std::setprecision(10) << elapsed
			<< " sec: " << message << std::endl << std::endl << std::endl;
}

int main()
{
	test("Sorting by -> Bubble Sort", bubbleSort);
	test("Sorting by -> Recursive Bubble Sort", recursiveBubbleSort);
	test("Sorting by -> Insertion Sort", insertionSort);
	test("Sorting by -> Recursive Insertion Sort", recursiveInsertionSort);
	test("Sorting by -> Selection Sort", selectionSort);
	test("Sorting by -> Recursive Selection Sort", recursiveSelectionSort, 0);
	test("Sorting by -> Radix Sort", radixSort);
	test("Sorting by -> Merge Sort", mergeSort);

	return 0;
}
