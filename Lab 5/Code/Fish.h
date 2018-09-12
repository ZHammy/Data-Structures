#ifndef FISH_H
#define FISH_H


class Fish {
    private:
        bool isSaltWater; // If the fish lives in salt water
    public:
        Fish();     // Initializes it to a standard, salt water fish
        Fish(bool); // Initializes isSaltWater based on parameter

        // Getters and setters
        bool getIsSaltWater();
        void setIsSaltWater(bool);

        // Member functions
        void move();
        void eat();
};

#endif
