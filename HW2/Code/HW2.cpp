#include "Player.cpp"
#include <iostream>
#include "limits.h"

using namespace std;

bool checkYesNo(string);      // Prompt for a yes or no answer
int checkInt(string,int,int); // Prompt for ints within a range of two numbers
int playRound(Die, Die, int); // Play a round with dice and wager. Returns money won or 0 if lost

// Handle hard mode round wins or losses as needed
// Takes in user, house, then current consecutive losses
void handleHardWin(Player&, Player&, int&);
void handleHardLoss(Player&, Player&, int&);

const int minMoney=1;
const int maxMoney=INT_MAX;
const int minSides=6;
const int maxSides=20;

int main () {
    // Initial prompts
    int money=checkInt("Enter the starting amount of money:  ",minMoney,maxMoney);
    int sides=checkInt("Enter the amount of sides for the dice to be used (6-20):  ",minSides,maxSides);
    bool hard=checkYesNo("Do you want to play in hard mode? (y/n)  ");

    // Players
    Player user(money,sides);
    Player house(0,sides); // Theoretically has infinite money

    // Set seed for RNG
    srand(time(NULL));

    // Hard mode loss counter
    int losses = 0;

    // Play the game
    // Loops until a break statement is reached
    while (true) {
        //Show the money total at start of round
        cout<<"Your money:  $";
        cout<<user.getMoney()<<endl;

        // If the user has no more money, exit
        if (user.getMoney() == 0) {
            cout << "You're out of money! You lost $" << money << endl;
            break;
        // If the user wishes to cash out, exit
        } else if (checkYesNo("Do you want to cash out? (y/n)  ")) {
            cout << "Your ending money:  $"
                 << user.getMoney() << endl;
            break;
        }

        // -- Play the round if the user reaches this point --

        int wager = checkInt("What is your wager?  $", 1, user.getMoney());
        int thisRound = playRound(user.myDie, house.myDie, wager);

        // If the user won the round...
        if (thisRound > 0) {
            user.setMoney(user.getMoney() + thisRound);

            // If in hard mode, handle win
            if (hard) {
                handleHardWin(user, house, losses);
            }

        // If the user lost the round...
        } else {
            // Subtract user money
            user.setMoney(user.getMoney() - wager);

            // If in hard mode, handle loss
            // Do not allow house dice to get less sides than player dice
            if (hard && house.myDie.getSides() > sides) {
                handleHardLoss(user, house, losses);
            }
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

int playRound(Die userDie, Die houseDie, int wager) {
    const int userScore  = userDie.roll();
    const int houseScore = houseDie.roll();

    // Output scores
    cout << "User score:  " << userScore << endl
         << "House score: " << houseScore << endl;

    // User wins if their score is greater than house
    // House wins ties as well
    if (userScore > houseScore) {
        cout << "Win!" << endl << endl;
        return wager;
    // Return 0 if the user lost
    } else {
        cout << "Loss!" << endl << endl;
        return 0;
    }
}

void handleHardWin (Player &user, Player &house, int &losses) {
    // Increase the house die sides
    losses = 0;
    house.myDie.setSides(house.myDie.getSides() + 1);
    cout << "House die sides increased to: " << house.myDie.getSides()
         << endl << endl;
}

void handleHardLoss (Player &user, Player &house, int &losses) {
    // Increment the loss counter
    losses++;

    // If two consecutive losses, decrease die sides
    if (losses >= 2) {
        house.myDie.setSides(house.myDie.getSides() - 1);
        losses = 0;
        cout << "House die sides decreased to: " << house.myDie.getSides()
             << endl << endl;
    }
}
