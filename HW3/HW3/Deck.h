#ifndef DECK_H
#define DECK_H

#include "Card.cpp"
#include "List.cpp"

class Deck {
private:
    List data;

public:
    // Constructor(s)
    Deck();

    // Error class(es)
    class DeckUnderflow {};

    // Getters / setters
    int getLength(); // Return user length
    Card top();      // Return first item of list
    bool isEmpty();  // Return if deck is empty

    // Add to list functions
    void push_back(Card);   // Insert a value at the end of list

    // Remove from list functions
    Card pop_front(); // Remove first item from list and return it
};

#endif
