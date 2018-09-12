// HW1.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <array>
#include <climits>
#include <sstream>
#include "Tree.cpp"
#include "Word.cpp"
using namespace std;

//Book struct that will contain all data for each book
struct Book {
	// Constructor to initialize everything to be empty
	Book() {
		characterCount = 0;
		lineCount = 0;
		title = "";
		author = "";
		// Initialize each letterFreq value to zero
		for(int i=0;i<26;i++){
			letterFreq[i]=0;
		}
	}

	string title;
	string author;
	int characterCount;
	int letterFreq [26];
	int lineCount;

	string getFirstName();
	string getLastName();
};

void openFile(ifstream&);              // Prompt the user for a file name and open it if valid.
char askYesNo(string);                 // Ask the user with the given string, return y, Y, n, or N
Book parseContents(ifstream&);         // Put data from file into a Book struct
void writeToCatalog(Book);             // Write a Book struct into CardCatalog.txt
void displayLetterFreq(Book);          // If the user wants, display relative frequency of letters
void checkWord(Tree<Word>&); 				   //Checks if a word is in the tree and if so returns the count
int checkInt(string,int,int); 			// Prompt for ints within a range of two numbers

int main() {
	// Ask the user if they want to continue reading files
	// Set flag to true to exit loop
	bool stopAskingMe=false;
	while(!stopAskingMe){
		// Open file through user prompt
		ifstream myFile;
		openFile(myFile);

		// Parse contents of file and close stream
		Book myBook = parseContents(myFile);
		myFile.close();

		// Write contents to catalog file
		writeToCatalog(myBook);

		// Check if the user wishes to display the letter Frequency
		char selection = askYesNo("Would you like to display Letter Frequency? (y/n) :");
		// Display letter freq if answered yes
		if (selection=='y'||selection=='Y') displayLetterFreq(myBook);

		// Check if the user wants to input another book
		selection = askYesNo("Would you like to parse another book? (y/n) :" );
		// If n, set the flag to stop the loop, else do nothing and continue
		if (selection=='n'||selection=='N') stopAskingMe=true;
	}
	return 0;
}

string Book::getFirstName() {
	int index = author.find(" ");
	return author.substr(0, index);
}

string Book::getLastName() {
	int index = author.find(" ");
	return author.substr(index + 1);
}

void openFile(ifstream &myFile) {
	string fileName;
	cout << "Please enter the file name of your book:  " << endl;
	cin >> fileName;

	myFile.open(fileName);

	//If the file fails, force the user into entering a valid file name
	while (myFile.fail()) {
		myFile.close();
		cout << "File not found, please enter a valid file name" << endl;
		cin >> fileName;
		myFile.open(fileName);
	}
}

char askYesNo(string text) {
	bool badAnswer=true;
	char selection;
	cout << text <<endl;
	while(badAnswer||(selection!='y'&&selection!='Y'&&selection!='n'&&selection!='N')){
		cin >>selection;
		badAnswer=cin.fail();
		if(badAnswer||(selection!='y'&&selection!='Y'&&selection!='n'&&selection!='N')){
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout<<"Invalid Selection, please enter y or n"<<endl;
		}
	}
	return selection;
}

