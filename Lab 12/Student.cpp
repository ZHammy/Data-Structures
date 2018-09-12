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
    cout << "Name:    " << getName() << endl
         << "MNumber: " << MNumber << endl;
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

// ---- Lab 10 addition -----
Student::operator string() const {
    return MNumber;
}

#endif
