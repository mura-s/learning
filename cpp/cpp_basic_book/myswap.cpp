#include <iostream>

using namespace std;

void mySwap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int main() {
    int a = 1;
    int b = 2;

    mySwap(a, b);

    cout << a << endl;
    cout << b << endl;
}
