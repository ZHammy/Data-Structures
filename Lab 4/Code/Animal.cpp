#ifndef ANIMAL_CPP
#define ANIMAL_CPP

#include "Animal.h"
#include <iostream>

using namespace std;

// Constructors
Animal::Animal() {
    legs = 0;
    hair = 0;
}

Animal::Animal(int legs_in, bool hair_in) {
    legs = legs_in;
    hair = hair_in;
}

// Member setters and getters
int Animal::getLegs()  { return legs; }
bool Animal::getHair() { return hair; }
void Animal::setLegs(int legs_in)  { legs = legs_in; }
void Animal::setHair(bool hair_in) { hair = hair_in; }

// Member functions
void Animal::move() { cout << "Move"   << endl; }
void Animal::eat()  { cout << "Yummy!" << endl; }

#endif
