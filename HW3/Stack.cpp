#ifndef STACK_CPP
#define STACK_CPP

#include "Stack.h"
using namespace std;

int MAX_STACK_LENGTH = 5;

// Constructor
Stack::Stack() {
    data = *new List(MAX_STACK_LENGTH);
}

// Getters / setters
int Stack::getLength() { return data.getLength(); }
Card Stack::top() { return data.top(); }
bool Stack::isFull() { return data.isFull(); }
bool Stack::isEmpty() {return data.isEmpty(); }

// Add to stack function
void Stack::push_front(Card val) { data.push_front(val); }

// Remove from stack function
Card Stack::pop_front() { return data.pop_front(); }

#endif
