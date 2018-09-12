#include <iostream>
#include <string>
#include "HashTable.cpp"
#include "HashChain.cpp"
#include "Student.cpp"

using namespace std;

int main () {
    Student* students[20];
    HashChain<Student> table(20);

    for (int i = 0; i < 20; i++) {
        string first = "Swag";
        string second = to_string(i+1);
        string mnum = "M" + to_string(10000000 + i);
        string birth = "01/01/" + to_string(80 + i);
        double gpa = i / 5;

        students[i] = new Student(first, second, mnum, birth, gpa);
        table.addItem(students[i]);
    }

    cout << table.getItem(students[0])->getName() << endl;
    cout << table.getItem(students[0])->getName() << endl;
    cout << table.getItem(students[5])->getName() << endl;
    cout << table.getItem(students[19])->getName() << endl;

    // table.addItem(new Student("This", "Will", "Not", "work", 3.3));

    cout << "Removed: " << table.removeItem(students[0])->getName() << endl;
    cout << "Removed: " << table.removeItem(students[5])->getName() << endl;
    cout << "Removed: " << table.removeItem(students[19])->getName() << endl;

    table.getItem(students[0]);
    table.getItem(students[5]);
    table.getItem(students[19]);

    return 0;
}
