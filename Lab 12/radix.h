#ifndef RADIX
#define RADIX

#include <iostream>
#include <string>
#include "counting.h"

// Modified counting sort to work with radix
// Values will be 0-9, since we only deal with one digit
void countingSortHelper(int array[], int size, int exponent) {
    // Initialize count array
    int countArray[10] = {};

    // Get array item counts
    for (int i = 0; i < size; i++) {
        countArray[(array[i]/exponent) % 10]++;
    }

    // Get cumulative sums
    for (int i = 1; i < 10; i++) {
        countArray[i] += countArray[i-1];
    }

    // Generate new, sorted array using summed values
    int sortedArray[size];
    int index = 0;
    // Must start from end to retain order
    for (int i = size-1; i >= 0; i--) {
        index = --countArray[(array[i]/exponent) % 10];
        sortedArray[index] = array[i];
    }

    // Assign each value individually to apply to original array
    for (int i = 0; i < size; i++) {
        array[i] = sortedArray[i];
    }
}

void radixSort(int array[], int size) {
    // Find the max of the array
    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max) { max = array[i]; }
    }

    // Cycle through each digit of each number and sort
    for (int exponent = 1; max/exponent > 0; exponent *= 10) {
        // Display sorted array
        countingSortHelper(array, size, exponent);
    }
}


#endif
