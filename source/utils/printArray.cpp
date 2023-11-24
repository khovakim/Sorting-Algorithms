#include <iostream>

void printArray(int arr[], int size)
{
    std::cout << "[";

    for (int i = 0; i < size; ++i) {
        std::cout << arr[i];
        
        if (i == size - 1) {
            break ;
        }

        std::cout << ", ";
    }

    std::cout << "]" << std::endl;
}
