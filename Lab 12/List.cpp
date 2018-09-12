#ifndef LIST_CPP
#define LIST_CPP

#include <iostream>
#include "List.h"
#include "Student.cpp"
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
    opCount = 0;
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
        if (temp->data == *val) { return true; }
        temp = temp->next;
    }

    // Return false if this point is reached (val is not found)
    return false;
}
template <class T> bool List<T>::isEmpty() { return (length <= 0); }
template <class T> int List<T>::size() { return length; }
template <class T> int List<T>::getOpCount() { return opCount; }

// Add / remove functions
template <class T> void List<T>::addItem(T* val) {
    Node<T> *temp = new Node<T>(*val);

    // If first is empty or the first val is larger,
    // insert at beginning
    if (first == nullptr || first->data >= *val) {
        temp->next = first;
        first = temp;

    // Else, search for val and insert where necessary
    } else {
        Node<T> *iter = first; // Temp node to cycle through list

        // Find a pointer where this val fits in the list
        while (iter->next != nullptr && iter->next->data < *val) {
            iter = iter->next;
        }

        temp->next = iter->next;
        iter->next = temp;
    }

    length++;
}

template <class T> T* List<T>::getItem(T* val) {
    opCount = 0;

    // If there is nothing in the list, throw an error
    if (first == nullptr) { throw *new ListUnderflow; }

    // To store data that will be removed
    T* returnVal = new T();
    Node<T> *iter = first;

    opCount++; // Increment for the initial comparison
    if (first->data == *val) {
        *returnVal = first->data;

    } else {
        bool found = false;

        while (iter->next != nullptr) {
            opCount++;
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
    }

    return returnVal;
}

template <class T> T* List<T>::removeItem(T* val) {
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
            cout << endl; // For readability
            temp=seeNext(); // Increment temp to next item
        }

        *look = tempLook; // Reset the look var back to its original state

    } else {
        cout << "No items in list to display!" << endl;
    }
}
//****************************************************************************
//Bubble Sorts
template <class T> void List<T>::bubSortFNameD() {
    T myArray[length];
    Node<T>* tempNode=first;
    for(int i=0;i<length;i++){
        myArray[i]=tempNode->data;
        tempNode=tempNode->next;
    }
    bool sorted;
    T temp;
    do {
        sorted = true; // Array is sorted until otherwise stated
        for (int i = 1; i < length; i++) {
            if (myArray[i].FirstName>myArray[i-1].FirstName) {
                sorted = false;

                // Swap array values
                temp = myArray[i-1];
                myArray[i-1] = myArray[i];
                myArray[i] = temp;
            }
        }
    } while (!sorted);
    tempNode=first;
    for(int i=0;i<length;i++){
        tempNode->data=myArray[i];
        tempNode=tempNode->next;
    }
}

template <class T> void List<T>::bubSortFNameA() {
    T myArray[length];
    Node<T>* tempNode=first;
    for(int i=0;i<length;i++){
        myArray[i]=tempNode->data;
        tempNode=tempNode->next;
    }
    bool sorted;
    T temp;
    do {
        sorted = true; // Array is sorted until otherwise stated
        for (int i = 1; i < length; i++) {
            if (myArray[i].FirstName<myArray[i-1].FirstName) {
                sorted = false;

                // Swap array values
                temp = myArray[i-1];
                myArray[i-1] = myArray[i];
                myArray[i] = temp;
            }
        }
    } while (!sorted);
    tempNode=first;
    for(int i=0;i<length;i++){
        tempNode->data=myArray[i];
        tempNode=tempNode->next;
    }
}

template <class T> void List<T>::bubSortLNameD() {
    T myArray[length];
    Node<T>* tempNode=first;
    for(int i=0;i<length;i++){
        myArray[i]=tempNode->data;
        tempNode=tempNode->next;
    }
    bool sorted;
    T temp;
    do {
        sorted = true; // Array is sorted until otherwise stated
        for (int i = 1; i < length; i++) {
            if (myArray[i].LastName>myArray[i-1].LastName) {
                sorted = false;

                // Swap array values
                temp = myArray[i-1];
                myArray[i-1] = myArray[i];
                myArray[i] = temp;
            }
        }
    } while (!sorted);
    tempNode=first;
    for(int i=0;i<length;i++){
        tempNode->data=myArray[i];
        tempNode=tempNode->next;
    }
}

