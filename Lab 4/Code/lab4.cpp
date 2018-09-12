#include "Animal.cpp"
#include "Horse.cpp"
#include "Fish.cpp"

#include <iostream>
#include "limits.h"

using namespace std;

bool askYesOrNo();         // Check to continue the loop or not
int checkMenu(string);     // Used for menu
void whatAnimal(Animal*);  // Outputs animals prints
void setAnimal(Animal*);   // Sets animal params
void setFish(Fish*);       // Sets fish params
void setHorse(Horse*);     // Sets horse params
int checkLegs(string);     // Prompt for leg number (int)
double checkHands(string); // Prompt for hands value (double)
bool checkBool(string);    // Prompt for yes or no answer (bool)

int main () {
    bool continueLoop=true;
    Fish * myAnimal = nullptr;
    while(continueLoop){
        cout<<"Would you like to make a fish, horse, or animal?  Select an option"<<endl;
        cout<<"1: Fish"<<endl;
        cout<<"2: Horse"<<endl;
        cout<<"3: Animal"<<endl;
        cout<<"4: Fish declared as an Animal"<<endl;
        cout<<"5: Horse declared as an Animal"<<endl;
        int menu=checkMenu("Enter your selection:  ");

        // Cases in own scopes to not redefine every time
        switch (menu){
            case 1:
                {
                    delete myAnimal;
                    Fish *myAnimal=new Fish;
                    // Initialize data through member functions
                    setFish(myAnimal);
                    cout << "From instance: " << endl;
                    myAnimal->move();
                    myAnimal->eat();
                    cout << endl;
                    whatAnimal(myAnimal);

                }
                break;
            case 2:
                {
                    delete myAnimal;
                    Horse *myAnimal=new Horse;
                    // Initialize data through member functions
                    setHorse(myAnimal);
                    cout << "From instance: " << endl;
                    myAnimal->move();
                    myAnimal->eat();
                    cout << endl;
                    whatAnimal(myAnimal);
                }
                break;
            case 3:
                {
                    delete myAnimal;
                    Animal *myAnimal=new Animal;
                    // Initialize data through member functions
                    setAnimal(myAnimal);
                    cout << "From instance: " << endl;
                    myAnimal->move();
                    myAnimal->eat();
                    cout << endl;
                    whatAnimal(myAnimal);
                }
                break;
            case 4:
                {
                    delete myAnimal;
                    // Initialize the data through constructor
                    double salty = checkBool("Does your fish live in saltwater?  ");
                    Animal *myAnimal = new Fish(salty);

                    cout << "From instance: " << endl;
                    myAnimal->move();
                    myAnimal->eat();
                    cout << endl;
                    whatAnimal(myAnimal);

                }
                break;
            case 5:
                {
                    delete myAnimal;
                    // Initialize the data through constructor
                    double hands = checkHands("How many hands tall is your horse?  ");
                    Animal *myAnimal = new Horse(hands);

                    cout << "From instance: " << endl;
                    myAnimal->move();
                    myAnimal->eat();
                    cout << endl;
                    whatAnimal(myAnimal);

                }
                break;
            default:
                break;
        }
        continueLoop=askYesOrNo();
    }
    return 0;
}

//Took this from our lab3 file, just asks yes or no
bool askYesOrNo(){
    string val;
    bool dontEndLoop = false;
    bool badVal = true;
    while(badVal){
        cout << "Would you like to make another animal? (y/n):   ";
        cin >> val;

        if(val == "y" || val == "Y" || val == "n" || val == "N"){
            badVal = false;
            dontEndLoop = val == "y" || val == "Y"; // Return true if answered y
        }
        else {
            cout << "Invalid entry, please enter again" << endl;
        }

        cout << endl; // Print blank line for readability
    }
    return dontEndLoop;
}


//Checks the intial menu
int checkMenu(string text){
    int val;
    bool badVal = true;
    while(badVal){
        cout << text;
        cin >> val;
        badVal = cin.fail();
        if(badVal||(val!=1&&val!=2&&val!=3&&val!=4&&val!=5)){
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Invalid entry, please enter again" <<endl;
            badVal=true;
        }

        cout << endl; // Print blank line for readability
    }
    return val;
}


//Check that the leg count is greater than 0
int checkLegs(string text){
    int val;
    bool badVal = true;
    while(badVal){
        cout << text;
        cin >> val;
        badVal = cin.fail();
        if(badVal||(val<0)){
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Invalid entry, please enter again" <<endl;
            badVal=true;
        }

        cout << endl; // Print blank line for readability
    }
    return val;
}

//Asks a question and get yes or no
bool checkBool(string text){
    int val;
    bool badVal = true;
    while(badVal){
        cout << text<<endl;
        cout<<"1: Yes"<<endl;
        cout<<"2: No"<<endl;
        cin >> val;
        badVal = cin.fail();
        if(badVal||(val!=1&&val!=2)){
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Invalid entry, please enter again" <<endl;
            badVal=true;
        }

        cout << endl; // Print blank line for readability
    }
    if(val==1) return true;
    return false;
}


//Check that the hand count is greater than 0
double checkHands(string text){
    double val;
    bool badVal = true;
    while(badVal){
        cout << text;
        cin >> val;
        badVal = cin.fail();
        if(badVal||(val<=0)){
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Invalid entry, please enter again" <<endl;
            badVal=true;
        }

        cout << endl; // Print blank line for readability
    }
    return val;
}

//Display Functions
void whatAnimal(Animal *ani){
    cout << "From function: " << endl;
    ani->move();
    ani->eat();
}


//These functions just help out with the setters and keeping the main clean
void setAnimal(Animal *ani){
    int legCount=checkLegs("How many legs does your animal have?  ");
    bool hair=checkBool("Does your Animal have Hair?");
    ani->setLegs(legCount);
    ani->setHair(hair);
}
void setFish(Fish *ani){
    bool salty=checkBool("Does your fish live in saltwater?  ");
    ani->setIsSaltWater(salty);
}
void setHorse(Horse *ani){
    double handCount=checkHands("How many hands tall is your horse?  ");
    ani->setHands(handCount);
}
