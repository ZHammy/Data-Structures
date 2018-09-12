#ifndef FISH_CPP
#define FISH_CPP

#include "Fish.h"
#include <iostream>
using namespace std;

// Constructors
Fish::Fish(){
    isSaltWater=true;
}
Fish::Fish(bool isSaltWater_in){
    isSaltWater = isSaltWater_in;
}

// Member getters and setters
bool Fish::getIsSaltWater() { return isSaltWater; }
void Fish::setIsSaltWater(bool x) { isSaltWater=x; }

// Member functions
void Fish::move(){ cout<<"Just keep swimming."<<endl; }
void Fish::eat(){ cout<<"Yummy Fish Food."<<endl; }

#endif
