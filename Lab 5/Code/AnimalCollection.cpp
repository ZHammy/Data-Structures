#ifndef ANIMAL_COLLECTION_CPP
#define ANIMAL_COLLECTION_CPP

#include "AnimalCollection.h"
#include <string>
using namespace std;

// Constructor
template <class T> AnimalCollection<T>::AnimalCollection(){
    count=0; //Indicate that the collection is empty
}

// Error classes
template <class T> class AnimalCollection<T>::FullAnimalCollection{};
template <class T> class AnimalCollection<T>::EmptyAnimalCollection{};

// Getters and setters
template <class T> int AnimalCollection<T>::getAnimalCount(){
    return count;
}

//member functions
template <class T> void AnimalCollection<T>::addAnimal(T newAnimal){
    if(count<GLOBAL_MAX_ANIMALS){
        dataArray[count]=newAnimal;
        count++;
    }
    else{
        FullAnimalCollection error;
        throw error;
    }
}
template <class T> T AnimalCollection<T>::removeAnimal(){
    if(count>0){
        count--;
    }
    else{
        EmptyAnimalCollection error;
        throw error;
    }
}
#endif
