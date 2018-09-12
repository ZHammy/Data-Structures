#include "Vector.h"
#include <cmath>
#include <iostream>
#define PI 3.14159265

using namespace std;

Vector::Vector(){
    x = 0;   // Initialize x value
    setY(0); // Initialize y, mag, and angle
}

Vector::Vector(float x_in, float y_in){
    x = x_in;   // Initialize x value
    setY(y_in); // Initialize y, mag, and angle
}

Vector::Vector(double mag_in, double angle_in){
    /* Reference:
    cos(angle) = x / mag
    sin(angle) = y / mag */

    mag = mag_in;
    angle = angle_in;

    double rad = angle / 180 * PI;
    x = cos(rad) * mag;
    y = sin(rad) * mag;
}

float Vector::getX(){
    return x;
}

float Vector::getY(){
    return y;
}

double Vector::getMag(){
    return mag;
}

double Vector::getAngle(){
    return angle;
}

void Vector::setX(float newX){
    x = newX;
    //Adds the squares of x and y then takes the sqaure root
    mag = pow((pow(x,2) + pow(y,2)), .5);
    //angle=arctangent(y/x)
    //By default function returns radians so convert to degrees
    //atan2 allows for values from -180 to 180
    angle = atan2(y,x) * (180 / PI);
}

void Vector::setY(float newY){
    y = newY;
    //Adds the squares of x and y then takes the sqaure root
    mag = pow((pow(x,2) + pow(y,2)), .5);
    //angle=arctangent(y/x)
    //By default atan2 function returns radians so convert to degrees
    //atan2 allows for values from -180 to 180
    angle = atan2(y,x) * (180 / PI);
}

void Vector::print() {
    cout << "Current vector values:" << endl;
    cout << "X-Coordinate: " << x << endl;
    cout << "Y-Coordinate: " << y << endl;
    cout << "Magnitude:    " << mag << endl;
    cout << "Angle:        " << angle << endl << endl;
}


// Operator overloads
Vector Vector::operator + (Vector &vectorRight) {
    Vector returnVector;
    returnVector.setX(getX() + vectorRight.getX());
    returnVector.setY(getY() + vectorRight.getY());
    return returnVector;
}

Vector Vector::operator - (Vector &vectorRight) {
    Vector returnVector;
    returnVector.setX(getX() - vectorRight.getX());
    returnVector.setY(getY() - vectorRight.getY());
    return returnVector;
}

Vector Vector::operator * (const double &scalar) {
    Vector returnVector;
    returnVector.setX(getX() * scalar);
    returnVector.setY(getY() * scalar);
    return returnVector;
}

Vector Vector::operator / (const double &scalar) {
    Vector returnVector;
    returnVector.setX(getX() / scalar);
    returnVector.setY(getY() / scalar);
    return returnVector;
}

bool Vector::operator == (Vector &vectorRight) {
    return getX() == vectorRight.getX() && getY() == vectorRight.getY();
}
