#ifndef TREE_H
#define TREE_H

#include <string>
using namespace std;

template <class T> class Node {
public:
    // Data
    T data;
    Node *left;
    Node *right;

    // Constructors
    Node();  // Default
    Node(T); // Initialize data
};

template <class T> class Tree {
private:
    Node<T> *root; // Root of tree
    int elemNum;   // Number of elements in the tree

public:
    // Constructor, Destructor
    Tree();
    ~Tree();

    // Error classes
    class TreeItemExistsExeption {
        string msg = "Tree item already exists";
    };

    // Modify tree functions
    void insert(T);    // Insert val and rebalance tree
    void _insert(T, Node<T>*&); // For recursion

    T* remove(T);  // Remove and rebalance tree
    T* _remove(T, Node<T>*&); // For recursion
    Node<T>* findMin(Node<T>*); //Needed for remove with 2 children

    void emptyTree(); // Empty all values
    void _emptyTree(Node<T>*); // Empty all values

    Node<T>* rotateLeft(Node<T>*);  // Rotate tree values left for rebalancing
    Node<T>* rotateRight(Node<T>*); // Rotate tree values right for rebalancing
    void rebalanceTree();           // Rebalance a tree
    void rebalanceNode(Node<T>*&);  // Rebalance from node; primarily for recursion

    // Get tree value functions
    Node<T>* find(T); // Return val if found, nullptr if not
    Node<T>* _find(T, Node<T>*); // For recursion

    int size();  // Return number of elements in tree
    void _getAllAscending(T* myArray,int *index, Node<T>* curNode);  // Returns nodes recursively from least to greatest
    void _getAllDescending(T* myArray,int* index, Node<T>* curNode); // Returns nodes recursively from greatest to least
    T* getAllAscending();  // Return array of values ascending
    T* getAllDescending(); // Return array of values descending
    int getHeight(Node<T>*); // Return height of node (highest of children)

    // Dev
    void print();
    void _print(Node<T>*&, int); // For recursion
};

#endif
