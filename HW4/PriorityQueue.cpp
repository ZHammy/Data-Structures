#ifndef PRIORITY_QUEUE_CPP
#define PRIORITY_QUEUE_CPP

#include <iostream>
#include "PriorityQueue.h"

template <class T> PriorityQueue<T>::PriorityQueue() {
    // Nothing really to do here?
}

template <class T> void PriorityQueue<T>::Insert(T val, int priority) {
    PriorityNode<T>* newNode = new PriorityNode<T>(val, priority);
    queue.addItem(newNode);
}

template <class T> T PriorityQueue<T>::Remove() {
    return queue.pop().data;
}

template <class T> void PriorityQueue<T>::PrintQueue() {
    queue.displayAll();
}

#endif
