#ifndef TREE_CPP
#define TREE_CPP

#include <iostream>
#include <cmath>
#include "Tree.h"

using namespace std;

// ---- NODE ----
template <class T> Node<T>::Node() {
    // Do not initialize data
    left = nullptr;
    right = nullptr;
}
template <class T> Node<T>::Node(T inVal) {
    data = inVal;
    left = nullptr;
    right = nullptr;
}

// ---- TREE ----
// Constructor
template <class T> Tree<T>::Tree() {
    root = nullptr;
    elemNum = 0;
}

// Destructor
template <class T> Tree<T>::~Tree() {
    emptyTree();
}

// Error classes

// Modify tree functions
template <class T> void Tree<T>::insert(T val) {
    // Recursively insert this val
    _insert(val, root);
    // Rebalance tree after insertion
    rebalanceTree();
}
template <class T> void Tree<T>::_insert(T val, Node<T>*& temp) {
    // Base case
    if (temp == nullptr) {
        temp = new Node<T>(val);
        elemNum++;
        return;
    }

    if (val < temp->data) {
        _insert(val, temp->left);
    } else if (val > temp->data) {
        _insert(val, temp->right);
    } else {
        // inc data if already exists
        ++temp->data;
    }
}

template <class T> T* Tree<T>::remove(T val) { _remove(val, root); }
template <class T> T* Tree<T>::_remove(T val, Node<T>*& temp) {
    //If the val doesn't exist in the tree, dont do anything
    if(find(val)==nullptr||temp==nullptr){
        return nullptr;
    }
    T* retVal=new T();
    if (val < temp->data) {
        _remove(val, temp->left);
    } else if (val > temp->data) {
        _remove(val, temp->right);
        //When the value is found, have to reorder the tree a bit
    } else {
        //If the node has no children
        if(temp->left==nullptr&&temp->right==nullptr){
            *retVal=temp->data;
            delete temp;
        }
        //If the node has a left child
        else if(temp->left==nullptr){
            Node<T>* temp2=temp;
            temp=temp->right;
            *retVal=temp2->data;
            delete temp2;
        }
        //if the node has a right child
        else if(temp->right==nullptr){
            Node<T>* temp2=temp;
            temp=temp->left;
            *retVal=temp2->data;
            delete temp2;
        }
        //if the node has 2 children
        else{
            Node<T>* temp2=temp;
            //Make temp = to the smallest val on the right side
            temp=findMin(temp->right);
            //Next remove the new val sitting at temps location
            _remove(temp->data,temp->right);
            *retVal=temp2->data;
            delete temp2;
        }
        rebalanceNode(temp);
        return temp;
    }

}
template <class T> Node<T>* Tree<T>::findMin(Node<T>* curNode) {
    Node<T>* temp=curNode;
    while(temp->left!=nullptr){
        temp=temp->left;
    }
    return temp;
}

template <class T> void Tree<T>::_emptyTree(Node<T>* curNode) {
    if(curNode->left!=nullptr){
        _emptyTree(curNode->left);
    }
    if(curNode->right!=nullptr){
        _emptyTree(curNode->right);
    }
    delete curNode;
}

template <class T> void Tree<T>::emptyTree() {
    _emptyTree(root);
}

template <class T> Node<T>* Tree<T>::rotateLeft(Node<T>* parent) {
    Node<T>* temp = parent;
    parent = parent->right;
    temp->right = parent->left;
    parent->left = temp;
    return parent;
}

template <class T> Node<T>* Tree<T>::rotateRight(Node<T>* parent) {
    Node<T>* temp = parent;
    parent = parent->left;
    temp->left = parent->right;
    parent->right = temp;
    return parent;
}

template <class T> void Tree<T>::rebalanceTree() {
    rebalanceNode(root); // Simply rebalance from the root node
}
template <class T> void Tree<T>::rebalanceNode(Node<T>*& temp) {
    if (temp == nullptr) { return; } // Base case

    int leftHeight = getHeight(temp->left);
    int rightHeight = getHeight(temp->right);
    int heightDiff = 2; // Height difference standard

    // Recursively cycle through until we reach leaves
    // in order to rebalance from bottom
    rebalanceNode(temp->left);
    rebalanceNode(temp->right);

    // Rotate the values if there is sizeable height difference
    if (leftHeight - rightHeight >= heightDiff) {
        temp = rotateRight(temp);
    } else if (rightHeight - leftHeight >= heightDiff) {
        temp = rotateLeft(temp);
    }
}

template <class T> Node<T>* Tree<T>::find(T val) { return _find(val, root); }
// Get tree value functions
template <class T> Node<T>* Tree<T>::_find(T val, Node<T>* temp) {
    // Base case (if not found)
    if (temp == nullptr) { return nullptr; }

    if (val < temp->data) {
        return _find(val, temp->left);
    } else if (val > temp->data) {
        return _find(val, temp->right);
    } else {
        // If match is found
        return temp;
    }
}

template <class T> int Tree<T>::size() { return elemNum; }


template <class T> void Tree<T>::_getAllAscending(T* myArray,int *index, Node<T>* curNode) {
    if (curNode==nullptr){
        return;
    }
    _getAllAscending(myArray,index,curNode->left);
    *(myArray+*index)=curNode->data;
    *index=*index+1;

    _getAllAscending(myArray,index,curNode->right);


}

template <class T> void Tree<T>::_getAllDescending(T* myArray,int* index,Node<T>* curNode) {
    if (curNode==nullptr){
        return;
    }
    _getAllDescending(myArray,index,curNode->right);
    *(myArray+*index)=curNode->data;
    *index=*index+1;
    _getAllDescending(myArray,index,curNode->left);
}

template <class T> T* Tree<T>::getAllAscending() {
    if(root==nullptr){
        return nullptr;
    }
    T* pointerToArray=new T[elemNum];
    int *index=new int(0);
    _getAllAscending(pointerToArray,index,root);
    delete index;
    return pointerToArray;
}

template <class T> T* Tree<T>::getAllDescending() {
    if(root==nullptr){
        return nullptr;
    }
    T* pointerToArray=new T[elemNum];
    int *index=new int(0);
    _getAllDescending(pointerToArray,index,root);
    delete index;
    return pointerToArray;
}

template <class T> int Tree<T>::getHeight(Node<T>* temp) {
    if (temp == nullptr) { return 0; } // Base case
    int leftHeight, rightHeight;

    // Recursively cycle through to count values
    // Includes this node in the count
    leftHeight = 1 + getHeight(temp->left);
    rightHeight = 1 + getHeight(temp->right);

    return max(leftHeight, rightHeight);
}

// Dev
template <class T> void Tree<T>::print() {
    _print(root, 0);
    cout << endl;
}
template <class T> void Tree<T>::_print(Node<T>*& temp, int spaces) {
    if (elemNum == 0) {
        cout << "No items in tree" << endl;
        return;
    }
    if (temp == nullptr) { return; }

    _print(temp->left, spaces+2);
    for (int i = 0; i < spaces; i++) { cout << " "; }
    cout << temp->data << " " << endl;
    _print(temp->right, spaces+2);
}

#endif
