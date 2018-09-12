#ifndef INSERTION_H
#define INSERTION_H

void insertionSort(int array[], int size) {
    int temp; // Temp var for swapping

    for (int i = 0; i < size; i++) {
        for (int j = i+1; j >= 1; j--) {
            // Swap items if out of order
            if (array[j-1] > array[j]) {
                temp = array[j-1];
                array[j-1] = array[j];
                array[j] = temp;

            // If these items are in order, so is rest of list.
            // So, we break from just the inner loop
            } else {
                break;
            }
        }
    }
}

#endif
