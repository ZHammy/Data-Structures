// This program demonstrates a two-dimensional array.
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

int main() {
	string fileName;                  // File name (or full path) to send data to
	ofstream data;                    // Output data stream
	const int NUM_DIVS = 3;           // Number of divisions
	const int NUM_QTRS = 4;           // Number of quarters
	double sales[NUM_DIVS][NUM_QTRS]; // Array with 3 rows and 4 columns.
	double totalSales = 0;            // To hold the total sales.
	int div, qtr;                     // Loop counters.

	cout << "This program will calculate the total sales of\n";
	cout << "all the company's divisions and store it to a file.\n";
	cout << "Enter the following sales information:\n\n";

	// Nested loops to fill the array with quarterly
	// sales figures for each division.
	for (div = 0; div < NUM_DIVS; div++) {
		for (qtr = 0; qtr < NUM_QTRS; qtr++) {
			cout << "Division " << (div + 1);
			cout << ", Quarter " << (qtr + 1) << ": $";
			cin >> sales[div][qtr];
		}
		cout << endl; // Print blank line.
	}

	// Prompt for filename
	cout << "Please enter where the output should be stored: ";
	cin >> fileName;

	// Open file stream for appending. Creates new file if one does not exist.
	data.open(fileName, ios::out | ios::app);

	// Output all final data to the given file name / path
	data << fixed << showpoint << setprecision(2);
	data << "The sales for the company is: $" << endl;
	data << "Div" << "\t" << "Q1" << "\t" << "Q2" << "\t" << "Q3" << "\t" << "Q4" << endl;


	// Nested loops to display the quarterly sales figures for each division and add up total sales.
	for (div = 0; div < NUM_DIVS; div++) {
		data << div + 1 << "\t";

		for (qtr = 0; qtr < NUM_QTRS; qtr++) {
			totalSales += sales[div][qtr];
			data << "$" << sales[div][qtr] << "\t";
		}
		data << endl; // Print blank line.
	}

	data << endl;
	data << "The total sales for the company are: $";
	data << totalSales << endl << endl;

	// Log data stream status to console before closing
	if (data.good()) {
		cout << "Success!" << endl;
	} else {
		cout << "Something went wrong.." << endl;
	}

	data.close();

	return 0;
}
