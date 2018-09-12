#ifndef CARD_CPP
#define CARD_CPP

#include "Card.h"
#include <string>
using namespace std;

// Constructors
Card::Card(){
    value=-1;
    cardType="Error Card";
}
Card::Card(int val, string name) {
    value = val;
    cardType = name;
}

// Getters
int Card::getValue(){ return value; }
string Card::getCardType(){ return cardType; }
bool Card::isError(){ return value == -1; }

#endif
