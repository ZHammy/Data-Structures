#ifndef STACK_H
#define STACK_H

// Block class for use alongside the stack class
class Block {
public:
    char symbol;   // Symbol to be displayed
    int playerNum; // Player number for this block
    int data;      // Block value

    Block();          // Default Constructor
    Block(char, int); // Initialize symbol and player num
};

template <class T> class Stack {
    private:
        int maxSize;   // Max size of the data array
        T** dataArray; // Have to determine size later
        int curLength;
    public:
        Stack();               // Default Constructor
        Stack(int);            // Initialize with given size

        // Error classes
        class StackOverflow;
        class StackUnderflow;
        class InvalidMove;

        // Member functions
        int length(); // Returns the length of dataArray
        void push(T); // Adds item to stack
        T* pop();     // Removes and returns an item from the stack
        void empty(); // Empties the stack
        T* top();     // Returns a pointer to the top of the stack

        // Friend functions
        friend void displayContents(Stack<Block>, Stack<Block>, Stack<Block>, Stack<Block>, Stack<Block>, int);
        friend bool checkWin(Stack<Block>, int, int);
};

#endif
