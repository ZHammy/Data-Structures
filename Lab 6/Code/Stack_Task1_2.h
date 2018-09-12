#ifndef STACK_H
#define STACK_H


template <class T> class Stack {
    private:
        int maxSize; //maxSize of the data array
        T** dataArray;//have to determine size later
        int curLength;
    public:
        Stack(); //Default Constructor
        Stack(int);//If the size of dataArray is specified

        // Error classes
        class StackOverflow;
        class StackUnderflow;
        class InvalidMove;

        // Member functions
        int length();//returns the length of dataArray
        void push(T);//Adds item to stack
        T* pop();//removes and returns an item from the stack
        void empty();//empties the stack
        T* top();//returns a pointer to the top of the stack

        //friend functions
        friend void displayContents(Stack<int>, Stack<int>, Stack<int>);
        friend bool checkWin(Stack<int>);
};

#endif
