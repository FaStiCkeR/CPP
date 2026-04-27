#ifndef LABS_OOP_CIRCLE_H
#define LABS_OOP_CIRCLE_H
#include "Dot.h"

class Circle : public Dot {
protected:
    double radius;

public:
    explicit Circle(double x = 0, double y = 0, double z = 0, double radius = 1);

    Circle(const Circle &other);

    double getRadius() const;

    virtual void print() const;

    virtual ~Circle() override ;
};

#endif //LABS_OOP_CIRCLE_H