template <class T> void List<T>::bubSortLNameA() {
    T myArray[length];
    Node<T>* tempNode=first;
    for(int i=0;i<length;i++){
        myArray[i]=tempNode->data;
        tempNode=tempNode->next;
    }
    bool sorted;
    T temp;
    do {
        sorted = true; // Array is sorted until otherwise stated
        for (int i = 1; i < length; i++) {
            if (myArray[i].LastName<myArray[i-1].LastName) {
                sorted = false;

                // Swap array values
                temp = myArray[i-1];
                myArray[i-1] = myArray[i];
                myArray[i] = temp;
            }
        }
    } while (!sorted);
    tempNode=first;
    for(int i=0;i<length;i++){
        tempNode->data=myArray[i];
        tempNode=tempNode->next;
    }
}

template <class T> void List<T>::bubSortMNumD() {
    T myArray[length];
    Node<T>* tempNode=first;
    for(int i=0;i<length;i++){
        myArray[i]=tempNode->data;
        tempNode=tempNode->next;
    }
    bool sorted;
    T temp;
    do {
        sorted = true; // Array is sorted until otherwise stated
        for (int i = 1; i < length; i++) {
            if (myArray[i].MNumber>myArray[i-1].MNumber) {
                sorted = false;

                // Swap array values
                temp = myArray[i-1];
                myArray[i-1] = myArray[i];
                myArray[i] = temp;
            }
        }
    } while (!sorted);
    tempNode=first;
    for(int i=0;i<length;i++){
        tempNode->data=myArray[i];
        tempNode=tempNode->next;
    }
}

template <class T> void List<T>::bubSortMNumA() {
    T myArray[length];
    Node<T>* tempNode=first;
    for(int i=0;i<length;i++){
        myArray[i]=tempNode->data;
        tempNode=tempNode->next;
    }
    bool sorted;
    T temp;
    do {
        sorted = true; // Array is sorted until otherwise stated
        for (int i = 1; i < length; i++) {
            if (myArray[i].MNumber<myArray[i-1].MNumber) {
                sorted = false;

                // Swap array values
                temp = myArray[i-1];
                myArray[i-1] = myArray[i];
                myArray[i] = temp;
            }
        }
    } while (!sorted);
    tempNode=first;
    for(int i=0;i<length;i++){
        tempNode->data=myArray[i];
        tempNode=tempNode->next;
    }
}

//*******************************************************************************
//Insertion Sorts
template <class T> void List<T>::insSortFNameD() {
    T myArray[length];
    Node<T>* tempNode=first;
    for(int i=0;i<length;i++){
        myArray[i]=tempNode->data;
        tempNode=tempNode->next;
    }
    T temp; // Temp var for swapping

    for (int i = 0; i < length-1; i++) {
        for (int j = i+1; j >= 1; j--) {
            // Swap items if out of order
            if (myArray[j-1].FirstName > myArray[j].FirstName) {
                temp = myArray[j-1];
                myArray[j-1] = myArray[j];
                myArray[j] = temp;

            // If these items are in order, so is rest of list.
            // So, we break from just the inner loop
            } else {
                break;
            }
        }
    }
    tempNode=first;
    for(int i=length-1;i>-1;i--){
        tempNode->data=myArray[i];
        tempNode=tempNode->next;
    }
}

template <class T> void List<T>::insSortFNameA() {
    T myArray[length];
    Node<T>* tempNode=first;
    for(int i=0;i<length;i++){
        myArray[i]=tempNode->data;
        tempNode=tempNode->next;
    }
    T temp; // Temp var for swapping
    for (int i = 0; i < length-1; i++) {
        for (int j = i+1; j >= 1; j--) {
            // Swap items if out of order
            if (myArray[j-1].FirstName > myArray[j].FirstName) {
                temp = myArray[j-1];
                myArray[j-1] = myArray[j];
                myArray[j] = temp;

            // If these items are in order, so is rest of list.
            // So, we break from just the inner loop
            } else {
                break;
            }
        }
    }
    tempNode=first;
    for(int i=0;i<length;i++){
        tempNode->data=myArray[i];
        tempNode=tempNode->next;
    }
}

template <class T> void List<T>::insSortLNameD() {
    T myArray[length];
    Node<T>* tempNode=first;
    for(int i=0;i<length;i++){
        myArray[i]=tempNode->data;
        tempNode=tempNode->next;
    }
    T temp; // Temp var for swapping
    for (int i = 0; i < length-1; i++) {
        for (int j = i+1; j >= 1; j--) {
            // Swap items if out of order
            if (myArray[j-1].LastName < myArray[j].LastName) {
                temp = myArray[j-1];
                myArray[j-1] = myArray[j];
                myArray[j] = temp;

            // If these items are in order, so is rest of list.
            // So, we break from just the inner loop
            } else {
                break;
            }
        }
    }
    tempNode=first;
    for(int i=0;i<length;i++){
        tempNode->data=myArray[i];
        tempNode=tempNode->next;
    }
}

