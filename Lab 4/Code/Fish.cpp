#ifndef FISH_CPP
#define FISH_CPP

#include "Fish.h"
#include <iostream>
using namespace std;

// Constructors
Fish::Fish(){
    isSaltWater=true;
    legs = 0;
    hair = false;
}
Fish::Fish(bool isSaltWater_in){
    isSaltWater = isSaltWater_in;
    legs = 0;
    hair = false;
}

// Member getters and setters
bool Fish::getIsSaltWater() { return isSaltWater; }
void Fish::setIsSaltWater(bool x) { isSaltWater=x; }

// Member functions
void Fish::move(){ cout<<"Just keep swimming."<<endl; }
void Fish::eat(){ cout<<"Yummy Fish Food."<<endl; }

#endif
