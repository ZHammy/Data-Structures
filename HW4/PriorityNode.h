#ifndef PRIORITY_NODE_H
#define PRIORITY_NODE_H

template <class T> class PriorityNode {
public:
    T data;
    int priority;

    PriorityNode();
    PriorityNode(T, int);

    void displayData();

    bool operator < (PriorityNode<T>&);
    bool operator <=(PriorityNode<T>&);
    bool operator > (PriorityNode<T>&);
    bool operator >=(PriorityNode<T>&);
    bool operator ==(PriorityNode<T>&);
};

#endif
