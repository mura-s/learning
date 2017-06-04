#include <iostream>
#include <string>
using namespace std;

struct A {
    ~A() {
        cout << "Aは解体された\n";
    }
};

struct Person {
    string name;
    A* pA;

    Person(const string& newName) : name(newName), pA(new A) {}

    ~Person() {
        delete pA;
        cout << name << "は解体された\n";
    }
};

int main() {
    Person person("Taro");
    Person* pPerson = new Person("Jiro");
    delete pPerson;
}
