#ifndef LABS_OOP_SPHERE_H
#define LABS_OOP_SPHERE_H
#include "Circle.h"

class Sphere : public Circle {
private:
    double innerRadius;
    double density;

public:
    Sphere(double x, double y, double z, double rOuter, double rInner, double density);

    double getInnerRadius() const;

    double volume() const;

    double weight() const;

    void print() const;

    double compare(const Sphere &other) const;
};

#endif //LABS_OOP_SPHERE_H