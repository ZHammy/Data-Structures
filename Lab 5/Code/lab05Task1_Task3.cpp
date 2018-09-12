#include <iostream>
#include "limits.h"
#include "Stable.cpp"

using namespace std;

bool checkYesNo(string);      // Prompt for a yes or no answer
int checkInt(string,int,int); // Prompt for ints within a range of two numbers

int main () {
    bool continueLoop=true;
    Stable myStable;
    while(continueLoop){
        cout<<"Select an option"<<endl;
        cout<<"1: Add a horse to the stable"<<endl;
        cout<<"2: Remove a horse from the stable"<<endl;
        cout<<"3: Check how many horses are in the stable"<<endl;
        cout<<"4: Quit"<<endl;
        int menu=checkInt("Enter your selection:  ",1,4);

        // Cases in own scopes to not redefine every time
        try{
            switch (menu){
                case 1:
                {
                    Horse* newHorse= new Horse;
                    myStable.addHorse(*newHorse);
                    cout << "Horse added!" << endl << endl;
                }
                break;
                case 2:
                    myStable.removeHorse();
                    cout << "Horse removed!" << endl << endl;
                    break;
                case 3:
                {
                    string verb = "";
                    if (myStable.getHorseCount() == 1) verb = "is ";
                    else verb = "are ";

                    cout<<"There " << verb << myStable.getHorseCount()<<" horse(s) in the stable"<<endl<<endl;
                }
                break;
                case 4:
                    continueLoop=false;
                    break;
                default:
                    break;
            }
        }
        catch(Stable::FullStable){
            cout<<"Error: Your stable is full"<<endl<<endl;
        }
        catch(Stable::EmptyStable){
            cout<<"Error: Your stable is empty"<<endl<<endl;
        }
    }
    return 0;
}

// Returns true if yes, false if no
bool checkYesNo(string text){
    string val;
    bool cashOut = false;
    bool badVal = true;
    while(badVal){
        cout << text;
        cin >> val;

        if(val == "y" || val == "Y" || val == "n" || val == "N"){
            badVal = false;
            cashOut = val == "y" || val == "Y"; // Return true if answered y
        }
        else {
            cout << "Invalid entry, please enter again" << endl;
        }

        cout << endl; // Print blank line for readability
    }
    return cashOut;
}

//Makes sure an entered int is within a range
int checkInt(string text, int min, int max){
    int val;
    bool badVal = true;
    while(badVal){
        cout << text;
        cin >> val;
        badVal = cin.fail();
        if(badVal||(val>max)||val<min){
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Invalid entry, please enter again" <<endl;
            badVal=true;
        }
        cout << endl; // Print blank line for readability
    }
    return val;
}
