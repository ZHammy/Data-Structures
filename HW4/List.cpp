#ifndef LIST_CPP
#define LIST_CPP

#include <iostream>
#include "List.h"
using namespace std;

// ----- Node -----
template <class T> Node<T>::Node() {
    next = nullptr;
}
template <class T> Node<T>::Node(T val) {
    data = val;
    next = nullptr;
}
template <class T> Node<T>::Node(T val, Node<T>* ptr) {
    data = val;
    next = ptr;
}


// ----- Linked List -----

// Constructor(s)
template <class T> List<T>::List() {
    first = nullptr;
    look = new int(0);
    length = 0;
}

// Destructor
template <class T> List<T>::~List() {
    // Empty the class memory allocations on item deletion
    makeEmpty();
}

// Basic functions
template <class T> bool List<T>::isInList(T* val) {
    Node<T> *temp = first;

    // Search through list and return true once val is found
    while (temp != nullptr) {
        if (temp->data == *val) { return new bool(true); }
        temp = temp->next;
    }

    // Return false if this point is reached (val is not found)
    return new bool(false);
}
template <class T> bool List<T>::isEmpty() { return (length <= 0); }
template <class T> int List<T>::size() { return length; }

// Add / remove functions
template <class T> void List<T>::addItem(T* val) {
    Node<T> *temp = new Node<T>(*val);

    // If first is empty or the first val is larger,
    // insert at beginning
    if (first == nullptr || first->data <= *val) {
        temp->next = first;
        first = temp;

    // Else, search for val and insert where necessary
    } else {
        Node<T> *iter = first; // Temp node to cycle through list

        // Find a pointer where this val fits in the list
        while (iter->next != nullptr && iter->next->data > *val) {
            iter = iter->next;
        }

        temp->next = iter->next;
        iter->next = temp;
    }

    length++;
}

template <class T> T* List<T>::getItem(T* val) {
    // If there is nothing in the list, throw an error
    if (first == nullptr) { throw *new ListUnderflow; }

    // To store data that will be removed
    T* returnVal = new T();
    Node<T> *iter = first;

    if (first->data == *val) {
        *returnVal = first->data;

        first = first->next;
        delete iter;
    } else {
        bool found = false;

        while (iter->next != nullptr) {
            if (iter->next->data == *val) {
                found = true;
                break;
            }

            iter = iter->next;
        }

        // Error out if the item was never found
        if (!found) {
            delete returnVal;
            throw *new ListItemNotFound;
        }

        *returnVal = iter->next->data;

        Node<T>* delNode = iter->next;
        iter->next = iter->next->next;

        delete delNode;
    }

    length--;
    return returnVal;
}

template <class T> T List<T>::pop() {
    // If there is nothing in the list, throw an error
    if (first == nullptr) { throw *new ListUnderflow; }

    // To store data that will be removed
    T returnVal = first->data;

    // Remove first item
    Node<T>* delNode = first;
    first = first->next;
    delete delNode;

    length--;
    return returnVal;
}

template <class T> void List<T>::makeEmpty() {
    // Temp node to keep track of next node
    Node<T> *nextNode = new Node<T>();

    // Delete all memory allocations until first is empty
    while (first != nullptr) {
        nextNode = first->next;
        delete first;
        first = nextNode;
    }
}

// See functions
template <class T> Node<T>* List<T>::seeNext() {
    /* Look at the next index set by the List member

       If we're looking past the length, simply return nullptr
       instead of erroring out

       Other error checking + look indexing within seeAt function */

    return *look < length ? seeAt(*look) : nullptr;
}

template <class T> Node<T>* List<T>::seeAt(int index) {
    // Throw error if looking past list length
    if (index >= length) { throw *new ListEnd; }
    // Throw error if no data is in the list
    if (length == 0) { throw *new ListUnderflow; }

    // Find the item
    Node<T> *temp = first;
    for(int i = 0; i < index; i++) {
        temp = temp->next;
    }

    // Increment look index
    *look = index + 1;
    return temp;
}

template <class T> void List<T>::reset() { *look = 0; }

template <class T> void List<T>::displayAll() {
    if (length > 0) {
        int tempLook = *look; // Temp var for storing the current look val

        // Set look to the first val and retrieve it
        reset();
        Node<T> *temp = seeNext();

        // Display all items in list
        while (temp != nullptr) {
            // Display this item
            temp->data.displayData();
            cout << endl;

            // Output arrow to indicate pointers between items
            if (temp->next != nullptr) {
                cout << "   |" << endl;
                cout << "   |" << endl;
                cout << "  \\|/" << endl;
                cout << "   V" << endl;
            }

            temp=seeNext(); // Increment temp to next item
            cout << endl; // For visibility between items
        }

        *look = tempLook; // Reset the look var back to its original state

    } else {
        cout << "No items in list to display!" << endl;
    }
}

#endif
