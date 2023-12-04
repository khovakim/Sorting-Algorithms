#ifndef  __SORTINGALGORITHMS_H__
# define __SORTINGALGORITHMS_H__

void bubbleSort(int arr[], int size);
void recursiveBubbleSort(int arr[], int size);

void insertionSort(int arr[], int size);
void recursiveInsertionSort(int arr[], int size);

void selectionSort(int arr[], int size);
void recursiveSelectionSort(int arr[], int size, int index = 0);

void radixSort(int arr[], int size);
#endif   // __SORTINGALGORITHMS_H__
