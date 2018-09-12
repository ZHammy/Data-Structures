#ifndef DICE_H
#define DICE_H

class Die{
private:
    int sides; // Number of sides the die should have
    int seed;  // Random roll seed
public:
    // Constructor
    Die();

    // Roll the die and return result
    int roll();

    // Setters and getters
    void setSides(int);
    int getSides();
};
#endif
