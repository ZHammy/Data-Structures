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
#include "limits.h"
#include "Student.cpp"
#include "List.cpp"


using namespace std;
bool checkYesNo(string);      // Prompt for a yes or no answer
int checkInt(string,int,int); // Prompt for ints within a range of two numbers
double checkDouble(string,int,int); //prompt for double
string checkBirthDay(string); // Prompt for birth day using MM/DD/YY format
string getMNumber();    //A couple of the functions require mNumber so can reuse code

int main () {
    srand(time(NULL)); // Seed rand
    List <Student> classRoom;

    //20 Names with random Mnumbers that will be used
    classRoom.addItem(new Student("Jon","Jafari",getMNumber(),"11/11/88"));
    classRoom.addItem(new Student("Johnathan","Joestar",getMNumber(),"11/11/88"));
    classRoom.addItem(new Student("Joseph","Joestar",getMNumber(),"11/11/88"));
    classRoom.addItem(new Student("Jimmy","Neutron",getMNumber(),"11/11/88"));
    classRoom.addItem(new Student("Jolyne","Cujoh",getMNumber(),"11/11/88"));
    classRoom.addItem(new Student("Josuke","Higashikata",getMNumber(),"11/11/88"));
    classRoom.addItem(new Student("Jotaro","Kujo",getMNumber(),"11/11/88"));
    classRoom.addItem(new Student("James","Bond",getMNumber(),"11/11/88"));
    classRoom.addItem(new Student("John","Cena",getMNumber(),"11/11/88"));
    classRoom.addItem(new Student("Jack","Nicklaus",getMNumber(),"11/11/88"));
    classRoom.addItem(new Student("Jake","Paul",getMNumber(),"11/11/88"));
    classRoom.addItem(new Student("John","Kennedy",getMNumber(),"11/11/88"));
    classRoom.addItem(new Student("Jean","Polnareff",getMNumber(),"11/11/88"));
    classRoom.addItem(new Student("Jimi","Hendrix",getMNumber(),"11/11/88"));
    classRoom.addItem(new Student("Judy","Neutron",getMNumber(),"11/11/88"));
    classRoom.addItem(new Student("Jimmy","Buffett",getMNumber(),"11/11/88"));
    classRoom.addItem(new Student("Jack","Sparrow",getMNumber(),"11/11/88"));
    classRoom.addItem(new Student("James","Jones",getMNumber(),"11/11/88"));
    classRoom.addItem(new Student("James","Franco",getMNumber(),"11/11/88"));
    classRoom.addItem(new Student("Jeremy","Corbyn",getMNumber(),"11/11/88"));

    //Display all the member functions that the user can choose
    cout<<"Select an function"<<endl;
    cout<<"1:  Bubble Sort Ascending by First Name"<<endl;
    cout<<"2:  Bubble Sort Ascending by Last Name"<<endl;
    cout<<"3:  Bubble Sort Ascending by MNumber"<<endl;
    cout<<"4:  Bubble Sort Descending by First Name"<<endl;
    cout<<"5:  Bubble Sort Descending by Last Name"<<endl;
    cout<<"6:  Bubble Sort Descending by MNumber"<<endl;
    cout<<"7:  Insertion Sort Ascending by First Name"<<endl;
    cout<<"8:  Insertion Sort Ascending by Last Name"<<endl;
    cout<<"9:  Insertion Sort Ascending by MNumber"<<endl;
    cout<<"10: Insertion Sort Descending by First Name"<<endl;
    cout<<"11: Insertion Sort Descending by Last Name"<<endl;
    cout<<"12: Insertion Sort Descending by MNumber"<<endl;
    cout<<"13: Heap Sort Ascending by First Name"<<endl;
    cout<<"14: Heap Sort Ascending by Last Name"<<endl;
    cout<<"15: Heap Sort Ascending by MNumber"<<endl;
    cout<<"16: Heap Sort Descending by First Name"<<endl;
    cout<<"17: Heap Sort Descending by Last Name"<<endl;
    cout<<"18: Heap Sort Descending by MNumber"<<endl;
    int menu=checkInt("Enter your selection:  ",1,18);

    //Using a switch, do the appropriate operations from the menu
    try{
        switch (menu){
            case 1:
                {
                    classRoom.bubSortFNameA();
                }
                break;
            case 2:
                {
                    classRoom.bubSortLNameA();
                }
                break;
            case 3:
                {
                    classRoom.bubSortMNumA();
                }
                break;
            case 4:
                {
                    classRoom.bubSortFNameD();
                }
                break;
            case 5:
                {
                    classRoom.bubSortLNameD();
                }
                break;
            case 6:
                {
                    classRoom.bubSortMNumD();
                }
                break;
            case 7:
                {
                    classRoom.insSortFNameA();
                }
                break;
            case 8:
                {
                    classRoom.insSortLNameA();
                }
                break;
            case 9:
                {
                    classRoom.insSortMNumA();
                }
                break;
            case 10:
                {
                    classRoom.insSortFNameD();
                }
                break;
            case 11:
                {
                    classRoom.insSortLNameD();
                }
                break;
            case 12:
                {
                    classRoom.insSortMNumD();
                }
                break;
            case 13:
                {
                    classRoom.heapSortFNameA();
                }
                break;
            case 14:
                {
                    classRoom.heapSortLNameA();
                }
                break;
            case 15:
                {
                    classRoom.heapSortMNumA();
                }
                break;
            case 16:
                {
                    classRoom.heapSortFNameD();
                }
                break;
            case 17:
                {
                    classRoom.heapSortLNameD();
                }
                break;
            case 18:
                {
                    classRoom.heapSortMNumD();
                }
                break;
        }
    }
    catch(...){
        cout<<"ERROR, unallowed operation"<<endl<<endl;
    }

    classRoom.displayAll();

    return 0;
}

