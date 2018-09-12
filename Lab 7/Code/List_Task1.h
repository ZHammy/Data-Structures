#ifndef LIST_TASK1_H
#define LIST_TASK1_H

const int MAX_LENGTH = 50;

// Sorted list
// Searches from front
class List1 {
protected:
    int *data[MAX_LENGTH];
    int length;
    int maxLength;
    int opCount; // Temp store; number of operations for the last run func

public:
    // Constructor(s)
    List1();

    // Error classes
    class ListUnderflow {};
    class ListOverflow {};
    class ListItemNotFound {};
    class ListNull {};
    class ListUnsorted {};

    // Getters / setters
    int getLength();  // Return user length
    int getOpCount(); // Return operation count
    bool isEmpty();   // Check if the list is empty
    bool isFull();    // Check if the list is full

    // Add to list functions
    void addItem(int); // Insert a value into the list sorted

    // Remove from list functions
    int removeItem(int); // Search for given item, remove it, and return it
    void makeEmpty();    // Empty the list

    void displayAll();
};

#endif
