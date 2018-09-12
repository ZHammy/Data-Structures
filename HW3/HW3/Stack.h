#ifndef STACK_H
#define STACK_H

#include "Card.cpp"
#include "List.cpp"

class Stack {
private:
    List data;

public:
    // Constructor
    Stack();

    // Error classes
    class StackUnderflow {};
    class StackOverflow{};

    // Getters / setters
    int getLength(); // Return user length
    Card top();      // Return first item of Stack
    bool isFull();
    bool isEmpty();

    // Add to / remove Stack functions
    void push_front(Card); // Insert a value to the front of Stack
    Card pop_front();      // Remove first item from Stack and return it

};

#endif
