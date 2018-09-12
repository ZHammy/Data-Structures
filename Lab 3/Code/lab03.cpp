#include "Vector.cpp"
#include <limits.h>
#include <string>
using namespace std;

float checkFloat(string text);   // Make sure the user enters a valid float (x or y) input
double checkDouble(string text); // Make sure the user enters a valid double (mag or angle) input
bool checkEnd();                 // Check if the user wants to end the vector operations

int main () {
    float x = checkFloat("Enter an x value for your vector:  ");
    float y = checkFloat("Enter a y value for your vector:  ");
    Vector initialVector(x, y);
    initialVector.print(); // Print the initialized vector

    bool continueAsking = true;
    while(continueAsking){
        Vector secondVector;
        Vector resultVector;
        bool areVectorsSame = false;

        string selection = "";

        //Make sure the user enters a valid selection
        //string.compare returns 0 if an exact match
        while(selection.compare("add")&&selection.compare("subtract")&&selection.compare("multiply")&&selection.compare("divide")&&selection.compare("compare")){
            cout << "Select an operation to perform:  " << endl;
            cout << "add" << endl;
            cout << "subtract" << endl;
            cout << "multiply" << endl;
            cout << "divide" << endl;
            cout << "compare" << endl;
            cout << "Selection: "; cin >> selection;
            if (selection.compare("add")&&selection.compare("subtract")&&selection.compare("multiply")&&selection.compare("divide")&&selection.compare("compare")){
                cout << "Invalid Selection" << endl;
            }

            cout << endl; // Print blank line for readability
        }

        //Can sort of combine these 3 as they are very similar
        if (!selection.compare("add")||!selection.compare("subtract")||!selection.compare("compare")){
            int menu = 0;
            bool badChoice = true;
            //ask the user if they wish to supply the magnitude and angle or the coordinates for their vecotr
            while(badChoice){
                cout << "Would you like to supply coordinates or the magnitude and angle of your vector?" << endl;
                cout << "1:  coordinates" << endl;
                cout << "2:  magnitude and angle" << endl;
                cout << "Enter your choice:  ";
                cin >> menu;

                if(cin.fail()){
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');

                    cout << "Invalid Selection (wrong type)" << endl;
                }
                else if(menu==1 || menu==2){
                    badChoice = false;
                }
                else{
                    cout << "Invalid Selection (not an option)" << endl;
                }

                cout << endl; // Print blank line for readability
            }
            //Menu will either store a 1 or a 2 at this point, ask the user for the data of their vector
            if(menu == 1){//If the user is supplying coordinates
                secondVector.setX(checkFloat("Enter an x value for your vector:  "));
                secondVector.setY(checkFloat("Enter a y value for your vector:  "));
            }
            else{//If the user is supplying a magnitude and angle
                double mag = checkDouble("Enter the magnitude of your vector:  ");
                double angle = checkDouble("Enter an angle for your vector:  ");
                Vector temp(mag, angle);
                secondVector = temp;
            }
            if(!selection.compare("add")){
                resultVector = initialVector + secondVector;
            }
            else if(!selection.compare("subtract")){
                resultVector = initialVector - secondVector;
            }
            else if(!selection.compare("compare")){
                //Compare secondVector and initialVector
                if(initialVector == secondVector){
                    cout << "Your vectors are equal" << endl << endl;
                }
                else{
                    cout << "Your vectors are not equal" << endl << endl;
                }
            }
        }//end add subtract compare statement

        else if(!selection.compare("multiply")){
            double scalar = checkDouble("Enter a scalar to multiply your vector by:  ");
            resultVector = initialVector * scalar;
        }
        else{
            double scalar = checkDouble("Enter a scalar to divide your vector by:  ");
            resultVector = initialVector / scalar;
        }

        //Print the resulting vector if applicable
        //(Compare is a special result and doesnt have the same resultVector as the others)
        if(selection.compare("compare")){
            resultVector.print();
            //Set the new initialVector to the resulting vector
            initialVector = resultVector;
        }

        //Setting continueAsking=false will stop the loop
        continueAsking = checkEnd();

    }//end while loop

    return 0;

}


float checkFloat(string text){
    float val;
    bool badVal = true;
    while(badVal){
        cout << text;
        cin >> val;
        badVal = cin.fail();
        if(badVal){
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Invalid entry, please enter again" <<endl;
        }

        cout << endl; // Print blank line for readability
    }
    return val;
}


double checkDouble(string text){
    double val;
    bool badVal = true;
    while(badVal){
        cout << text;
        cin >> val;
        badVal = cin.fail();
        if(badVal){
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Invalid entry, please enter again" << endl;
        }

        cout << endl; // Print blank line for readability
    }
    return val;
}

bool checkEnd(){
    string val;
    bool dontEndLoop = false;
    bool badVal = true;
    while(badVal){
        cout << "Would you like to do another operation? (y/n):   ";
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
