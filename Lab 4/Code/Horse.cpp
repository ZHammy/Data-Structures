#ifndef HORSE_CPP
#define HORSE_CPP

#include "Horse.h"
#include <iostream>

using namespace std;

// Constructors
Horse::Horse(){
    hands=15.2; // Average horse height
    legs=4;
    hair=true;
}
Horse::Horse(double hands_in){
    hands = hands_in;
    legs = 4;
    hair = true;
}

// Getters and setters
double Horse::getHands() { return hands; }
void Horse::setHands(double x) { hands=x; }

// Member functions
void Horse::move() { cout<<"Walk, Trot, Canter, Gallop."<<endl; }
void Horse::eat()  { cout<<"Yummy grass."<<endl; }

#endif
