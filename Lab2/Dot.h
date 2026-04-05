#ifndef LABS_OOP_DOT_H
#define LABS_OOP_DOT_H

class Dot {
protected:
    double x, y, z;

public:
    explicit Dot(double x = 0, double y = 0, double z = 0);

    double getX() const;

    double getY() const;

    double getZ() const;

    virtual void print() const;
};

#endif