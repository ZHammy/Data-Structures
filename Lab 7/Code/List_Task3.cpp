#ifndef LIST_TASK3_CPP
#define LIST_TASK3_CPP

#include <iostream>
#include "List_Task3.h"

using namespace std;

List3::List3() {
    length = 0;
    maxLength = MAX_LENGTH;
    opCount = 0;
    for(int i=0;i<maxLength;i++){
        data[i]=nullptr;
    }
}

// Add to list functions
void List3::addItem(int val) {
    // Throw error if the list is already full
    if (maxLength == length) { throw *new ListOverflow; }

    // Reset operation count
    opCount = 0;
    // Create a pointer using the given value
    int *newVal = new int;
    *newVal = val;


    //if the list is empty
    if (length == 0) {
        opCount++;
        data[0] = newVal;
    }


    //if the list only has 1 item
    else if(length==1){
        opCount++;
        data[maxLength-1] = newVal;
    }


    //If an item is smaller than the first item
    else if(val<=*data[0]){
        int firstFree;//Find where the first free spot is and move every item to the right
        for (int i = 1; i < maxLength; i++) {
            if (data[i]==nullptr) {
                firstFree = i;
                break;
            }
        }
        // Shift the data up to keep sort
        for (int j = firstFree; j > 0; j--) {
            opCount++;
            data[j] = data[j-1];
        }
        //Insert the item at the beginning of the array
        opCount++;
        data[0] = newVal;
    }

    //if the item goes at the end
    else if(val>=*data[0]){
        int firstFree;//Find where the first free spot is and move every item to the left
        for (int i = maxLength-2; i >0; i++) {
            if (data[i]==nullptr) {
                firstFree = i;
                break;
            }
        }
        // Shift the data up to keep sort
        for (int j = firstFree; j < maxLength-1; j++) {
            opCount++;
            data[j] = data[j+1];
        }
        //Insert the item at the end of the array
        opCount++;
        data[maxLength-1] = newVal;
    }

    //Most items will be inserted here with this function
     else {
         //keep track of the higher and lower indexes for each item
         int upperBound;
         int lowerBound;
         //First find the first item greater
        for (int i = 1; i < maxLength-1; i++) {
            if(data[i]!=nullptr){
                opCount++;
                if (val <= *data[i]) {
                    upperBound = i;
                    break;
                }
            }
        }
        //now find the first item lower
        for (int i = upperBound-1; i >-1; i++) {
            if(data[i]!=nullptr){
                opCount++;
                if (val >= *data[i]) {
                    lowerBound = i;
                    break;
                }
            }
        }
        //At this point we have the 2 index which our value should fit in
        //need to move items if the spots are next to each other
        if((upperBound-1)==lowerBound){
            //Find the first free space
            int firstFree;
            for(int i=0;i<maxLength-1;i++){
                opCount++;
                if(data[i]==nullptr){
                    firstFree=i;
                    break;
                }
            }
            //shift the items to either side depending on where the first blank space is
            if(firstFree<lowerBound){
                for(int i=firstFree;i<lowerBound;i++){
                    opCount++;
                    data[i]=data[i+1];
                }
                opCount++;
                data[lowerBound]=newVal;

            }
            //if earliest free item is after the upper bound
            else{
                for(int i=firstFree;i>=upperBound;i--){
                    opCount++;
                    data[i]=data[i-1];
                }
                opCount++;
                data[upperBound]=newVal;
            }
        }
        //This is the general case for most items
        else{
            int index=lowerBound+upperBound;
            index/=2;
            opCount++;
            data[index]=newVal;
        }
    }
    length++;
}

// Remove from list functions
int List3::removeItem(int val) {
    // If there is nothing in the list, throw an error
    if (length == 0) { throw *new ListUnderflow; }

    // Reset operation count
    opCount = 0;
    // Create a pointer using the given value
    bool found = false; // If the value was found
    int index = length; // Index of the new value

    // Find the index of where it should be removed
    for (int i = 0; i < length; i++) {
        if(data[i]!=nullptr){
            opCount++;
            if (val == *data[i] && !found) {
                found = true;
                index = i;
                delete data[i];
                opCount++;
                if(i==maxLength-1){
                    data[i]=data[i-1];
                    delete data[i-1];
                }
                else if(i==0){
                    data[0]=data[1];
                    delete data[1];
                }
                break;
            }
        }

    }
    if (!found) { throw *new ListItemNotFound; }
    length--;
}


void List3::displayAll() {
    for (int i = 0; i < length; i++) {
        if(data[i]!=nullptr){
            cout << *data[i] << endl;
        }
    }
    cout << endl; // For readability
}
#endif