template <class T> void List<T>::insSortLNameA() {
    T myArray[length];
    Node<T>* tempNode=first;
    for(int i=0;i<length;i++){
        myArray[i]=tempNode->data;
        tempNode=tempNode->next;
    }
    T temp; // Temp var for swapping

    for (int i = 0; i < length-1; i++) {
        for (int j = i+1; j >= 1; j--) {
            // Swap items if out of order
            if (myArray[j-1].LastName > myArray[j].LastName) {
                temp = myArray[j-1];
                myArray[j-1] = myArray[j];
                myArray[j] = temp;

            // If these items are in order, so is rest of list.
            // So, we break from just the inner loop
            } else {
                break;
            }
        }
    }
    tempNode=first;
    for(int i=0;i<length;i++){
        tempNode->data=myArray[i];
        tempNode=tempNode->next;
    }
}

template <class T> void List<T>::insSortMNumD() {
    T myArray[length];
    Node<T>* tempNode=first;
    for(int i=0;i<length;i++){
        myArray[i]=tempNode->data;
        tempNode=tempNode->next;
    }
    T temp; // Temp var for swapping

    for (int i = 0; i < length-1; i++) {
        for (int j = i+1; j >= 1; j--) {
            // Swap items if out of order
            if (myArray[j-1].MNumber < myArray[j].MNumber) {
                temp = myArray[j-1];
                myArray[j-1] = myArray[j];
                myArray[j] = temp;

            // If these items are in order, so is rest of list.
            // So, we break from just the inner loop
            } else {
                break;
            }
        }
    }
    tempNode=first;
    for(int i=0;i<length;i++){
        tempNode->data=myArray[i];
        tempNode=tempNode->next;
    }
}

template <class T> void List<T>::insSortMNumA() {
    T myArray[length];
    Node<T>* tempNode=first;
    for(int i=0;i<length;i++){
        myArray[i]=tempNode->data;
        tempNode=tempNode->next;
    }
    T temp; // Temp var for swapping

    for (int i = 0; i < length-1; i++) {
        for (int j = i+1; j >= 1; j--) {
            // Swap items if out of order
            if (myArray[j-1].MNumber > myArray[j].MNumber) {
                temp = myArray[j-1];
                myArray[j-1] = myArray[j];
                myArray[j] = temp;

            // If these items are in order, so is rest of list.
            // So, we break from just the inner loop
            } else {
                break;
            }
        }
    }
    tempNode=first;
    for(int i=0;i<length;i++){
        tempNode->data=myArray[i];
        tempNode=tempNode->next;
    }
}


//******************************************************************************
//heapnting
template <class T> void List<T>::buildFHeap(T myArray[],int size,int index) {
    int largest = index;
    int leftChild = 2*index + 1;
    int rightChild = 2*index + 2;

    // If left child is larger than largest
    if (leftChild < size && myArray[leftChild].FirstName > myArray[largest].FirstName)
        largest = leftChild;

    // If right child is larger than largest
    if (rightChild < size && myArray[rightChild].FirstName > myArray[largest].FirstName)
        largest = rightChild;

    // If largest is not the original root
    if (largest != index){
        T temp=myArray[index];
        myArray[index]=myArray[largest];
        myArray[largest]=temp;

        // Recursively build the heap
        buildFHeap(myArray,size, largest);
    }
}

template <class T> void List<T>::buildLHeap(T myArray[],int size,int index) {
    int largest = index;
    int leftChild = 2*index + 1;
    int rightChild = 2*index + 2;

    // If left child is larger than largest
    if (leftChild < size && myArray[leftChild].LastName > myArray[largest].LastName)
        largest = leftChild;

    // If right child is larger than largest
    if (rightChild < size && myArray[rightChild].LastName > myArray[largest].LastName)
        largest = rightChild;

    // If largest is not the original root
    if (largest != index){
        T temp=myArray[index];
        myArray[index]=myArray[largest];
        myArray[largest]=temp;

        // Recursively build the heap
        buildLHeap(myArray,size, largest);
    }
}
template <class T> void List<T>::buildMHeap(T myArray[],int size,int index) {
    int largest = index;
    int leftChild = 2*index + 1;
    int rightChild = 2*index + 2;

    // If left child is larger than largest
    if (leftChild < size && myArray[leftChild].MNumber > myArray[largest].MNumber)
        largest = leftChild;

    // If right child is larger than largest
    if (rightChild < size && myArray[rightChild].MNumber > myArray[largest].MNumber)
        largest = rightChild;

    // If largest is not the original root
    if (largest != index){
        T temp=myArray[index];
        myArray[index]=myArray[largest];
        myArray[largest]=temp;

        // Recursively build the heap
        buildMHeap(myArray,size, largest);
    }
}

