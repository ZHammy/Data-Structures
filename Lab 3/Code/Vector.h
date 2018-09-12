class Vector {
private:
    float x;       // Vector x component
    float y;       // Vector y component
    double mag;    // Vector magnitude
    double angle;  // Vector angle

public:
    // Contructors
    Vector();
    Vector(float, float);
    Vector(double, double);

    // Getters
    float getX();
    float getY();
    double getMag();
    double getAngle();

    // Setters (should calculate mag and angle)
    void setX(float);
    void setY(float);

    // Print the current values
    void print();

    // Operator overloads
    Vector operator + (Vector&);
    Vector operator - (Vector&);
    Vector operator * (const double&);
    Vector operator / (const double&);
    bool operator == (Vector&);
};
