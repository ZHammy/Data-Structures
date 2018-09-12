#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student {
    private:
        string FirstName;
        string LastName;
        string MNumber;
        string Birthday;
        double GPA;
    public:
        // Constructors
        Student();
        // First name, last name, M-number, birthday, and GPA respectively
        // GPA defaults to 0 if not given
        Student(string,string,string,string,double);

        // Basic getters
        string getName();
        string getMNumber();
        double getGPA();

        // Getters that need processing
        int getAge();
        void displayData(); // Display members using ASCII art

        // Operator Overloads
        bool operator < (Student&);
        bool operator > (Student&);
        bool operator == (Student&);
        bool operator >= (Student&);
        bool operator <= (Student&);
};

#endif