template <class T> void List<T>::heapSortFNameA() {
    T myArray[length];
    Node<T>* tempNode=first;
    for(int i=0;i<length;i++){
        myArray[i]=tempNode->data;
        tempNode=tempNode->next;
    }
    for(int i=(length/2)-1;i>=0;i--){
        buildFHeap(myArray,length,i);
    }
    for(int i=length-1;i>=0;i--){
        T temp=myArray[0];
        myArray[0]=myArray[i];
        myArray[i]=temp;
        buildFHeap(myArray,i,0);
    }
    tempNode=first;
    for(int i=0;i<length;i++){
        tempNode->data=myArray[i];
        tempNode=tempNode->next;
    }
}

template <class T> void List<T>::heapSortFNameD() {
    T myArray[length];
    Node<T>* tempNode=first;
    for(int i=0;i<length;i++){
        myArray[i]=tempNode->data;
        tempNode=tempNode->next;
    }
    for(int i=(length/2)-1;i>=0;i--){
        buildFHeap(myArray,length,i);
    }
    for(int i=length-1;i>=0;i--){
        T temp=myArray[0];
        myArray[0]=myArray[i];
        myArray[i]=temp;
        buildFHeap(myArray,i,0);
    }
    tempNode=first;
    for(int i=length-1;i>-1;i--){
        tempNode->data=myArray[i];
        tempNode=tempNode->next;
    }
}

template <class T> void List<T>::heapSortLNameA() {
    T myArray[length];
    Node<T>* tempNode=first;
    for(int i=0;i<length;i++){
        myArray[i]=tempNode->data;
        tempNode=tempNode->next;
    }
    for(int i=(length/2)-1;i>=0;i--){
        buildLHeap(myArray,length,i);
    }
    for(int i=length-1;i>=0;i--){
        T temp=myArray[0];
        myArray[0]=myArray[i];
        myArray[i]=temp;
        buildLHeap(myArray,i,0);
    }
    tempNode=first;
    for(int i=0;i<length;i++){
        tempNode->data=myArray[i];
        tempNode=tempNode->next;
    }
}

template <class T> void List<T>::heapSortLNameD() {
    T myArray[length];
    Node<T>* tempNode=first;
    for(int i=0;i<length;i++){
        myArray[i]=tempNode->data;
        tempNode=tempNode->next;
    }
    for(int i=(length/2)-1;i>=0;i--){
        buildLHeap(myArray,length,i);
    }
    for(int i=length-1;i>=0;i--){
        T temp=myArray[0];
        myArray[0]=myArray[i];
        myArray[i]=temp;
        buildLHeap(myArray,i,0);
    }
    tempNode=first;
    for(int i=length-1;i>-1;i--){
        tempNode->data=myArray[i];
        tempNode=tempNode->next;
    }
}

template <class T> void List<T>::heapSortMNumA() {
    T myArray[length];
    Node<T>* tempNode=first;
    for(int i=0;i<length;i++){
        myArray[i]=tempNode->data;
        tempNode=tempNode->next;
    }
    for(int i=(length/2)-1;i>=0;i--){
        buildMHeap(myArray,length,i);
    }
    for(int i=length-1;i>=0;i--){
        T temp=myArray[0];
        myArray[0]=myArray[i];
        myArray[i]=temp;
        buildMHeap(myArray,i,0);
    }
    tempNode=first;
    for(int i=0;i<length;i++){
        tempNode->data=myArray[i];
        tempNode=tempNode->next;
    }
}

template <class T> void List<T>::heapSortMNumD() {
    T myArray[length];
    Node<T>* tempNode=first;
    for(int i=0;i<length;i++){
        myArray[i]=tempNode->data;
        tempNode=tempNode->next;
    }
    for(int i=(length/2)-1;i>=0;i--){
        buildMHeap(myArray,length,i);
    }
    for(int i=length-1;i>=0;i--){
        T temp=myArray[0];
        myArray[0]=myArray[i];
        myArray[i]=temp;
        buildMHeap(myArray,i,0);
    }
    tempNode=first;
    for(int i=length-1;i>-1;i--){
        tempNode->data=myArray[i];
        tempNode=tempNode->next;
    }
}

#endif
