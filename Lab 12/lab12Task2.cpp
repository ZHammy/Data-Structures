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

// Array sizes we will cycle through to test
static const int ARR_SIZES[6] = {10, 100, 500, 5000, 25000, 50000};
static const int ARR_LEN = 6;

void copyArray(int[], int[], int); // Copy the contents the first array into the second

int main () {
    // Temp variables for each array size test
    int currSort = 0; // Current sort index
    auto start = chrono::high_resolution_clock::now(); // Start time monitor
    auto end = chrono::high_resolution_clock::now();   // End time monitor
    bool stopLoop = false; // Stop flag for sort loop
    string text; // Text variable for output


    for (int i = 0; i < ARR_LEN; i++) {
        // Reset temp variables
        currSort = 0;
        stopLoop = false;

        // This array size
        const int ARR_SIZE = ARR_SIZES[i];

        // This will store all the random values
        int MASTER_ARR[ARR_SIZE];

        srand(time(NULL)); // Seed rand
        // Populate master array with random values
        for(int i=0;i<ARR_SIZE;i++){
            MASTER_ARR[i]=rand() % (2*ARR_SIZE);
        }

        // Temp array to be used by functions
        int temp[ARR_SIZE];

        // Loop through all sorting techniques and display time
        // Done in this way for ease of adding/removing techniques,
        cout << "Tests for array size: " << ARR_SIZE << endl;
        while (!stopLoop) {
            copyArray(MASTER_ARR, temp, ARR_SIZE); // Reset temp contents

            // Sort depending on current mode and monitor time
            // Switch case time considered negligible
            start = chrono::high_resolution_clock::now();
            switch (currSort) {
                // Bubble
                case 0:
                    text="Bubble";
                    bubbleSort(temp,ARR_SIZE);
                    break;
                // Insertion
                case 1:
                    text="Insertion";
                    insertionSort(temp,ARR_SIZE);
                    break;
                // Merge
                case 2:
                    text="Merge";
                    mergeSort(temp,0,ARR_SIZE-1);
                    break;
                // Quick
                case 3:
                    text="Quick";
                    quickSort(temp,0,ARR_SIZE-1);
                    break;
                // Heap
                case 4:
                    text="Heap";
                    heapSort(temp,ARR_SIZE);
                    break;
                // Counting
                case 5:
                    text="Counting";
                    countingSort(temp,ARR_SIZE);
                    break;
                // Radix
                case 6:
                    text="Radix";
                    radixSort(temp,ARR_SIZE);
                    break;
                default:
                    stopLoop = true; // End the loop once we get past all sort types
            }
            end = chrono::high_resolution_clock::now();

            if (!stopLoop) {
                // Output elapsed time
                chrono::duration<double, nano> elapsedTime = end - start;
                cout << text << " sort time: " << elapsedTime.count()/1000000000.0 << " seconds" << endl;

                // Increment current sort
                currSort++;
            }
        }

        cout << endl; // For readability
    }

    return 0;
}

void copyArray(int base[], int copy[], int size) {
    for (int i = 0; i < size; i++) {
        copy[i] = base[i];
    }
};
