#include <iostream>
#include <string>
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
    List <Student> classRoom;
    do{
        //Display all the member functions that the user can choose
        cout<<"Select an function"<<endl;
        cout<<"1: Add a new student to the list"<<endl;
        cout<<"2: Get a student from the list"<<endl;
        cout<<"3: Check if the student is in the list"<<endl;
        cout<<"4: Check if the list is empty"<<endl;
        cout<<"5: Check how many students are in the list"<<endl;
        cout<<"6: See the student at a selected location in the list"<<endl;
        cout<<"7: See the next student in the list"<<endl;
        cout<<"8: Reset the next counter for the list"<<endl;
        int menu=checkInt("Enter your selection:  ",1,8);

        //Using a switch, do the appropriate operations from the menu
        try{
            switch (menu){
                case 1:
                    {
                        string first, last, mNum, birthDay;
                        cout<<"Enter the student's first name:  ";
                        cin >>first; cout << endl;

                        cout<<"Enter the student's last name:  ";
                        cin >>last; cout<<endl;

                        mNum=getMNumber();

                        birthDay=checkBirthDay("Enter the student's birthday (MM/DD/YY):  ");

                        // Prompt for GPA
                        // If none provided, use default GPA from constructor
                        if(checkYesNo("Provide a gpa? (y/n) ")){
                            double gpa=checkDouble("Enter the student's GPA:  ",0,4);
                            classRoom.addItem(new Student(first,last,mNum,birthDay,gpa));
                        }
                        else{
                            // Defaults GPA to 0.0
                            classRoom.addItem(new Student(first,last,mNum,birthDay));
                        }
                    }
                    break;
                case 2:
                    {
                        Student *temp=classRoom.getItem(new Student("","",getMNumber(),""));
                        cout<<"Removed student: "<<temp->getName()<<endl;
                        delete temp;
                    }
                    break;
                case 3:
                    {
                        if(classRoom.isInList(new Student("","",getMNumber(),""))){
                            cout<<"The student is in the list"<<endl;
                        }
                        else{
                            cout<<"The student is not in the list"<<endl;
                        }
                    }
                    break;
                case 4:
                    {
                        if(classRoom.isEmpty()){
                                cout<<"The list is empty"<<endl;
                        }
                        else{
                            cout<<"The list is not empty"<<endl;
                        }
                    }
                    break;
                case 5:
                    {
                        cout<<"There are "<<classRoom.size()<<" students in the list"<<endl;
                    }
                    break;
                case 6:
                    {
                        if(classRoom.size()){
                            Student temp=classRoom.seeAt(checkInt("What location in the list do you want to get?  ",0,classRoom.size()))->data;
                            cout<<temp.getName()<<endl;
                        }
                        else{
                            cout<<"Can't do that, there aren't any students in the list"<<endl;
                        }
                    }
                    break;
                case 7:
                    {
                        Node <Student> *temp=classRoom.seeNext();
                        if(temp!=nullptr){
                            cout<<temp->data.getName()<<endl;
                        }
                        else{
                            cout<<"End of list reached, can't see next"<<endl;
                        }

                    }
                    break;
                case 8:
                    {
                        classRoom.reset();
                    }
                    break;

                default:
                    break;
            }
        }
        // catch(List::classRoomListUnderflow){
        //     cout<<"LIST UNDERFLOW ERROR"<<endl<<endl;
        // }
        // catch(List::ListItemNotFound){
        //     cout<<"ITEM NOT FOUND ERROR"<<endl<<endl;
        // }
        // catch(List::ListEnd){
        //     cout<<"END OF LIST ERROR"<<endl<<endl;
        // }
        catch(...){
            cout<<"ERROR, unallowed operation"<<endl<<endl;
        }

    }
    while(checkYesNo("Would you like to continue?  (y/n):  "));

    return 0;
}

// Returns true if yes, false if no
bool checkYesNo(string text){
    string val;
    bool cashOut = false;
    bool badVal = true;
    while(badVal){
        cout << text;
        cin >> val;

        if(val == "y" || val == "Y" || val == "n" || val == "N"){
            badVal = false;
            cashOut = val == "y" || val == "Y"; // Return true if answered y
        }
        else {
            cout << "Invalid entry, please enter again" << endl;
        }

        cout << endl; // Print blank line for readability
    }
    return cashOut;
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

    // Prompt for M number
    // Prevents inputs highter than 8 digits long
    int num=checkInt("Enter the student's M Number:  M",0,99999999);
    string numString = to_string(num);

    // Add necessary amount of 0's so length is consistent
    if (numString.length() < NUM_LENGTH) {
        int diff = NUM_LENGTH - numString.length();
        for (int i = 0; i < diff; i++) { numString.insert(0, "0"); }
    }

    return "M"+numString;
}
