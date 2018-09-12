#ifndef PLAYER_H
#define PLAYER_H
#include "Die.cpp"

class Player{
private:
    int money;
public:
    Die myDie;       // Initializes with 6 sides by default

    // Constructors
    Player();        // Initialize money to 100 by default
    Player(int);     // Initialize player's money
    Player(int,int); // Initialize player's money and die sides respectively

    // Member functions
    int getMoney();
    void setMoney(int);
    int takeTurn();
};
#endif
