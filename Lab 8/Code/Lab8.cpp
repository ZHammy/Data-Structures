#include <iostream>
#include <string>
#include "List.cpp"

using namespace std;

int main () {
    List<int> john;

    john.addItem(new int(10));
    cout << "10 in list: " << *john.isInList(new int(10)) << endl;
    cout << "3 in list:  " << *john.isInList(new int(3)) << endl;
    cout << "5 in list:  " << *john.isInList(new int(5)) << endl;
    john.addItem(new int(2));
    john.addItem(new int(3));
    cout << "10 in list: " << *john.isInList(new int(10)) << endl;
    cout << "3 in list:  " << *john.isInList(new int(3)) << endl;
    cout << "5 in list:  " << *john.isInList(new int(5)) << endl;
    john.addItem(new int(0));
    john.addItem(new int(5));
    cout << "10 in list: " << *john.isInList(new int(10)) << endl;
    cout << "3 in list:  " << *john.isInList(new int(3)) << endl;
    cout << "5 in list:  " << *john.isInList(new int(5)) << endl << endl;

    Node <int> *nextVal = john.seeNext();
    while (nextVal != nullptr) {
        cout << nextVal->data << endl;
        nextVal = john.seeNext();
    }
    cout << endl;

    cout << *john.getItem(new int(10)) << endl;
    cout << *john.getItem(new int(3)) << endl << endl;

    john.displayAll();

    return 0;
}
