#include "Product.cpp"
#include <fstream>
#include <sstream>
using namespace std;

// NUM_PRODS is the number of products produced.
const int NUM_PRODS = 6;
int getFileData(string, Product[],int);//do the file IO to store products in the array
void showTotals(Product[], int);//show the total units and sales
void showOrder(Product[], int);//show the products by sales
void dualSort(Product[], int);//Sort the array by sales


int main()
{

	Product myArray[NUM_PRODS];
	cout << "Enter a text file to pull data from:  " << endl;
	string fileName;
	cin >> fileName;
	cout << endl;
	int prodCount=getFileData(fileName, myArray,NUM_PRODS);
	showOrder(myArray, prodCount);
	showTotals(myArray, prodCount);
	return 0;
}


void showTotals(Product myArray[], int prodCount) {
	//Use try here in case there's some invalid data or the array has no data

	int totalUnits = 0;
	double totalSales = 0.0;
	if (prodCount>0) {//Just in case the array has 0 elements or invalid data
		for (int index = 0; index <prodCount; index++)
		{
			totalUnits += myArray[index].getUnits();
			totalSales += myArray[index].getSales();
		}
	}
	else {
		//set the values to -1 if the array size is 0
		int totalUnits = -1;
		double totalSales = -1;
	}
	cout << "Total units Sold:  " << totalUnits << endl;
	cout << "Total sales:      $" << totalSales << endl;

}
void showOrder(Product myArray[], int prodCount) {

	if (prodCount>0) {//Just in case the array has 0 elements or invalid data
		cout << "Product Number\tSales\n";
		cout << "----------------------------------\n";
		for (int index = 0; index < prodCount; index++)
		{
			cout << myArray[index].getID() << "\t\t$";
			cout << setw(8) << myArray[index].getSales() << endl;
		}
		cout << endl;
	}
	else {
		//for if there aren't products
		cout << "No Products" << endl;
	}
}
void dualSort(Product myArray[], int prodCount) {
	int startScan, maxIndex, tempid;
	Product maxValue;
	//Check if the array size is greater than 0
	if (prodCount>0) {
		for (startScan = 0; startScan < (prodCount - 1); startScan++)
		{
			maxIndex = startScan;
			maxValue = myArray[startScan];
			//(sizeof(myArray) / sizeof(myArray[0])) is really why a try catch is used
			for (int index = startScan + 1; index < prodCount; index++)
			{
				if (myArray[index].getSales() > maxValue.getSales())
				{
					maxValue = myArray[index];
					maxIndex = index;
				}
			}
			myArray[maxIndex] = myArray[startScan];
			myArray[startScan] = maxValue;
		}
	}
	else {
		cout << "No Products"<<endl;
	}
}

int getFileData(string fileName, Product myArray[], int prodCount) {

	//Counter to track the amount of products found in the text file
	//Needed for when the file has less than the required entries
	int existingProdCount = 0;
	ifstream prodData;
	prodData.open(fileName);
	if (prodData.fail()) {
		//Just return -1
		return existingProdCount;
	}
	int pos;
	string text;//stores the contents of the file
	for (int i = 0; i < prodCount; i++) {

		//get the ID
		getline(prodData, text);
		if (prodData.eof()) break; //If we have reached the end of the file, quit the loop
		Product temp; //Initiate the temp after eof check so we do not return an empty Product
		pos = text.find(":");
		text = text.substr((pos + 1));
		stringstream stringToInt(text);
		int id = 0;
		stringToInt >> id;
		temp.setID(id);

		//get the units
		getline(prodData, text);
		pos = text.find(":");
		text = text.substr((pos + 1));
		stringstream stringToInt2(text);
		int units = 0;
		stringToInt2 >> units;
		temp.setUnits(units);

		//get the price
		getline(prodData, text);
		pos = text.find(":");
		text = text.substr((pos+1));
		stringstream stringToDouble(text);
		double price = 0;
		stringToDouble >> price;
		temp.setPrice(price);

		getline(prodData, text);//Ths will get a blank line

		//store the temp product into the array
		temp.setSales();
		//temp.dumpData();
		myArray[i] = temp;
		existingProdCount++;

	}
	prodData.close();
	//after grabbing all the data and storing it in an array, run the sort function
	dualSort(myArray, prodCount);
	return existingProdCount;

}
