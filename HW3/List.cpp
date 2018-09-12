#ifndef LIST_CPP
#define LIST_CPP

#include "List.h"
using namespace std;

// ----- Node -----

Node::Node() {
    Card newCard;
    data = newCard;
    next = nullptr;
}
Node::Node(Card val) {
    data = val;
    next = nullptr;
}
Node::Node(Card val, Node* ptr) {
    data = val;
    next = ptr;
}


// ----- Linked List -----

// Constructor(s)
List::List() {
    first = nullptr;
    length = 0;
    maxLength = 1000;
}
List::List(int maxLength_in) {
    first = nullptr;
    length = 0;
    maxLength = maxLength_in;
}

// Getters / setters
int List::getLength() { return length; }
Card List::top() { return first->data; }
bool List::isFull() { return length >= maxLength; }
bool List::isEmpty() { return length <= 0; }

// Add to list functions
void List::push_front(Card val) {
    if (length >= maxLength) { throw *new ListOverflow; }
    Node *temp = new Node(val, first);
    first = temp;
    length++;
}
void List::push_back(Card val) {
    if (length >= maxLength) { throw *new ListOverflow; }
    Node *temp = new Node(val, nullptr);

    if (first == nullptr) {
        first = temp;
    } else {
        Node *end = first; // Temp node to cycle through list

        // Find a pointer to the last element in the list
        while (end -> next != nullptr) { end = end->next; }
        end->next = temp;
    }

    length++;
}

// Remove from list functions
Card List::pop_front() {
    // If there is nothing in the list, throw an error
    if (first == nullptr) { throw *new ListUnderflow; }

    // Store data that will be removed
    Card returnVal = first->data;

    // Delete first value and move current first value to its next
    Node *temp = first;
    first = first->next;
    delete temp;
    length--;

    return returnVal;
}
Card List::pop_back() {
    // If there is nothing in the list, throw an error
    if (first == nullptr) { throw *new ListUnderflow; }

    // To store data that will be removed
    Card returnVal = first->data;
    Node *end = first;

    if (first->next == nullptr) {
        returnVal = first->data;

        first = first->next;
        delete end;
    } else {
        while (end->next->next != nullptr) {
            end = end->next;
        }

        returnVal = end->next->data;
        // NOTE: Does end->next need to be deleted before reassignment?
        //       i.e. does this line cause a memory leak?
        delete end->next->next;
        end->next = nullptr;
    }

    length--;
    return returnVal;
}

#endif
