#ifndef STUDENT_CPP
#define STUDENT_CPP
#include "Student.h"
#include <string>
#include <iostream>
#include <time.h>
#include <ctime>
using namespace std;

//A default constructor is needed for the linked list to work
Student::Student(){
    FirstName="";
    LastName="";
    MNumber="";
    Birthday="";
    GPA=0.0;
}

Student::Student(string first ,string last ,string num,string birth, double grades = 0.0){
    FirstName=first;
    LastName=last;
    MNumber=num;
    Birthday=birth;
    GPA=grades;
}

string Student::getName(){
    return (FirstName+" "+LastName);
}

string Student::getMNumber(){
    return MNumber;
}

double Student::getGPA(){
    return GPA;
}

int Student::getAge(){
    //parse the birthday string into ints
    int month=atoi((Birthday.substr(0,2)).c_str());
    int day=atoi((Birthday.substr(3,2)).c_str());
    int year=atoi((Birthday.substr(6,2)).c_str());
    //Do some timezone setup
    time_t temp;
    struct tm * birthTime;
    time ( &temp );
    birthTime = localtime ( &temp );
    //set the values for the birthTime
    birthTime->tm_year   = year;
    birthTime->tm_mon    = month-1;
    birthTime->tm_mday   = day;

    //convert to unix time
    int secondsSinceBirth = mktime ( birthTime );
    //now get the current time and find the difference
    time_t curTime;
    time(&curTime);
    int seconds = difftime(curTime,secondsSinceBirth);
    //seconds now contains the seconds since the person's birth
    return seconds/31557600;//seconds in a year is 31557600
}

void Student::displayData(){
    /* NOTE: Final reference image:
                    omMMMd+       _____________________
                   sMMMMMMM+     | M-Number: M12345678 |
                   hMMMMMMMs     | Age: 20             |
                   .hMMMMMy`   // ---------------------
                 :dNNmh+-`   -
                -NMMMMMMms-
        .m.    `NMMMMMmMMMMNs:        \\
        sM:   `dMMMMMh `+hNMMMNmmmmmmmm\\
       omM:   hMMMMMm`    `:shdddddddddd\\   GPA: 4.0
       dyM/  oMMMMMM-    `my============================|
       h/M- /MMMMMM+     `M/ Name: John Doe             |
       h - .NMMMMMy      `Nh============================|
       h  `mMMMMMm-........`                +MMM/
       h  yMMMMMMMMMMMMMMMMMmo`             +MMM/
       h  /dNMMMMMMMMMMMMMMMMMm.            +MMM/
       ymddddddddddddddddh`mMMMd            +MMM/
         -y+.`````````-oy- -MMMMo           +MMM/
         N/             :N  oMMMM-          +MMM/
        `M-             .M   dMMMm`         +MMM/
        -M`             `M.  .NMMMy         +MMM/
        /N               N-   /MMMM/        +MMM/
        +m               d/    yMMMN.       +MMM/
        sh               yo    `ys+-`      .yMMMy.
        yo               +s -mmmmdddddddmmNMMMMMMMNmmddd:

        Original reference generated from image to ascii generator found at:
        https://www.text-image.com/convert/pic2ascii.cgi

        Original image in project directory

        Code works top down to output all necessary values
    */

    // ------ SPEECH BUBBLE ------

    // Top of head and M-Number
    // Assumes given M-Number is always of 9 length
    cout << "             omMMMd+       _____________________" << endl;
    cout << "            sMMMMMMM+     | M-Number: " << MNumber << " |" << endl;

    // Age output
    // 15 total spaces to use after "Age: "
    const int AGE_LENGTH = to_string(getAge()).length();
    int ageSpaces = 15 - AGE_LENGTH;

    cout << "            hMMMMMMMs     | Age: " << getAge(); // Head and speech bubble
    // Output remaining spaces necessary
    for (int i = 0; i < ageSpaces; i++) { cout << " "; }
    cout << "|" << endl; // End of speech bubble

    // Output body and GPA; stops at desk
    cout << "            .hMMMMMy`   // ---------------------  " << endl;
    cout << "          :dNNmh+-`   -                           " << endl;
    cout << "         -NMMMMMMms-                              " << endl;
    cout << " .m.    `NMMMMMmMMMMNs:        \\\\                 " << endl;
    cout << " sM:   `dMMMMMh `+hNMMMNmmmmmmmm\\\\                " << endl;
    cout << "omM:   hMMMMMm`    `:shdddddddddd\\\\   GPA: " << GPA << endl;

    // ------- DESK PROCESSING -------
    // Desk is 28 characters long by default
    const int DESK_LENGTH = 28;
    // String to be displayed in the desk
    string displayString = " Name: " + getName() + " ";
    const int DISPLAY_LENGTH = displayString.length();

    int diff = DESK_LENGTH - DISPLAY_LENGTH;

    // NOTE: for rest of processing, if diff < 0,
    // we need to make more room for the name

    // ------- TOP OF DESK -------

    // Start of desk
    cout << "dyM/  oMMMMMM-    `my============================";

    if (diff < 0) {
        // Add as many chars as necessary to fit the name
        for (int i = diff; i < 0; i++) { cout << '='; }
    }

    cout << '|' << endl; // End of desk

    // ------- MIDDLE OF DESK -------

    // Start of desk
    cout << "h/M- /MMMMMM+     `M/";

    // Output name
    cout << displayString;
    // Output additional spaces to fit default desk size if need be
    if (diff > 0) {
        for (int i = 0; i < diff; i++) { cout << " "; }
    }

    cout << "|" << endl; // End of desk

    // ------- BOTTOM OF DESK -------

    // Start of desk
    cout << "h - .NMMMMMy      `Nh============================";

    // Add as many chars as necessary to fit the name
    if (diff < 0) {
        for (int i = diff; i < 0; i++) { cout << '='; }
    }

    cout << '|' << endl; // End of desk

    // ------ REMAINING ASCII ART -------
    cout << "h  `mMMMMMm-........`                +MMM/        " << endl;
    cout << "h  yMMMMMMMMMMMMMMMMMmo`             +MMM/        " << endl;
    cout << "h  /dNMMMMMMMMMMMMMMMMMm.            +MMM/        " << endl;
    cout << "ymddddddddddddddddh`mMMMd            +MMM/        " << endl;
    cout << "  -y+.`````````-oy- -MMMMo           +MMM/        " << endl;
    cout << "  N/             :N  oMMMM-          +MMM/        " << endl;
    cout << " `M-             .M   dMMMm`         +MMM/        " << endl;
    cout << " -M`             `M.  .NMMMy         +MMM/        " << endl;
    cout << " /N               N-   /MMMM/        +MMM/        " << endl;
    cout << " +m               d/    yMMMN.       +MMM/        " << endl;
    cout << " sh               yo    `ys+-`      .yMMMy.       " << endl;
    cout << " yo               +s -mmmmdddddddmmNMMMMMMMNmmddd:" << endl;
}

