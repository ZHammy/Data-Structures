#include <iostream>
#include "limits.h"
#include "AnimalCollection.cpp"
#include "Fish.cpp"

using namespace std;

bool checkYesNo(string);      // Prompt for a yes or no answer
int checkInt(string,int,int); // Prompt for ints within a range of two numbers

int main () {
    bool continueLoop=true;
    AnimalCollection<Fish> myCollection;
    while(continueLoop){
        cout<<"Select an option"<<endl;
        cout<<"1: Add a animal to the collection"<<endl;
        cout<<"2: Remove an animal from the collection"<<endl;
        cout<<"3: Check how many animals are in the collection"<<endl;
        cout<<"4: Quit"<<endl;
        int menu=checkInt("Enter your selection:  ",1,4);

        // Cases in own scopes to not redefine every time
        try{
            switch (menu){
                case 1:
                {
                    Fish* newFish= new Fish;
                    myCollection.addAnimal(*newFish);
                    cout << "Animal added!" << endl << endl;
                }
                break;
                case 2:
                    myCollection.removeAnimal();
                    cout << "Animal removed!" << endl << endl;
                    break;
                case 3:
                    {
                        string verb = "";
                        if (myCollection.getAnimalCount() == 1) verb = "is ";
                        else verb = "are ";

                        cout<<"There " << verb << myCollection.getAnimalCount()<<" animal(s) in the stable"<<endl<<endl;
                    }
                    break;
                case 4:
                    continueLoop=false;
                    break;
                default:
                    break;
            }
        }
        catch(AnimalCollection<Fish>::FullAnimalCollection){
            cout<<"Error: Your Animal Collection is full"<<endl<<endl;
        }
        catch(AnimalCollection<Fish>::EmptyAnimalCollection){
            cout<<"Error: Your Animal Collection is empty"<<endl<<endl;
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
