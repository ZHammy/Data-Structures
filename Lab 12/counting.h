#ifndef COUNT
#define COUNT

#include <iostream>

using namespace std;

void countingSort(int array[], int size) {
    // Find the min and max of the given array
    int min = array[0]; int max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] < min) { min = array[i]; }
        if (array[i] > max) { max = array[i]; }
    }

    // Initialize count array
    // Values should initialize to zero
    int countSize = max-min + 1;
    int countArray[countSize] = {};

    // Get array item counts
    // NOTE: countArray offset from original = min
    for (int i = 0; i < size; i++) {
        countArray[array[i] - min]++;
    }

    // Get cumulative sums
    for (int i = 1; i < countSize; i++) {
        countArray[i] += countArray[i-1];
    }

    // Generate new, sorted array using summed values
    int sortedArray[size];
    int index = 0;
    // Must start from the end to retain order
    for (int i = size-1; i >= 0; i--) {
        index = --countArray[array[i]-min];
        sortedArray[index] = array[i];
    }

    // Assign values to new array
    for(int i = 0; i < size; i++) {
        array[i] = sortedArray[i];
    }
}

#endif
