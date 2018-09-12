#ifndef HORSE_H
#define HORSE_H

#include "Animal.cpp"

class Horse: public Animal{
    private:
        double hands; // How many hands tall the horse is
    public:
        Horse();       // Initializes it to an average horse
        Horse(double); // Initialize height in hands based on parameter

        // Getters and setters
        double getHands();
        void setHands(double);

        // Member functions
        void move();
        void eat();
};

#endif
