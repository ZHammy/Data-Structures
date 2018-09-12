#include <iostream>
#include <string>
#include "limits.h"
#include "PriorityHeap.cpp"

using namespace std;

int checkInt(string, int = -INT_MAX, int = INT_MAX); // Prompt for ints within a range of two numbers

int main () {
    int choice;
    PriorityHeap<int> myHeap(1000);
    while (true) {
        // Menu output / input
        cout << "What would you like to do to your Heap?" << endl
             << "1: Insert an Item" << endl
             << "2: Remove the highest priority item" << endl
             << "3: Print the Heap" << endl
             << "4: Quit" << endl;
        choice = checkInt("Enter your selection:  ",1,4);

        // Check first if program will be exites
        if (choice == 4) { break; }
        try {
            // Remaining menu options
            switch (choice) {
                // Add node
                case 1:
                    {
                        int inVal, priority;
                        inVal = checkInt("What value would you like to insert?  ");
                        priority = checkInt("What's the priority of this item?  ");
                        myHeap.Insert(inVal,priority);
                    }
                    break;
                // Add edge
                case 2:
                    {
                        int displayData=myHeap.Remove().data;
                        if(displayData!=-9999){
                            cout<<"Removed item:  "<< displayData <<" from the Heap"<<endl;
                        }

                    }
                    break;
                // Remove edge
                case 3:
                    {
                        myHeap.PrintHeap();
                    }
                    break;
                default:
                    // Should never be reached
                    cout << "Huh, that's odd" << endl;
            }
        }
        catch(...){
            cout << "ERROR: Unallowed Operation" << endl;
        }
        cout << endl; // For readability
    }
    return 0;
}

//Makes sure an entered int is within a range
int checkInt(string text, int min, int max){
    int val;
    bool badVal = true;
    while(badVal){
        cout << text;
        cin >> val;
        badVal = cin.fail();
        if(badVal||(val>max)||val<min){
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Invalid entry, please enter again" <<endl;
            badVal=true;
        }
        cout << endl; // Print blank line for readability
    }
    return val;
}
