#ifndef DIE_CPP
#define DIE_CPP

#include "Die.h"
#include <stdlib.h>//Needed for RNG
#include <time.h> //Used to seed Rand for different results every game
using namespace std;

// Constructor
Die::Die(){
    sides=6;
}

// Member functions
int Die::roll(){
    return ((rand()%sides +1)); // Seed is set in main
}

void Die::setSides(int x){
    sides=x;
}

int Die::getSides() {
    return sides;
}

#endif
