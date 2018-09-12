#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "List.cpp"
#include "PriorityNode.cpp"

template <class T> class PriorityQueue {
private:
    List<PriorityNode<T>> queue;

public:
    PriorityQueue();

    void Insert(T, int);
    T Remove();
    void PrintQueue();
};

#endif
