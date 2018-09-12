#include <iostream>
#include "Tree.cpp"
#include "Word.cpp"

using namespace std;

int main () {
    Tree<int> Jontron;


    //Jontron.print();
    Jontron.insert(3);
    Jontron.insert(4);
    Jontron.insert(5);
    Jontron.insert(100);
    Jontron.insert(101);
    Jontron.insert(50);
    Jontron.insert(0);
    // for (int i = 0; i < 10; i++){ Jontron.insert(102 + i); }
    // for (int i = 0; i < 10; i++){ Jontron.insert(-1 - i);}
    //Jontron.print();

    cout << "Should be 100: " << endl;
    cout << Jontron.find(100)->data << endl;
    cout << "Should be 5: " << endl;
    cout << Jontron.find(5)->data << endl;
    cout << "Should be 102: " << endl;
    Jontron.insert(101);
    cout << Jontron.find(102)->data << endl;
    int* myArray=Jontron.getAllAscending();
    for(int i=0;i<7;i++){
        cout<<i<<":  "<<*(myArray+i)<<endl;
    }
    int* myArray2=Jontron.getAllDescending();
    for(int i=0;i<7;i++){
        cout<<i<<":  "<<*(myArray2+i)<<endl;
    }
    Jontron.emptyTree();
    Jontron.emptyTree();

    Jontron.print();


    return 0;
}
