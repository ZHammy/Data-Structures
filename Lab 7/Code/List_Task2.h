#ifndef LIST_TASK2_H
#define LIST_TASK2_H

#include "List_Task1.cpp"

class List2 : public List1 {
public:
    // Statically overwritten add function
    // Search from end of list instead of beginning
    void addItem(int);
    // int removeItem(int); // TODO: Does this need done? Instructions unclear
};

#endif
