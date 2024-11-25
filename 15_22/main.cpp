#include <iostream>

class Shape {
public:
    virtual void display() const = 0;
};

class PlanShape : public Shape {
public:
    virtual double getArea() const = 0;
};

class SolidShape : public Shape {
public:
    virtual double getVolume() const = 0;
};

class Circle : public PlanShape {
public:
    void display() const override;
    double getArea() const override;
private:
    double radius;
};

class Box : public SolidShape {
public:
    void display() const override;
    double getVolume() const override;
private:
    double length;
    double width;
    double height;
};

class Sphere : public SolidShape {
public:
    void display() const override;
    double getVolume() const override;
private:
    double radius;
};

class Cone : public SolidShape {
public:
    void display() const override;
    double getVolume() const override;
private:
    double radius;
    double height;
};

int main() {
    return 0;
}
