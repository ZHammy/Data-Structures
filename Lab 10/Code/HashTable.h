#ifndef HASHTABLE_H
#define HASHTABLE_H

// ----- Node -----
template <class T> class Data {
public:
    int key;
    T* data;
    // Constructors
    Data();
    Data(T*, int);
    bool operator < (Data&);
    bool operator > (Data&);
    bool operator == (Data&);
    bool operator >= (Data&);
    bool operator <= (Data&);
};

// ----- Linear probing HashTable -----
template <class T> class HashTable {
private:
    Data<T>** table;
    int maxLength;
    int length;
    int opCount;

public:
    // Constructor(s)
    HashTable();
    HashTable(int);
    // Destructor
    ~HashTable();

    // Basic functions
    virtual int getLength(); // Returns current HashTable size
    virtual int getOpCount(); // Returns last op count

    // Add / remove functions
    virtual void addItem(T*); // Add an item to the HashTable
    virtual T* removeItem(T*); // Remove an item from the HashTable
    virtual T* getItem(T*); // Get but dont remove an item from the HashTable

};

#endif
