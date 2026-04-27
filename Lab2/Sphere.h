#ifndef LABS_OOP_SPHERE_H
#define LABS_OOP_SPHERE_H
#include "Circle.h"

class Sphere : public Circle {
private:
    double innerRadius;
    double density;

public:
    Sphere(double x = 0, double y = 0, double z = 0, double rOuter = 1, double rInner = 0.5, double density = 1);

    Sphere(const Sphere &other);

    double getInnerRadius() const;

    double volume() const;

    double weight() const;

    void print() const;

    double compare(const Sphere &other) const;

    ~Sphere() override;
};

#endif //LABS_OOP_SPHERE_H