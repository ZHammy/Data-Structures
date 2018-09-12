#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

void openFile(ifstream&);
void displayTenLines(ifstream&);

int main() {
	ifstream data;
	openFile(data);

	if (data.fail()) {
		cout << "ERROR: Failed to read. (Is your file name correct?)" << endl;
	} else {
		displayTenLines(data);
	}

	data.close();
}

void openFile(ifstream& stream) {
	string fileName;

	cout << "Full file name to open: ";
	cin >> fileName;

	stream.open(fileName, ios::in);
}

void displayTenLines(ifstream& stream) {
	string thisLine;

	// Loop a maximum of 10 times to read 10 lines
	for (int i = 1; i <= 10; i++) {
		// Get next line and store in string
		getline(stream, thisLine);

		// Output this line
		cout << thisLine << endl;

		// If reached end of file, exit
		if (stream.eof()) break;
	}
}