// Returns true if yes, false if no
bool checkYesNo(string text){
    string val;
    bool returnVal = false;
    bool badVal = true;
    while(badVal){
        cout << text;
        cin >> val;

        if(val == "y" || val == "Y" || val == "n" || val == "N"){
            badVal = false;
            returnVal = val == "y" || val == "Y"; // Return true if answered y
        }
        else {
            cout << "Invalid entry, please enter again" << endl;
        }

        cout << endl; // Print blank line for readability
    }
    return returnVal;
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

double checkDouble(string text, int min, int max){
    double val;
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

// Simply assure date format
// Does not validate the date itself
string checkBirthDay(string text) {
    string birthDay;
    bool badVal = true;
    const int DATE_LENGTH = 8;

    while (badVal) {
        cout << text;
        cin >> birthDay;

        // Error early if the input date is not the right length
        if (birthDay.length() != DATE_LENGTH) {
            cout << "Invalid date length" << endl << endl;
            continue;
        }

        // Check all the slash locations
        if (birthDay[2] != '/' || birthDay[5] != '/') {
            cout << "Improper format, check slashes." << endl << endl;
            continue;
        }

        // Ensure values between slashes are numbers
        try {
            // This will error with invalid_argument if they
            // cannot be converted into numbers
            int month = stoi(birthDay.substr(0,2));
            int day = stoi(birthDay.substr(3,2));
            int year = stoi(birthDay.substr(6,2));

            badVal = false; // Exit if all vals can convert properly

        } catch (invalid_argument) {
            cout << "Invalid date. Try again." << endl << endl;
        } catch(...) {
            cout << "Unknown error." << endl << endl;
        }

    }

    cout << endl; // For legibility
    return birthDay;
}

string getMNumber(){
    const int NUM_LENGTH = 8;

    // Generate random, 8 digit MNumber
    int num=(rand()*rand())%99999999;
    string numString = to_string(num);

    // Add necessary amount of 0's so length is consistent
    if (numString.length() < NUM_LENGTH) {
        int diff = NUM_LENGTH - numString.length();
        for (int i = 0; i < diff; i++) { numString.insert(0, "0"); }
    }

    return "M"+numString;
}
