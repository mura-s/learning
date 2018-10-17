#include <iostream>
#include <fstream>

struct V {
    double x;
    double y;
    double z;
    V(double v = 0)
        : V(v, v, v) {}
    V(double x, double y, double z)
        : x(x), y(y), z(z) {}
    double operator[](int i) const {
        return (&x)[i]; // i=0: x, i=1: y, i=2 zを返す
    }
};

int main() {
    const int w = 1200;
    const int h = 800;
    std::ofstream ofs("tmp/result.ppm");
    ofs << "P3\n" << w << " " << h << "\n255\n";

    for (int i = 0; i < w*h; i++) {
        ofs << "255 0 255\n";
    }

    return 0;
}
