#ifndef DECK_CPP
#define DECK_CPP

#include "Deck.h"
using namespace std;

// Constructor(s)
Deck::Deck(){
    data = *new List();
}

// Getters / setters
int Deck::getLength() { return data.getLength(); }
Card Deck::top() { return data.top(); }
bool Deck::isEmpty() { return data.isEmpty(); }

// Add to Deck function
void Deck::push_back(Card val) { data.push_back(val); }

// Remove from Deck function
Card Deck::pop_front() { return data.pop_front(); }

#endif
