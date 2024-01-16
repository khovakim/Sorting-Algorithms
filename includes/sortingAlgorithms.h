#ifndef  __SORTINGALGORITHMS_H__
# define __SORTINGALGORITHMS_H__

void bubbleSort(int arr[], const int size);
void recursiveBubbleSort(int arr[], const int size);

void insertionSort(int arr[], const int size);
void recursiveInsertionSort(int arr[], const int size);

void selectionSort(int arr[], const int size);
void recursiveSelectionSort(int arr[], const int size, int index = 0);

void radixSort(int arr[], const int size);

void mergeSort(int arr[], const int begin, const int end);
void quickSort(int arr[], const int begin, const int end);

#endif   // __SORTINGALGORITHMS_H__
