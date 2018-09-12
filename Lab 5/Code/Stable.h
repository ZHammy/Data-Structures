#ifndef STABLE_H
#define STABLE_H

#include "Horse.cpp"
//change this to what the max number of horses should be
const int GLOBAL_MAX_HORSES = 10;

class Stable{
    private:
        Horse horseArray[GLOBAL_MAX_HORSES]; //Stores the horses
        int horseCount;//tracks the horseCount

    public:
        class FullStable;
        class EmptyStable;
        Stable();       //Default Constructor

        // Getters and setters
        int getHorseCount();
        void setHorseCount(int);

        //member functions
        void addHorse(Horse);
        Horse removeHorse();
};

#endif
