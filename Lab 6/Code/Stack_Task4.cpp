#ifndef STACK_CPP
#define STACK_CPP

#include <iostream>
#include "Stack_Task4.h"
using namespace std;

const int MAX_SIZE_DEFAULT = 10;

// Constructors
//For default, set length to 0 and size to 10
template <class T> Stack<T>::Stack(){
    curLength=0;
    maxSize=MAX_SIZE_DEFAULT;
    dataArray=new T*[maxSize];
}

template <class T> Stack<T>::Stack(int size){
    curLength=0;
    maxSize=size;
    dataArray=new T*[maxSize];
}

// Error classes
template <class T> class Stack<T>::StackOverflow{};
template <class T> class Stack<T>::StackUnderflow{};
template <class T> class Stack<T>::InvalidMove{};


//member functions
template <class T> int Stack<T>::length(){
    return curLength;
}

template <class T> void Stack<T>::push(T newData){
    if (curLength >= maxSize) {
        StackOverflow error;
        throw error;
    } else if (curLength > 0 && newData > *dataArray[curLength-1]) {
        InvalidMove error;
        throw error;
    } else {
        T* temp=new T;
        *temp =newData;
        dataArray[curLength]=temp;
        curLength++;
    }
}

template <class T> T* Stack<T>::pop(){
    if(curLength>0){
        curLength--;
        return *&dataArray[curLength];
    }
    else{
        StackUnderflow error;
        throw error;
    }
}

template <class T> T* Stack<T>::top(){
    if(curLength>0){
        return *&dataArray[curLength-1];
    }
    else{
        StackUnderflow error;
        throw error;
    }
}

template <class T> void Stack<T>::empty(){
    for(int i=0;i<curLength;i++){
        delete dataArray[i];
    }
}


// ---- Display Functions ---

// displayContents helper function
// Displays one row using the given width and total number of spaces
void displayRow(int width, int spaces) {
    cout << " ";

    // If there is a width to this row, display normally
    if (width > 0) {
        spaces = spaces / 2;
        for (int i = 0; i < spaces; i++) { cout << " "; }
        for (int i = 0; i < width;  i++) { cout << "*"; }
        for (int i = 0; i < spaces; i++) { cout << " "; }

    // If there is no width, simply display the max number of spaces
    /* Has its own case since this is the only instance that
       the width would be even, so we need to specially account for the
       leftover piece that should be in the middle. */
    } else {
        for (int i = 0; i < spaces; i++) { cout << " "; }
    }

    cout << " ";
}

// displayContents helper function
// Displays the base of a stack with the given max width of the stack
// TODO: Display stack number within the base
void displayBase(int width, int num) {
    int half = (width - 1) / 2;
    cout << "|";
    for (int i = 0; i < half; i++) { cout << "-"; }
    cout << num;
    for (int i = 0; i < half; i++) { cout << "-"; }
    cout << "|";
}

// Displays three given stacks
// Assumes stacks are all of the same max size
void displayContents(Stack<int> stack1, Stack<int> stack2, Stack<int> stack3){
    const int maxSize = stack1.maxSize; // Simply for easier referencing
    const int maxWidth = maxSize * 2 - 1;

    // Iterate through and display each stacks piece by row starting from the top
    for (int i = maxSize-1; i >= 0; i--) {
        // Assign the widths of each stack piece...
        // If this stack index is within the length of the stack, assign the width normally
        // Else, set the width to zero
        int width1 = i + 1 <= stack1.length()  ?  2 * *stack1.dataArray[i] - 1  :  0;
        int width2 = i + 1 <= stack2.length()  ?  2 * *stack2.dataArray[i] - 1  :  0;
        int width3 = i + 1 <= stack3.length()  ?  2 * *stack3.dataArray[i] - 1  :  0;

        // How many spaces should there be total to surround the pieces
        // Set manually to allow for even stack formatting
        int spaces1 = maxWidth - width1;
        int spaces2 = maxWidth - width2;
        int spaces3 = maxWidth - width3;

        // First stack piece
        displayRow(width1, spaces1);

        // Second stack piece
        displayRow(width2, spaces2);

        // Third stack piece
        displayRow(width3, spaces3);

        cout << endl;
    }

    // Display the bases for each stack to distinguish their locations
    for (int i = 1; i <= 3; i++) { displayBase(maxWidth, i); }
    cout << endl;
}

bool checkWin(Stack<int> myStack) {
    if (myStack.length() < myStack.maxSize) {
        return false;
    } else {
        for (int i = myStack.maxSize - 1; i >= 0; i--) {
            if (*myStack.dataArray[i] != myStack.maxSize - i) {
                return false;
            }
        }

        return true;
    }
}

#endif
