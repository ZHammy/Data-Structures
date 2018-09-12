#ifndef HASHTABLE_CPP
#define HASHTABLE_CPP

#include <iostream>
#include <string>
#include "HashTable.h"
using namespace std;

template <class T> int generateHash(T* val, int maxLength) {
    int hash =0;
    string valString = string(*val);

    for(int i=0;i<valString.length();i++){
        hash+=int(valString.at(i));
    };
    return hash%maxLength;
}

// ----- Data -----
template <class T> Data<T>::Data() {
    data = nullptr;
    key = -9999;
}
template <class T> Data<T>::Data(T* val, int maxLength) {
    data = val;
    key = generateHash(data, maxLength);
}
// Operator overloads
template <class T> bool Data<T>::operator > (Data<T> &data2) {
    return data > data2.data;
}

template <class T> bool Data<T>::operator < (Data<T> &data2) {
    return data < data2.data;
}

template <class T> bool Data<T>::operator == (Data<T> &data2) {
    return key == data2.key && *(data2.data) == *data;
}

template <class T> bool Data<T>::operator <= (Data<T> &data2) {
    return data <= data2.data;
}

template <class T> bool Data<T>::operator >= (Data<T> &data2) {
    return data <= data2.data;
}

// Constructor(s)
template <class T> HashTable<T>::HashTable() {
    maxLength=100;
    length=0;
    table = new Data<T>*[100];

    // Initialize all table values to nullptr
    for( int i = 0; i < maxLength; i++) { table[i] = nullptr; }
}
template <class T> HashTable<T>::HashTable(int size) {
    maxLength=size;
    length=0;
    table = new Data<T>*[maxLength];

    // Initialize all table values to nullptr
    for( int i = 0; i < maxLength; i++) { table[i] = nullptr; }
}

// Destructor
template <class T> HashTable<T>::~HashTable() {
    for(int i=0;i<maxLength;i++){
        delete table[i];
    }
}

template <class T> int HashTable<T>::getLength() { return length; }
template <class T> int HashTable<T>::getOpCount() { return opCount; }

// Add / remove functions
template <class T> void HashTable<T>::addItem(T* val) {
    // Exit if the table is already full
    // TODO: Should probably throw an error
    if(length >= maxLength) { cout << "Table already full!" << endl; return; }

    Data<T>* newData=new Data<T>(val,maxLength); // Make new data value using given val
    int targetIndex = newData->key; // Get the index to look at
    int tempIndex = targetIndex; // Index we will increment

    for (int i = 0; i < maxLength; i++) {
        // Index we are looking at currently
        // Cycles around if we reach the end of a list
        tempIndex = (i + targetIndex) % maxLength;

        if (table[tempIndex] == nullptr) {
            Data<T>* delData = table[tempIndex];
            table[tempIndex] = newData;
            delete delData;
            length++;
            return;
        }
    }

    // Should never reach this point
    cout << "Something's wrong!" << endl;
    delete newData;
}

template <class T> T* HashTable<T>::removeItem(T* val) {
    if(length <= 0) { cout << "Table already empty!" << endl; return nullptr; }

    Data<T> compareVal(val, maxLength);
    int targetKey = compareVal.key;

    for(int i = 0; i < maxLength; i++) {
        int tempIndex = (i + targetKey) % maxLength;

        if (table[tempIndex] != nullptr && compareVal == *(table[tempIndex])) {
            T* returnVal = table[tempIndex]->data;

            delete table[tempIndex]; // Remove memory allocation of data item
            table[tempIndex] = nullptr;
            length--;

            return returnVal;
        }
    }

    cout << "Item not found!" << endl;
    return nullptr;
}

template <class T> T* HashTable<T>::getItem(T* val) {
    opCount = 0;
    if(length <= 0) { cout << "Table is empty!" << endl; return nullptr; }

    Data<T> compareVal(val, maxLength);
    int targetKey = compareVal.key;

    for(int i = 0; i < maxLength; i++) {
        int tempIndex = (i + targetKey) % maxLength;
        opCount++;

        if (table[tempIndex] != nullptr && compareVal == *(table[tempIndex])) {
            return table[tempIndex]->data;
        }
    }

    cout << "Item not found!" << endl;
}

// ----- Linked HashTable -----

#endif
