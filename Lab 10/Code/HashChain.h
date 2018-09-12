#ifndef HASHCHAIN_H
#define HASHCHAIN_H
#include "HashTable.cpp"
#include "List.cpp"

// ----- Linked Hash chain -----
template <class T> class HashChain: public HashTable<T> {
private:
    List<T>** table;
    int maxLength;
    int length;
    int opCount;

public:
    // Constructor(s)
    HashChain();
    HashChain(int);
    // Destructor
    ~HashChain();

    // Basic functions
    int getLength();
    int getOpCount();

    // Add / remove functions
    void addItem(T*); // Add an item to the HashChain
    T* removeItem(T*); // Remove an item from the HashChain
    T* getItem(T*); // Get but dont remove an item from the HashChain
};

#endif
