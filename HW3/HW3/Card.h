#ifndef CARD_H
#define CARD_H

#include <string>
using namespace std;

class Card{
private:
    int value; // Used to determine which cards are higher value
    string cardType; // Used to store Ace/King/Queen/etc. for easy displaying
public:
    // Constructors
    Card();
    Card(int,string); // Set value and cardType respectively

    // Getters
    int getValue();
    string getCardType();
    bool isError(); // Determine if this card has been set yet
};

#endif
