#ifndef LIST_H
#define LIST_H

// ----- Node -----
template <class T> class Node {
public:
    T data;
    Node<T>* next;

    // Constructors
    Node();
    Node(T);
    Node(T, Node<T>*);
};

// ----- Linked List -----
template <class T> class List {
private:
    Node<T>* first;
    // Index of where we look with see functions
    // Pointer to allow for easier passing to functions
    int* look;
    int length;

    // Most recent number of operations
    // Only checks getItem
    int opCount;

public:
    // Constructor(s)
    List();

    // Destructor
    ~List();

    // Error class(es)
    class ListUnderflow {};
    class ListItemNotFound {};
    class ListEnd {}; // If we're at the end of a list

    // Basic functions
    bool isInList(T*); // Check if an item is in the list
    bool isEmpty(); // Check if an item is empty
    int size(); // Returns current list size
    int getOpCount(); // Returns last op count

    // Add / remove functions
    void addItem(T*); // Add an item to the list
    T* getItem(T*); // gets but does not Remove an item from the list
    T* removeItem(T*); // Remove an item from the list
    void makeEmpty();

    // See functions
    Node<T>* seeNext(); // Return item at next list location
    Node<T>* seeAt(int); // Return item found at given index
    void reset(); // Reset the seeNext pointer

    // Display all items in list
    void displayAll();
};

#endif
