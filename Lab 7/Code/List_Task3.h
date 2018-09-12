#ifndef LIST_TASK3_H
#define LIST_TASK3_H

#include "List_Task1.cpp"

class List3 : public List1 {
public:
    List3();
    // Statically overwritten add function
    // adds item between 2 items, dont move
    void addItem(int);
    //Will no longer move items
    int removeItem(int);
    void displayAll();
};

#endif