// Operator overloads
bool Student::operator > (Student &Student2) {
    //get both mNumbers and remove the M
    string m1=MNumber;
    string m2=Student2.getMNumber();
    m1.erase(0,1);
    m2.erase(0,1);

    // Convert strings to numbers and compare
    int mNum1=atoi(m1.c_str());
    int mNum2=atoi(m2.c_str());

    return mNum1 > mNum2;
}

bool Student::operator < (Student &Student2) {
    //get both mNumbers and remove the M
    string m1=MNumber;
    string m2=Student2.getMNumber();
    m1.erase(0,1);
    m2.erase(0,1);

    // Convert strings to numbers and compare
    int mNum1=atoi(m1.c_str());
    int mNum2=atoi(m2.c_str());

    return mNum1 < mNum2;
}

bool Student::operator == (Student &Student2) {
    //get both mNumbers and remove the M
    string m1=MNumber;
    string m2=Student2.getMNumber();
    m1.erase(0,1);
    m2.erase(0,1);

    // Convert strings to numbers and compare
    int mNum1=atoi(m1.c_str());
    int mNum2=atoi(m2.c_str());

    return mNum1 == mNum2;
}

bool Student::operator <= (Student &Student2) {
    //get both mNumbers and remove the M
    string m1=MNumber;
    string m2=Student2.getMNumber();
    m1.erase(0,1);
    m2.erase(0,1);

    // Convert strings to numbers and compare
    int mNum1=atoi(m1.c_str());
    int mNum2=atoi(m2.c_str());

    return mNum1 <= mNum2;
}

bool Student::operator >= (Student &Student2) {
    //get both mNumbers and remove the M
    string m1=MNumber;
    string m2=Student2.getMNumber();
    m1.erase(0,1);
    m2.erase(0,1);

    // Convert strings to numbers and compare
    int mNum1=atoi(m1.c_str());
    int mNum2=atoi(m2.c_str());

    return mNum1>=mNum2;
}

#endif
