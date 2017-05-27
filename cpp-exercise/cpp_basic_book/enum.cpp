#include <iostream>

using namespace std;

enum class choice1 { ROCK, SCISSORS, PAPER };

int main() {
    int r = (int)choice1::PAPER;
    cout << r << endl;
    return 0;
}
