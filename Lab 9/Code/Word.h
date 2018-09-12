#ifndef WORD_H
#define WORD_H

#include <string>
using namespace std;

class Word {
    private:
        string text;
        int count;
    public:
        // Constructors
        Word();
        Word(string);

        // Basic getters
        string getText();
        int getCount();


        void displayData(); // Display text

        // Operator Overloads
        bool operator < (Word&);
        bool operator > (Word&);
        bool operator == (Word&);
        void operator ++ ();
};

#endif
