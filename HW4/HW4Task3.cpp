#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include <stdlib.h>
#include <time.h>
#include "PriorityQueue.cpp"
#include "PriorityHeap.cpp"

using namespace std;

// Array sizes we will cycle through to test
static const int ARR_SIZES[4] = {500,1000,2000,5000};
static const int ARR_LEN = 4;

int main () {
    //clocks
    auto queueStart = chrono::high_resolution_clock::now();
    auto queueEnd = chrono::high_resolution_clock::now();
    auto heapStart = chrono::high_resolution_clock::now();
    auto heapEnd = chrono::high_resolution_clock::now();


    for (int i = 0; i < ARR_LEN; i++) {

        // This array size
        const int ARR_SIZE = ARR_SIZES[i];
        PriorityHeap<int> myHeap(ARR_SIZE);
        PriorityQueue<int> myQueue;
        // This will store all the random values
        int data[ARR_SIZE];
        int priorities[ARR_SIZE];

        srand(time(NULL)); // Seed rand
        // Populate priorities and data arrays
        for(int i=0;i<ARR_SIZE;i++){
            data[i]=rand() % (2*ARR_SIZE);
            priorities[i]=rand() % (2*ARR_SIZE);
        }



        // Done in this way for ease of adding/removing techniques,
        cout << "Insert and remove tests for array size: " << ARR_SIZE << endl;

        //Monitor time of Inserts
        heapStart = chrono::high_resolution_clock::now();
        for(int i=0;i<ARR_SIZE;i++){
            myHeap.Insert(data[i],priorities[i]);
        }
        heapEnd = chrono::high_resolution_clock::now();
        chrono::duration<double, nano> HIelapsedTime = heapEnd - heapStart;


        queueStart = chrono::high_resolution_clock::now();
        for(int i=0;i<ARR_SIZE;i++){
            myQueue.Insert(data[i],priorities[i]);
        }
        queueEnd = chrono::high_resolution_clock::now();
        chrono::duration<double, nano> QIelapsedTime = queueEnd - queueStart;

        cout <<"Queue Insert time: " << QIelapsedTime.count()/1000000000.0 << " seconds" << endl;
        cout <<"Heap Insert time: " << HIelapsedTime.count()/1000000000.0 << " seconds" << endl;



        //Now remove every item for both queue and heap
        heapStart = chrono::high_resolution_clock::now();
        for(int i=0;i<ARR_SIZE;i++){
            myHeap.Remove();
        }
        heapEnd = chrono::high_resolution_clock::now();
        chrono::duration<double, nano> HRelapsedTime = heapEnd - heapStart;


        queueStart = chrono::high_resolution_clock::now();
        for(int i=0;i<ARR_SIZE;i++){
            myQueue.Remove();
        }
        queueEnd = chrono::high_resolution_clock::now();
        chrono::duration<double, nano> QRelapsedTime = queueEnd - queueStart;
        cout <<"Queue Remove time: " << QRelapsedTime.count()/1000000000.0 << " seconds" << endl;
        cout <<"Heap Remove time: " << HRelapsedTime.count()/1000000000.0 << " seconds" << endl;
        cout<<endl;//for readability
    }



    return 0;
}
