#ifndef BUBBLE
#define BUBBLE

#include <iostream>
using namespace std;

void bubbleSort(int array[], int size) {
    // Keep track of if sorted or not
    bool sorted;
    int temp;

    do {
        sorted = true; // Array is sorted until otherwise stated
        for (int i = 1; i < size; i++) {
            if (array[i] < array[i-1]) {
                sorted = false;

                // Swap array values
                temp = array[i-1];
                array[i-1] = array[i];
                array[i] = temp;
            }
        }
    } while (!sorted);
}

#endif
