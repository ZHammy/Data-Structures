#ifndef HEAP_H
#define HEAP_H

#include "PriorityNode.cpp"

template <class T> class PriorityHeap {
private:
    PriorityNode<T>* arr; // Heap array
    int cap;  // Maximum capacity
    int size; // Current heap size

public:
    PriorityHeap (int);

    // Utility getters for indexes
    int parent (int i)    { return (i-1)/2; }
    int leftChild(int i)  { return 2*i + 1; }
    int rightChild(int i) { return 2*i + 2; }

    void Insert(T, int);

    PriorityNode<T> Remove();

    void PrintHeap();
};

#endif
