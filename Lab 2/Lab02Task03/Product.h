#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <string>
#include <array>

using namespace std;

class Product{
private:
	int id;
	int units;
	double price;
	double sales;
public:
	Product();//Default Constructor
	Product(int, int, double);//if Id, units, and price are known
	void setID(int);
	void setUnits(int);
	void setPrice(double);
	void setSales();
	double getID();
	double getSales();
	int getUnits();
	double getPrice();
	void dumpData();//for testing
};
