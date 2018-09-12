#include <iostream>
#include <string>
#include <stdlib.h> //needed for rand
#include <time.h>

#include "HashTable.cpp"
#include "HashChain.cpp"
#include "Student.cpp"

using namespace std;

const int STUDENT_NUM = 50;
string getMNumber(int); // For mNumber formatting with rand, modified from Lab 8 Task 3

int main () {
    // Cumulative operation counts
    int tableOpCount = 0;
    int chainOpCount = 0;

    // Get the size of the current test
    // No error checking, assumes user is smart
    int arraySize = 0;
    cout << "Array size to test (>=" << STUDENT_NUM << "): " << endl;
    cin >> arraySize;
    srand(time(NULL)); // Seed rand

    // Tables we will be working with
    HashTable<Student> table(arraySize);
    HashChain<Student> chain(arraySize);

    for (int i = 0; i < STUDENT_NUM; i++) {
        // Make random m-number val
        // Extra processing ensures proper mNum length
        int mNumVal = rand()*rand() % 99999999;
        string mNumFull = getMNumber(mNumVal);

        // Make temp student with random M-Num
        // Remaining values should not be important, as hash table only needs mNum
        // Separate for table and chain to avoid memory conflictions
        Student *tempStudentTable = new Student("", "", mNumFull, "", 0.0);
        Student *tempStudentChain = new Student("", "", mNumFull, "", 0.0);

        table.addItem(tempStudentTable);
        chain.addItem(tempStudentChain);

        table.getItem(tempStudentTable);
        tableOpCount += table.getOpCount();

        chain.getItem(tempStudentChain);
        chainOpCount += chain.getOpCount();
    }

    cout << "Test results for array size: " << arraySize << endl;
    cout << "Table Operations: " << tableOpCount << endl;
    cout << "Chain Operations: " << chainOpCount << endl;

    return 0;
}

string getMNumber(int num){
    const int NUM_LENGTH = 8;
    string numString = to_string(num);

    // Add necessary amount of 0's so length is consistent
    if (numString.length() < NUM_LENGTH) {
        int diff = NUM_LENGTH - numString.length();
        for (int i = 0; i < diff; i++) { numString.insert(0, "0"); }
    }

    return "M"+numString;
}
