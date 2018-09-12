#ifndef LIST_TASK1_CPP
#define LIST_TASK1_CPP

#include <iostream>
#include "List_Task1.h"

using namespace std;

// Constructor(s)
List1::List1() {
    length = 0;
    maxLength = MAX_LENGTH;
    opCount = 0;
}

// Getters / setters
int List1::getLength() { return length; }
int List1::getOpCount() { return opCount; }
bool List1::isEmpty() { return length == 0; }
bool List1::isFull() { return length == maxLength; }

// Add to list functions
void List1::addItem(int val) {
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
        int index = length; // Index of the new value

        // Find the index of where it should be inserted
        // Start at beginning of list
        for (int i = 0; i < length; i++) {
            opCount++;
            if (val <= *data[i]) {
                index = i;
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

// Remove from list functions
int List1::removeItem(int val) {
    // If there is nothing in the list, throw an error
    if (length == 0) { throw *new ListUnderflow; }

    // Reset operation count
    opCount = 0;
    // Create a pointer using the given value
    int *newVal = new int;
    *newVal = val;

    if (length == 0) {
        opCount++;
        data[0] = newVal;

    } else {
        bool found = false; // If the value was found
        int index = length; // Index of the new value

        // Find the index of where it should be removed
        for (int i = 0; i < length; i++) {
            opCount++;

            // Ensure that there are no empty spots in the array
            if (i < length && (data[i] == nullptr || data[i+1] == nullptr)) {
                throw *new ListNull;
            }
            // Ensure that the list is still sorted
            else if (i < length-1 && *data[i] > *data[i+1]) {
                throw *new ListUnsorted;
            }

            if (val == *data[i] && !found) {
                found = true;
                index = i;
                delete data[i];
                break;
            }
        }

        if (!found) { throw *new ListItemNotFound; }

        // Shift the data down to keep sort
        for (int j = index + 1; j < length; j++) {
            opCount++;
            data[j-1] = data[j];
        }

        // Set the data value we want to add
        opCount++;
        data[index] = newVal;
    }

    length--;
}

void List1::makeEmpty() {
    // Delete previously allocated memory
    for (int i = 0; i < length; i++) {
        delete data[i];
    }
    
    length = 0; // Reset length
}

void List1::displayAll() {
    for (int i = 0; i < length; i++) {
        cout << *data[i] << endl;
    }
    cout << endl; // For readability
}
#endif
