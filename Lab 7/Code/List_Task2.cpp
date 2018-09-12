#ifndef LIST_TASK2_CPP
#define LIST_TASK2_CPP

#include "List_Task2.h"

using namespace std;

void List2::addItem(int val) {
    // Throw error if the list is already full
    if (maxLength == length) { throw *new ListOverflow; }

    // Reset operation count
    opCount = 0;
    // Create a pointer using the given value
    int *newVal = new int;
    *newVal = val;

    if (length == 0) {
        opCount++;
        data[0] = newVal;

    } else {
        int index = 0; // Index of the new value

        // Find the index of where it should be inserted
        // Start at end of list
        for (int i = length-2; i >= 0; i--) {
            opCount++;
            if (val >= *data[i]) {
                index = i+1;
                break;
            }
        }

        // Shift the data up to keep sort
        for (int j = length; j > index; j--) {
            opCount++;
            data[j] = data[j-1];
        }

        // Set the data value we want to add
        opCount++;
        data[index] = newVal;
    }

    length++;
}

#endif
