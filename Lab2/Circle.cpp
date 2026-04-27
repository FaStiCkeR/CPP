#include "Circle.h"
#include <iostream>
using namespace std;

Circle::Circle(double x, double y, double z, double radius)
    : Dot(x, y, z), radius(radius) {
}

Circle::Circle(const Circle &other)
    : Dot(other), radius(other.radius) {
}

double Circle::getRadius() const { return radius; }

void Circle::print() const {
    cout << "Центр: ";
    Dot::print();
    cout << ", Радиус: " << radius;
}

Circle::~Circle() {}
