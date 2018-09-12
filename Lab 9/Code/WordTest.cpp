#include "Word.cpp"

using namespace std;

int main() {
    Word jeff("Jeff");
    Word bork("Borker");
    Word Bork("borker");
    if(jeff>bork){
        cout<<"RIGHT 1"<<endl;
    }
    if(bork>jeff){
        cout<<"WRONG 2"<<endl;
    }
    if(jeff<bork){
        cout<<"WRONG 3"<<endl;
    }
    if(bork<jeff){
        cout<<"RIGHT 4 "<<endl;
    }
    if(bork==Bork){
        cout<<"Doggo 5"<<endl;
    }
    ++bork;
    bork.displayData();
    return 0;
}
