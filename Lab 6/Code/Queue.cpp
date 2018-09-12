#ifndef QUEUE_CPP
#define QUEUE_CPP

#include "Queue.h"
using namespace std;

//Constructors
template <class T> Queue<T>::Queue(){
    vector<T> dataArray;
}

// Error classes
template <class T> class Queue<T>::QueueUnderflow{};

//member functions
template <class T> int Queue<T>::length(){
    return dataArray.size();
}

template <class T> void Queue<T>::enqueue(T newData){
    dataArray.push_back(newData);
}

template <class T> T Queue<T>::dequeue(){
    if(dataArray.size()>0){
        T retData=dataArray.front();
        dataArray.erase(dataArray.begin());
        return retData;
    }
    else{
        QueueUnderflow error;
        throw error;
    }
}

template <class T> void Queue<T>::makeEmpty(){
    dataArray.clear();
}

template <class T> bool Queue<T>::isFull(){
    return false; //The queue should never fill up, but this function is needed
}

template <class T> bool Queue<T>::isEmpty(){
    if(dataArray.size()>0){
        return false;
    }
    return true;
}

#endif
