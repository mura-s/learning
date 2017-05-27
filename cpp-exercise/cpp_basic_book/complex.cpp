#include <iostream>
#include <complex>
#include <memory>

using namespace std;

int main() {
    complex<double> a(1., 2.);
    cout << a.real() << endl;
    cout << a.imag() << endl;

    complex<double>* pb = new complex<double>(3., 4.);
    cout << (*pb).real() << endl;
    cout << pb->imag() << endl;
    delete pb;

    using cplx = complex<double>;
    shared_ptr<cplx> spc = make_shared<cplx>(3., 4.);
    cout << *spc << endl;

    return 0;
}

