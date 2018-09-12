#ifndef HORSE_H
#define HORSE_H
//Same as the Lab 4 horse class but removed the animal stuff
class Horse{
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
