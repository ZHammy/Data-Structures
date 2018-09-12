#ifndef PLAYER_CPP
#define PLAYER_CPP
#include "Player.h"

//constructors
Player::Player(){
    //set the money to 100 by default
    money=100;
    //leave die as default 6
}
Player::Player(int x){
    //set the players money to x
    money=x;
    //Keep the Default die sides
}

Player::Player(int x,int y){
    //set player money to x
    money=x;
    //set an amount of die sides
    myDie.setSides(y);
}

int Player::getMoney(){
    return money;
}

void Player::setMoney(int x){
    //set money to x
    money=x;
}

int Player::takeTurn(){
    return myDie.roll();
}
#endif
