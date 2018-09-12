#include "Stack.cpp"
#include "Deck.cpp"
#include <cstdlib>// for srand and rand
#include <ctime>// for time
using namespace std;
//this file is meant to keep the main nice and cleanish

//This function will build a Deck of 52 cards
//The cards will be shuffled first and then distribuited to the players

Deck buildIntialDeck(){
    //Going to initally put cards in here to shuffle them
    Card deck[52];
    //This game doesn't care about suit so just loop 4 times
    for(int i=0;i<4;i++){
        deck[0+13*i]=Card(2,"2");
        deck[1+13*i]=Card(3,"3");
        deck[2+13*i]=Card(4,"4");
        deck[3+13*i]=Card(5,"5");
        deck[4+13*i]=Card(6,"6");
        deck[5+13*i]=Card(7,"7");
        deck[6+13*i]=Card(8,"8");
        deck[7+13*i]=Card(9,"9");
        deck[8+13*i]=Card(10,"10");
        deck[9+13*i]=Card(11,"Jack");
        deck[10+13*i]=Card(12,"Queen");
        deck[11+13*i]=Card(13,"King");
        deck[12+13*i]=Card(14,"Ace");
    }
    //Now that their is an array of cards, time to shuffle them
    srand(time(0));//seed the rng
    //This basic algorithm will just swap various cards around 52 times
    for(int i=0;i<52;i++){
        int rng=rand()%52;
        Card temp=deck[i];
        deck[i]=deck[rng];
        deck[rng]=temp;
    }
    //Now that deck has been shuffled, create a Deck that will store the Cards
    Deck retDeck;
    for(int i=0;i<52;i++){
        retDeck.push_back(deck[i]);
    }
    return retDeck;
}
