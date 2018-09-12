#ifndef HASHCHAIN_CPP
#define HASHCHAIN_CPP

#include <iostream>
#include <string>
#include "HashChain.h"
using namespace std;

// Constructor(s)
template <class T> HashChain<T>::HashChain() {
    maxLength=100;
    length = 0;
    table = new List<T>*[maxLength];
    for (int i = 0; i < maxLength; i++) {
        table[i] = new List<T>();
    }
}
template <class T> HashChain<T>::HashChain(int size) {
    maxLength=size;
    length = 0;
    table = new List<T>*[maxLength];
    for (int i = 0; i < maxLength; i++) {
        table[i] = new List<T>();
    }
}

// Destructor
template <class T> HashChain<T>::~HashChain() {
    for(int i=0;i<maxLength;i++){
        table[i]->makeEmpty();
    }
}

template <class T> HashChain<T>::getLength() { return length; }

template <class T> HashChain<T>::getOpCount() { return opCount; }

template <class T> void HashChain<T>::addItem(T* val) {
    int hash = generateHash<T>(val, maxLength);
    table[hash]->addItem(val); // Add this value to the proper linked list
    length++;
}

// Add / remove functions
template <class T> T* HashChain<T>::removeItem(T* val) {
    int hash = generateHash<T>(val, maxLength);
    T* retVal = nullptr;

    try {
        retVal = table[hash]->removeItem(val);
        length--;

    // List gives either of these errors if the value isn't found
    } catch (typename List<T>::ListItemNotFound) {
        cout << "Item not found!" << endl;
    } catch (typename List<T>::ListUnderflow) {
        cout << "Item not found!" << endl;
    }

    return retVal;
}

template <class T> T* HashChain<T>::getItem(T* val) {
    int hash = generateHash<T>(val, maxLength);
    T* retVal = nullptr;

    try {
        retVal = table[hash]->getItem(val);

    // List gives either of these errors if the value isn't found
    } catch (typename List<T>::ListItemNotFound) {
        cout << "Item not found!" << endl;
    } catch (typename List<T>::ListUnderflow) {
        cout << "Item not found!" << endl;
    }

    // Get the opcount for the last operation
    opCount = table[hash]->getOpCount();

    return retVal;
}


#endif
