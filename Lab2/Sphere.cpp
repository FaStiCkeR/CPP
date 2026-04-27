#include "Sphere.h"
#include <iostream>
#include <cmath>

using namespace std;

Sphere::Sphere(double x, double y, double z, double rOuter, double rInner, double density)
    : Circle(x, y, z, rOuter), innerRadius(rInner), density(density) {
}

Sphere::Sphere(const Sphere &other)
    : Circle(other), innerRadius(other.innerRadius), density(other.density) {
}

double Sphere::getInnerRadius() const { return innerRadius; }

double Sphere::volume() const {
    if (innerRadius >= radius) return 0.0;
    double const R3 = radius * radius * radius;
    double const r3 = innerRadius * innerRadius * innerRadius;
    return (4.0 / 3.0) * M_PI * (R3 - r3);
}

double Sphere::weight() const {
    return volume() * density;
}


void Sphere::print() const {
    std::cout << "Полный шар: " << std::endl;
    std::cout << "Центр: ";
    Dot::print();
    std::cout << "Внешний радиус: " << radius << std::endl;
    std::cout << "Внутренний радиус: " << innerRadius << std::endl;
    std::cout << "Объем: " << volume() << std::endl;
}

double Sphere::compare(const Sphere &other) const {
    const double w1 = weight();
    const double w2 = other.weight();
    if (w1 > w2) {
        return 1.0;
    } else if (w1 < w2) {
        return -1.0;
    } else {
        return 0.0;
    }
}

Sphere::~Sphere() {}