#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <class T> class Queue {
    private:
        vector <T> dataArray;
    public:
        // Error classes
        class QueueUnderflow;
        //Constructors
        Queue();
        
        int length();//returns the length of dataArray
        void enqueue(T);//Adds item to Queue
        T dequeue();//removes and returns an item from the Queue
        void makeEmpty();//empties the queue
        bool isEmpty();
        bool isFull();
};

#endif
