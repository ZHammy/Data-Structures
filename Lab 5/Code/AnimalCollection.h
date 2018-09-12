#ifndef ANIMAL_COLLECTION_H
#define ANIMAL_COLLECTION_H

// Change this to what the max number of animals should be
const int GLOBAL_MAX_ANIMALS = 10;

template <class T> class AnimalCollection {
    private:
        T dataArray[GLOBAL_MAX_ANIMALS]; // Stores the animals
        int count; // Tracks the number of animals

    public:
        AnimalCollection(); //Default Constructor

        // Error classes
        class FullAnimalCollection;
        class EmptyAnimalCollection;

        // Getters
        int getAnimalCount();

        // Member functions
        void addAnimal(T);
        T removeAnimal();
};

#endif
