#ifndef STABLE_CPP
#define STABLE_CPP

#include "Stable.h"
#include <string>
using namespace std;

// Constructors
    Stable::Stable(){
        horseCount=0;//Indicate that the stable is empty
    }
    class Stable::FullStable{
    };
    class Stable::EmptyStable{
    };

    // Getters and setters
    int Stable::getHorseCount(){
        return horseCount;
    }
    void Stable::setHorseCount(int newHorseCount){
        horseCount=newHorseCount;
    }

    //member functions
    void Stable::addHorse(Horse newHorse){
        if(horseCount<GLOBAL_MAX_HORSES){
            horseArray[horseCount]=newHorse;
            horseCount++;
        }
        else{
            FullStable error;
            throw error;
        }
    }
    Horse Stable::removeHorse(){
        if(horseCount>0){
            horseCount--;
        }
        else{
            EmptyStable error;
            throw error;
        }
    }
#endif
