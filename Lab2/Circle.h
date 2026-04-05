#ifndef LABS_OOP_CIRCLE_H
#define LABS_OOP_CIRCLE_H
#include "Dot.h"

class Circle : public Dot {
protected:
    double radius;

public:
    Circle(double x, double y, double z, double radius);

    double getRadius() const;

    virtual void print() const;
};

#endif //LABS_OOP_CIRCLE_H