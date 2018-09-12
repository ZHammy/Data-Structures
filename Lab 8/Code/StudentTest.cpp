#include "Student.cpp"
#include <iostream>
using namespace std;
int main(){
    Student jotaro("Jotaro","Kujo","M10120210","12/25/89");
    Student kakyoin("Noriyaki","Kakyoin","M10120211","11/14/91",2.0);
    Student avdol("Muhammad","Avdol","M10120209","11/14/99",2.0);
    cout<<jotaro.getName()<<endl;
    cout<<jotaro.getAge()<<" Years old"<<endl;
    cout<<"MNumber:  "<<jotaro.getMNumber()<<endl<<endl;
    cout<<kakyoin.getName()<<endl;
    cout<<kakyoin.getAge()<<" Years old"<<endl;
    cout<<"MNumber:  "<<kakyoin.getMNumber()<<endl<<endl;
    cout<<avdol.getName()<<endl;
    cout<<avdol.getAge()<<" Years old"<<endl;
    cout<<"MNumber:  "<<avdol.getMNumber()<<endl<<endl;

    if(jotaro==jotaro){
        cout<<"EQUALS WORKS"<<endl;
    }
    if(jotaro<kakyoin){
        cout<<"LESS WORKS"<<endl;
    }
    if(kakyoin>jotaro){
        cout<<"GREATER WORKS"<<endl;
    }

    return 0;
}
