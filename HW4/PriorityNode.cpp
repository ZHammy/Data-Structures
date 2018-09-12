#ifndef PRIORITY_NODE_CPP
#define PRIORITY_NODE_CPP

#include <iostream>
#include "PriorityNode.h"

using namespace std;

template <class T> PriorityNode<T>::PriorityNode() {
    priority = -9999;
}

template <class T> PriorityNode<T>::PriorityNode(T data_in, int priority_in) {
    data = data_in;
    priority = priority_in;
}

template <class T> void PriorityNode<T>::displayData() {
    cout << "Data:     " << data << endl;
    cout << "Priority: " << priority << endl;
}

template <class T> bool PriorityNode<T>::operator < (PriorityNode<T> &other) {
    return priority < other.priority;
}

template <class T> bool PriorityNode<T>::operator <= (PriorityNode<T> &other) {
    return priority <= other.priority;
}

template <class T> bool PriorityNode<T>::operator > (PriorityNode<T> &other) {
    return priority > other.priority;
}

template <class T> bool PriorityNode<T>::operator >= (PriorityNode<T> &other) {
    return priority >= other.priority;
}

template <class T> bool PriorityNode<T>::operator == (PriorityNode<T> &other) {
    return priority == other.priority;
}

#endif
