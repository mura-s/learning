#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    const int N = 9;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << setw(3) << i * j;
        }
        cout << endl;
    }
}
