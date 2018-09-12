#ifndef ANIMAL_H
#define ANIMAL_H

class Animal {
protected:
    int legs;  // Number of legs the animal has
    bool hair; // If the animal has hair or not

public:
    Animal();          // Initializes it to an arbitrary animal
    Animal(int, bool); // Initialize legs and hair

    // Getters and setters
    int getLegs();
    bool getHair();
    void setLegs(int);
    void setHair(bool);

    // Member functions
    virtual void move();
    void eat();
};

#endif
