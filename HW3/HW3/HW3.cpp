#include "deckFunctions.h"
#include <iostream>
#include "limits.h"
#include "List.cpp"

using namespace std;

bool checkYesNo(string);      // Prompt for a yes or no answer
int checkInt(string,int,int); // Prompt for ints within a range of two numbers

int main () {
    //make the initial deck that holds shuffled 52 cards
    Deck initialDeck=buildIntialDeck();
    //Each players deck
    Deck playerDeck;
    Deck botDeck;
    //Also declare a side pile that each player can use
    Stack playerSideDeck;
    Stack botSideDeck;
    //give each player 26 cards
    for(int i=0;i<26;i++){
        playerDeck.push_back(initialDeck.pop_front());
        botDeck.push_back(initialDeck.pop_front());
    }

    // Prompt user for max number of rounds
    bool setMaxRounds=checkYesNo("Do you want to limit the max amount of rounds? (y/n):  ");
    int roundsRemaining=INT_MAX;//Default value for the turn timer
    if(setMaxRounds){
        //If the user wants a round limit, get a valid turn limit
        roundsRemaining=checkInt("What would you like the maximum amount of turns to be?  ",1,INT_MAX);
    }

    //This is the actual gameplay loop
    while((playerDeck.getLength()||playerSideDeck.getLength())&&botDeck.getLength()&&roundsRemaining){
        bool goodPlayerTurn=false;//This will be used in combo with the try catches
        //to make sure the player has a valid move

        //Make temp cards to store each of the players cards for comparison
        Card playCurCard;
        Card botCurCard;
        Card playSideDeckCard;
        Card botSideDeckCard;

        int playerValue = 0; // Store total player card value
        int botValue = 0; // Store total bot card value

        //The AI wont attempt to make invalid moves so no need to make a flag for it
        while(!goodPlayerTurn){
            try{
                //Display cards in each player's hand
                cout<<"There are "<<playerDeck.getLength() + playerSideDeck.getLength()<<" cards in your hand"<<endl;
                cout<<"There are "<<playerDeck.getLength()<<" cards in your main deck"<<endl;
                cout<<"There are "<<playerSideDeck.getLength()<<" cards in your side deck"<<endl<<endl;

                cout<<"There are "<<botDeck.getLength()<<" cards in the bot's main deck"<<endl;

                // --- PLAYER TURN ---

                // If player has cards in their deck
                if(!playerDeck.isEmpty()) {
                    //Pick up the first card in the deck and peek at it
                    playCurCard=playerDeck.pop_front();
                    cout<<"Your picked up card: " << playCurCard.getCardType() << endl << endl;

                    bool turnDone = false; // To keep track of if a prompt was chosen

                    //If the side deck is not full, prompt to put this one in it
                    if(!playerSideDeck.isFull() && checkYesNo("Would you like to move this card to your side deck? (y/n)  ")){
                        cout << "Moving card onto side deck..." << endl;
                        playerSideDeck.push_front(playCurCard); // Put this card on the side deck

                        cout << "Picking up new card..." << endl << endl;
                        playCurCard=playerDeck.pop_front(); // Get new card

                        goodPlayerTurn = true;
                        turnDone = true; // Do not allow second prompt if this was chosen
                    }

                    //If the side stack is not empty, prompt to play a card from it
                    if (!turnDone && !playerSideDeck.isEmpty() && checkYesNo("Would you like to play a card from your side deck? (y/n)  ")){
                        cout << "Drawing card alongside card from side deck..." << endl << endl;
                        playSideDeckCard = playerSideDeck.pop_front();
                        goodPlayerTurn = true;
                        turnDone = true;
                    }

                    // If you reach this point and neither prompts were chosen, exit with a normal turn
                    if (!turnDone) {
                        cout << "Playing current card..." << endl << endl;
                        goodPlayerTurn = true;
                    }

                    // For storing the total value of the cards
                    // If the card was not initialized (not picked up), value is zero
                    int playerValueMain = !playCurCard.isError() ? playCurCard.getValue() : 0;
                    int playerValueSide = !playSideDeckCard.isError() ? playSideDeckCard.getValue() : 0;
                    playerValue = playerValueMain + playerValueSide; // Assign to player value

                // If the player has cards in the side deck but not the main
                } else if (!playerSideDeck.isEmpty()) {
                    cout << "Main stack empty! Playing card from side deck." << endl << endl;
                    playCurCard=playerSideDeck.pop_front();
                    goodPlayerTurn=true;
                }

                // --- BOT TURN ---
                // NOTE: Set up to be a simple AI, not a particularly difficult one

                // Get top card
                botCurCard = botDeck.pop_front();

                // Put a card onto the side deck if low number and able
                if (!botSideDeck.isFull() && botCurCard.getValue() <= 6) {
                    cout << "Bot places card onto side pile" << endl << endl;
                    botSideDeck.push_front(botCurCard);
                    botCurCard = botDeck.pop_front();

                // Use a card from the side deck if able unless card is particularly high
                } else if (!botSideDeck.isEmpty() && botCurCard.getValue() <= 9) {
                    cout << "Bot uses a card from the side pile" << endl << endl;
                    botSideDeckCard = botSideDeck.pop_front();
                } else {
                    cout << "Bot takes a normal turn" << endl << endl;
                }

                // For storing the total value of the cards
                // If the card was not initialized (not picked up), value is zero
                int botValueMain = !botCurCard.isError() ? botCurCard.getValue() : 0;
                int botValueSide = !botSideDeckCard.isError() ? botSideDeckCard.getValue() : 0;
                botValue = botValueMain + botValueSide; // Assign to player value
            }
            catch(List::ListUnderflow){
                cout<<"Error: No cards in that deck"<<endl;
            }
            catch(List::ListOverflow){
                cout<<"Error: That deck is full"<<endl;
            }
        }

        //End of player loop

        // Generate card type strings based on if a side deck card is played
        string playerCardString = playCurCard.getCardType();
        if (!playSideDeckCard.isError()) { playerCardString += " " + playSideDeckCard.getCardType(); }
        string botCardString = botCurCard.getCardType();
        if (!botSideDeckCard.isError()) { botCardString += " " + botSideDeckCard.getCardType(); }

        // Display all current cards
        cout<<"Player's card(s):  "<<playerCardString<<endl;
        cout<<"Total card value:  "<<playerValue<<endl;
        cout<<"Bot's card(s):     "<<botCardString<<endl;
        cout<<"Total card value:  "<<botValue<<endl<<endl;

        if(playerValue>botValue){
            cout<<"You win this round!"<<endl;
            playerDeck.push_back(playCurCard);
            playerDeck.push_back(botCurCard);
            if (!playSideDeckCard.isError()) {
                playerDeck.push_back(playSideDeckCard);
            }
        }
        else if(playerValue<botValue){
            cout<<"You lose this round!"<<endl;
            botDeck.push_back(playCurCard);
            botDeck.push_back(botCurCard);
        }
        else{//IF the players cards are equal, do war
            cout<<"WAR! "<<endl;
            bool stopWar=false;
            //create a temp deck that will keep the winners pile
            Deck warPile;
            warPile.push_back(playCurCard);
            warPile.push_back(botCurCard);

            // Put side deck cards into pile if they were played
            if (!playSideDeckCard.isError()) { warPile.push_back(playSideDeckCard); }
            if (!botSideDeckCard.isError())  { warPile.push_back(botSideDeckCard); }

            while(!stopWar){

                //First check if anyone can't play the war, if so end the loop and game
                if(playerDeck.getLength()<2){
                    //If the players main deck is too small, attempt to make it big enough with the side deck
                    if(playerSideDeck.getLength()+playerDeck.getLength()>=2){
                        while(playerDeck.getLength()<2){
                            playerDeck.push_back(playerSideDeck.pop_front());
                        }
                    }
                    //If the side deck cant make the main deck big enough
                    else{
                        stopWar=true;
                        //Also if they have a remaining card, just remove it so the end game check works
                        if(playerDeck.getLength()==1){
                            warPile.push_back(playerDeck.pop_front());
                        }
                        break;
                    }
                }
                else if(botDeck.getLength()<2){
                    stopWar=true;
                    cout << "Not enough cards!" << endl;
                    //Also if they have a remaining card, just remove it so the end game check works
                    if(botDeck.getLength()==1){
                        warPile.push_back(botDeck.pop_front());
                    }
                    break;
                }



                //Do the war if there are enough cards
                else{
                    //add the two "face down" cards to the warPile
                    warPile.push_back(playerDeck.pop_front());
                    warPile.push_back(botDeck.pop_front());
                    cout<<"You both put a face down card into the war pile"<<endl;
                    //grab the main cards to battle
                    playCurCard=playerDeck.pop_front();
                    botCurCard=botDeck.pop_front();
                    //put the cards in the war pile
                    warPile.push_back(playCurCard);
                    warPile.push_back(botCurCard);


                    //Display the player and bots cards
                    cout<<"Player's card:  "<<playCurCard.getCardType()<<endl;
                    cout<<"Bot's card:  "<<botCurCard.getCardType()<<endl<<endl;


                    //If the player wins, put all cards in the war pile in their deck
                    if(playCurCard.getValue()>botCurCard.getValue()){
                        cout<<"You win the war!"<<endl<<endl;
                        stopWar=true;
                        while(warPile.getLength()){
                            playerDeck.push_back(warPile.pop_front());
                        }
                    }
                    //if the bot wins, put all the war pile cards in their deck
                    else if(playCurCard.getValue()<botCurCard.getValue()){
                        cout<<"You lose the war!"<<endl<<endl;
                        stopWar=true;
                        while(warPile.getLength()){
                            botDeck.push_back(warPile.pop_front());
                        }
                    }
                }
            }
        }
        roundsRemaining--;
    }

    cout<<"There are "<<(playerDeck.getLength()+playerSideDeck.getLength())<<" cards in the your decks"<<endl;
    cout<<"There are "<<botDeck.getLength()+botSideDeck.getLength()<<" cards in the bot's decks"<<endl<<endl;
    //If there are limited rounds or not, this if will work
    if((playerDeck.getLength()+playerSideDeck.getLength())>botDeck.getLength()){
        cout<<"You WIN THE GAME!"<<endl;
    }
    else if((playerDeck.getLength()+playerSideDeck.getLength())<botDeck.getLength()){
        cout<<"You lose the game!"<<endl;
    }
    else{
        cout<<"You tied with the bot :/"<<endl;
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
