#ifndef STACK_CPP
#define STACK_CPP

#include <iostream>
#include "Stack_Task3.h"
using namespace std;

const int MAX_SIZE_DEFAULT = 10;
const int PLAYER_1_DEFAULT_STACK = 1;
const int PLAYER_2_DEFAULT_STACK = 5;

// --- Block ---
// Constructors
Block::Block(){
    symbol = '*';
    playerNum = 0;
}
Block::Block(char symbol_in, int playerNum_in){
    symbol = symbol_in;
    playerNum = playerNum_in;
}


// --- Stack ---
// Constructors
// For default, set length to 0 and size to 10
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
    } else if (curLength > 0 && newData.data > dataArray[curLength-1]->data) {
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
void displayRow(int width, int spaces, char symbol) {
    cout << " ";

    // If there is a width to this row, display normally
    if (width > 0) {
        spaces = spaces / 2;
        for (int i = 0; i < spaces; i++) { cout << " "; }
        for (int i = 0; i < width;  i++) { cout << symbol; }
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
// NOTE: Would be much cleaner with an array of stacks, in hinesight. Could revise if necessary.
void displayContents(Stack<Block> stack1, Stack<Block> stack2, Stack<Block> stack3, Stack<Block> stack4, Stack<Block> stack5, int blockCount){
    const int maxSize = stack1.maxSize; // Simply for easier referencing
    const int maxWidth = blockCount * 2 - 1;

    // Iterate through and display each stacks piece by row starting from the top
    for (int i = maxSize-1; i >= 0; i--) {
        // Assign the widths of each stack piece...
        // If this stack index is within the length of the stack, assign the width normally
        // Else, set the width to zero
        int width1 = i + 1 <= stack1.length()  ?  2 * stack1.dataArray[i]->data - 1  :  0;
        int width2 = i + 1 <= stack2.length()  ?  2 * stack2.dataArray[i]->data - 1  :  0;
        int width3 = i + 1 <= stack3.length()  ?  2 * stack3.dataArray[i]->data - 1  :  0;
        int width4 = i + 1 <= stack4.length()  ?  2 * stack4.dataArray[i]->data - 1  :  0;
        int width5 = i + 1 <= stack5.length()  ?  2 * stack5.dataArray[i]->data - 1  :  0;

        // How many spaces should there be total to surround the pieces
        // Set manually to allow for even stack formatting
        int spaces1 = maxWidth - width1;
        int spaces2 = maxWidth - width2;
        int spaces3 = maxWidth - width3;
        int spaces4 = maxWidth - width4;
        int spaces5 = maxWidth - width5;

        char symbol1 = i + 1 <= stack1.length() ? stack1.dataArray[i]->symbol : ' ';
        char symbol2 = i + 1 <= stack2.length() ? stack2.dataArray[i]->symbol : ' ';
        char symbol3 = i + 1 <= stack3.length() ? stack3.dataArray[i]->symbol : ' ';
        char symbol4 = i + 1 <= stack4.length() ? stack4.dataArray[i]->symbol : ' ';
        char symbol5 = i + 1 <= stack5.length() ? stack5.dataArray[i]->symbol : ' ';


        // First stack piece
        displayRow(width1, spaces1, symbol1);

        // Second stack piece
        displayRow(width2, spaces2, symbol2);

        // Third stack piece
        displayRow(width3, spaces3, symbol3);

        // Fourth stack piece
        displayRow(width4, spaces4, symbol4);

        // Fifth stack piece
        displayRow(width5, spaces5, symbol5);

        cout << endl;
    }

    // Display the bases for each stack to distinguish their locations
    for (int i = 1; i <= 5; i++) { displayBase(maxWidth, i); }
    cout << endl;
}
bool checkWin(Stack<Block> myStack, int blockCount, int stackNum) {
    // Exit immediately if not enough values in the stack
    if (myStack.length() < blockCount) { return false; }

    // Player win bools
    // First index is player 1, second index is player 2
    bool playerWins[] = {false, false};

    // Cycle through to check each player's win status
    for (int player = 1; player <= 2; player++) {
        // Exit if checking the player's default stack (since that does not allow for a win)
        if (player == 1 && stackNum == PLAYER_1_DEFAULT_STACK) { continue; }
        if (player == 2 && stackNum == PLAYER_2_DEFAULT_STACK) { continue; }

        int checkVal = 1; // Value we will check against
        for (int i = myStack.length() - 1; i >= 0; i--) {
            int playerNum = myStack.dataArray[i]->playerNum;
            int data = myStack.dataArray[i]->data;

            // If this value is what we are looking for and is from the current
            // player, increment the value we are looking for
            if (data == checkVal && playerNum == player) { checkVal++; }

            // If all block values are accounted for, set this win status to true
            if (checkVal > blockCount) { return true; }
        }
    }

    // Return true if one person ones
    return playerWins[0] || playerWins[1];
}

#endif
