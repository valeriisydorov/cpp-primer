class Shape {

};

class PlanShape : public Shape {

};

class SolidShape : public Shape {

};

class Circle : public PlanShape {

};

class Box : public SolidShape {

};

class Sphere : public SolidShape {

};

class Cone : public SolidShape {

};

int main() {
    return 0;
}
