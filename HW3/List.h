#ifndef LIST_H
#define LIST_H

#include "Card.cpp"

/*

Generic list class, including nodes
Defines all necessary possible functions
Stacks or queues using this should ideally control which functions are
called for their specific purposes

 */

class Node {
public:
    Card data;
    Node* next;

    // Constructors
    Node();
    Node(Card);
    Node(Card, Node*);
};

class List {
private:
    Node* first;
    int length;
    int maxLength;

public:
    // Constructor(s)
    List();
    List(int); // Give a max length

    // Error class(es)
    class ListUnderflow {};
    class ListOverflow {};

    // Getters / setters
    int getLength(); // Return user length
    Card top();       // Return first item of list
    bool isFull();
    bool isEmpty();

    // Add to list functions
    void push_front(Card); // Insert a value to the front of list
    void push_back(Card);  // Insert a value at the end of list

    // Remove from list functions
    Card pop_front(); // Remove first item from list and return it
    Card pop_back();  // Remove last item from list and return it
};

#endif
