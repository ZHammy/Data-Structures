#include "Product.h"

Product::Product() {//default the values to 0
 setID(0);
 setUnits(0);
 setPrice(0);
 setSales();
}
Product::Product(int a, int b, double c) {
 setID(a);
 setUnits(b);
 setPrice(c);
 setSales();
}
void Product::setID(int a) {
	id = a;
}
void Product::setUnits(int a) {
	units = a;
}
void Product::setPrice(double a) {
	price = a;
}
void Product::setSales() {
	sales = price*units;
}
double Product::getID() {
	return id;
}
double Product::getSales() {
	return sales;
}
int Product::getUnits() {
	return units;
}
double Product::getPrice() {
	return price;
}
void Product::dumpData() {
	cout << id << endl;
	cout << price << endl;
	cout << units << endl;
	cout << sales << endl;
}
