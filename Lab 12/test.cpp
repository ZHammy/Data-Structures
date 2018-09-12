#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <memory.h>
//RAND AND TIME TRACKING INCLUDES
#include <chrono>
#include <ctime>
#include <stdlib.h>
#include <time.h>
//END RAND AND TIME INCLUDES
#include "bubble.h"
#include "counting.h"
#include "heap.h"
#include "insertion.h"
#include "merge.h"
#include "quick.h"
#include "radix.h"

using namespace std;
static int ARR_SIZE=100;
int main () {
    //This will store all the random values
    int MASTER_ARR[ARR_SIZE];
    //This will store the temp arrays
    int temp[ARR_SIZE];
    srand(time(NULL)); // Seed rand
    for(int i=0;i<ARR_SIZE;i++){
        MASTER_ARR[i]=rand() % (2*ARR_SIZE);
    }

    //heap

    for(int i=0;i<ARR_SIZE;i++){
        temp[i]=MASTER_ARR[i];
    }
    cout<<endl<<"UNSORTED"<<endl;
    for(int i=0;i<ARR_SIZE;i++){
        cout<<temp[i]<<endl;
    }
    auto start3 = chrono::high_resolution_clock::now();
    heapSort(temp,ARR_SIZE);
    auto end3 = chrono::high_resolution_clock::now();
    chrono::duration<double, nano> elapsedTime3 = end3 -start3;
    cout<<"Heap sort elapsed time for "<<ARR_SIZE<<" items:  "<<elapsedTime3.count()/1000000000.0<<" seconds"<<endl;


    cout<<endl<<"SORTED"<<endl;
    for(int i=0;i<ARR_SIZE;i++){
        cout<<temp[i]<<endl;
    }

}
