#include "List.cpp"
#include <iostream>

using namespace std;

void test(); // Temporary testing for classes

int main () {
    test();
    return 0;
}

void test () {
    List jontron;

    try {
        for (int i = 1; i <= 10; i++) {
            jontron.push_back(i);
            cout << "Length:  " << jontron.getLength() << endl;
            cout << "Top val: " << jontron.top() << endl << endl;
        }

        for (int i = 1; i <= 11; i++) {
            cout << "Length:  " << jontron.getLength() << endl;
            cout << "Bot val: " << jontron.pop_back() << endl << endl;
        }
    } catch (List::ListUnderflow) {
        cout << "ERROR: There was indeed an underflow" << endl;
    }
}
