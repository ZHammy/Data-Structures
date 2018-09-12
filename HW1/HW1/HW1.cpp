// HW1.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <array>
#include <climits>
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
	return myBook;
}

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
