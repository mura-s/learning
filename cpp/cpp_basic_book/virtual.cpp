#include <iostream>
#include <vector>
using namespace std;

struct Shape {
    virtual void draw() = 0;
};

struct Circle : public Shape {
    void draw() { cout << "○" << endl; }
};

struct Rectangle : public Shape {
    void draw() { cout << "□" << endl; }
};

int main() {
    Circle c;
    c.draw();
    Rectangle r;
    r.draw();

    vector<Shape*> shapes = { &c, &r };
    for (auto s : shapes) {
        s->draw();
    }
}
