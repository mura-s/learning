#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, Y;
  cin >> N >> Y;

  // x: 10000, y: 5000, z: 1000
  for (int x = 0; x <= N; x++) {
    for (int y = 0; y <= N - x; y++) {
      int z = N - x - y;
      int sum = 10000 * x + 5000 * y + 1000 * z;
      if (sum == Y) {
        cout << x << " " << y << " " << z << endl;
        return 0;
      }
    }
  }

  cout << "-1 -1 -1" << endl;
  return 0;
}