Book parseContents(ifstream &myFile) {
	// Create a Book to store the data
	// Values initialized with constructor
	Book myBook;
	//create the tree where we will do most of our stuff
	Tree<Word> myTree;
	// Get title (first line found)
	while (myBook.title.length() == 0) {
		string temp;
		getline(myFile, temp);

		if (temp.length() != 0) myBook.title = temp;
	}

	// Get author (second line found)
	while (myBook.author.length() == 0) {
		string temp;
		getline(myFile, temp);

		if (temp.length() != 0) myBook.author = temp;
	}

	// Get contents
	bool startCount = false;
	while (!myFile.eof()) {
		string temp;
		getline(myFile, temp);

		// If we have not started counting and found the contents, begin counting
		if (startCount == false && temp.find("Contents:") != -1) {
			startCount = true;

			// Increment counts. Do not include empty lines.
		} else if (temp.length() != 0) {
			//Go through the line of text and parse out words for putting them into the tree
			//**************************************************************************************************
			//TREE STUFF

			istringstream iss(temp);
			while(iss){
				//best line of code ive written in my life right here
				string word;
				iss>>word;
				//Need to check for puncuation and other stuff
				if(word.length()>0){
					//eliminates all space strings
					if(word.at(0)!=' '){
						if (!(isalpha(word.at(word.length()-1)))){
							word.pop_back();
							//Some words in PeterPan have repeated puncuation
							if (!(isalpha(word.at(word.length()-1)))){
								word.pop_back();
							}
						}
						if ((!(isalpha(word[0])))){
							word.erase(0);
						}
						if(word.length()>0){
							Word myWord(word);
							myTree.insert(myWord);
						}

					}
				}
			}
			// END TREE STUFF
			//**************************************************************************************************

			// Count total characters and subtract the number of empty spaces
			// (Count function comes from algorithm library)
			myBook.characterCount += temp.length() - count(temp.begin(), temp.end(), ' ');
			myBook.lineCount++;

			//Loop through the current line and check what letter it is
			for(int i=0;i<temp.length();i++){
				char current=tolower(temp.at(i));//change the character to lowercase
				//Could make a 26 case switch, but a loop is quicker to write
				for(int j=0;j<26;j++){
					//If the current character is a letter, store in the array
					if(current==(char(j+97))){
						myBook.letterFreq[j]++;
					}
				}
			}
		}
	}



	//*************************************************************************************************
	// TREE STUFF
	// This is where all the interaction with the tree goes down
	// Check if the user wishes to find a word
	bool stopAskingMe=false;
	while(!stopAskingMe){
		// Check if the user wishes to display the letter Frequency
		char selection = askYesNo("Would you like to look for a word? (y/n) :");
		// Display letter freq if answered yes
		if (selection=='y'||selection=='Y') {
			checkWord(myTree);
		}
		if (selection=='n'||selection=='N'){
			stopAskingMe=true;
		}
	}

	cout<<"Would you like to display all words Ascending or descending?   "<<endl;
	cout<<"1:  Ascending"<<endl;
	cout<<"2:  Descending"<<endl;
	int menu=checkInt("Enter your selection:  ",1,2);
	if(menu==1){
		Word* myArray=myTree.getAllAscending();
		cout<<"Word		Frequency"<<endl;
		for(int i=0;i<myTree.size();i++){
			Word temp=*(myArray+i);
			string text=temp.getText();
			int count=((temp.getCount())+1);
			cout<<text<<"		"<<count<<endl;
		}
		delete myArray;
	}
	else{
		Word* myArray=myTree.getAllDescending();
		cout<<"Word		Frequency"<<endl;
		for(int i=0;i<myTree.size();i++){
			Word temp=*(myArray+i);
			string text=temp.getText();
			int count=((temp.getCount())+1);
			cout<<text<<"	"<<count<<endl;
		}
		delete myArray;
	}

	return myBook;
}

void checkWord(Tree<Word>& myTree){
	cout<<"Enter a word to search for:  ";
	string myWord;
	cin>>myWord;

	// Create temp word using input string
	Word searchWord(myWord);
	// Search for our temp word
	Node<Word>* searchVal = myTree.find(searchWord);

	if(searchVal != nullptr){
		cout<<"Your word, "<<myWord<<", occured "<<searchVal->data.getCount()+1<<" times"<<endl;
	} else {
		cout<<"Your word, "<<myWord<<", was not found :/ "<<endl;
	}
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


//end tree stuff
//***********************************************************************************************************************



void writeToCatalog(Book myBook) {
	fstream data;
	string fileName = "CardCatalog.txt";
	// Try to open (to see if file exists)
	data.open(fileName, ios::in);

	// Log what we're doing based on if file was found
	if (data.fail()) cout << "Writing to new file " << fileName << "..." <<endl;
	else cout << "Appending existing file " << fileName << "..." << endl;

	// Close and re-open for appending
	data.close();
	data.open(fileName, ios::app);

	// Write information to file
	data << "Title: " << myBook.title << endl;
	data << "Author Full Name: " << myBook.author << endl;
	data << "Author First Name: " << myBook.getFirstName() << endl;
	data << "Author Last Name: " << myBook.getLastName() << endl;
	data << "Character Count: " << myBook.characterCount << endl;
	data << "Line Count: " << myBook.lineCount << endl << endl;
}

void displayLetterFreq(Book myBook) {
	//initialize a counter for figuring out the percentages
	double totalLetters = 0;
	for (int i = 0; i < 26; i++) {
		totalLetters =totalLetters + myBook.letterFreq[i];
	}
	for(int i=0;i<26;i++){
		printf("%c: %1.4f %% \n",char(i+97),(myBook.letterFreq[i] / totalLetters * 100));
	}
}
