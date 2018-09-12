#ifndef HEAP_CPP
#define HEAP_CPP

#include <iostream>
#include <string>
#include "PriorityHeap.h"

using namespace std;

template <class T> PriorityHeap<T>::PriorityHeap (int size_in) {
    cap = size_in;
    size = 0;
    arr = new PriorityNode<T>[cap];
}

template <class T> void PriorityHeap<T>::Insert(T val, int priority) {
    if (size >= cap) { cout << "Heap full." << endl; return; }

    // Put the new value on the end of the heap
    int end = size;
    PriorityNode<T> newVal(val, priority);
    arr[end] = newVal;

    // Reheap up until it's in the proper place
    // This maintains order since items below will naturally be larger
    while (arr[parent(end)] < arr[end]) {
        PriorityNode<T> temp = arr[parent(end)];
        arr[parent(end)] = arr[end];
        arr[end] = temp;

        end = parent(end);
    }

    size++;
}

template <class T> PriorityNode<T> PriorityHeap<T>::Remove() {
    if (size <= 0) { cout << "No items in heap!" << endl; return PriorityNode<T>(-9999, -9999); }

    // Store smallest val
    PriorityNode<T> retVal = arr[0];

    // Put last val into the first val position
    arr[0] = arr[size-1];
    size--;

    // Reheap down
    int index = 0;
    while (true) {
        int left = leftChild(index);
        int right = rightChild(index);

        // Find the index of the smallest child
        // Ensure we're not looking past the current size
        int maxChild;
        if (left > size-1) {
            // Exit loop if we've reached the last position
            break;
        } else if (right > size-1) {
            maxChild = left;
        } else {
            maxChild = arr[left] >= arr[right] ? left : right;
        }

        // Swap if necessary, else it's in the right spot
        if (arr[index] < arr[maxChild]) {
            PriorityNode<T> temp = arr[index];
            arr[index] = arr[maxChild];
            arr[maxChild] = temp;

            index = maxChild;
        } else {
            break;
        }
    }

    return retVal;
}

template <class T> void PriorityHeap<T>::PrintHeap() {
    // Create full copy of our heap
    PriorityHeap<T> newHeap(cap);
    for(int i =0; i < size; i++) {
        newHeap.Insert(arr[i].data, arr[i].priority);
    }

    // Display contents of copy using remove function
    for (int i = 0; i < size; i++) {
        newHeap.Remove().displayData();
        cout << endl;
    }
}

#endif
