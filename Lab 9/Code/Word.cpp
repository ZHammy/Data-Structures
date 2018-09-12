#ifndef WORD_CPP
#define WORD_CPP
#include "Word.h"
#include <iostream>
#include <string>
#include<bits/stdc++.h>
using namespace std;

//A default constructor is needed for the linked list to work
Word::Word(){
    text="";
    count=0;
}

Word::Word(string myWord){
    text=myWord;
    count=0;
}

string Word::getText(){
    return text;
}

int Word::getCount(){
    return count;
}


void Word::displayData(){
    cout<<text<<"   "<<count<<endl;
}


bool Word::operator < (Word &Word2) {
    //get both mNumbers and remove the M
    string m1=text;
    string m2=Word2.getText();
    transform(m1.begin(), m1.end(), m1.begin(), ::tolower);
    transform(m2.begin(), m2.end(), m2.begin(), ::tolower);
    return m1 < m2;
}

bool Word::operator > (Word &Word2) {
    //get both mNumbers and remove the M
    string m1=text;
    string m2=Word2.getText();
    transform(m1.begin(), m1.end(), m1.begin(), ::tolower);
    transform(m2.begin(), m2.end(), m2.begin(), ::tolower);
    return m1 > m2;
}

bool Word::operator == (Word &Word2) {
    string m1=text;
    string m2=Word2.getText();
    transform(m1.begin(), m1.end(), m1.begin(), ::tolower);
    transform(m2.begin(), m2.end(), m2.begin(), ::tolower);
    return (m1 == m2);
}

void Word::operator ++ () {
    count++;
}

#endif
