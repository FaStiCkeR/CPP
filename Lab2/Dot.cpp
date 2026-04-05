#include "Dot.h"
#include <iostream>
using namespace std;

Dot::Dot(double x, double y, double z) : x(x), y(y), z(z) {
}

double Dot::getX() const { return x; }
double Dot::getY() const { return y; }
double Dot::getZ() const { return z; }

void Dot::print() const {
    cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
}