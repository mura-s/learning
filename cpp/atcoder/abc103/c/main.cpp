#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

// long gcd(long a, long b) {
//   if (a < b) {
//     return gcd(b, a);
//   }

//   while (a % b != 0) {
//     long tmp = b;
//     b = a % b;
//     a = tmp;
//   }
//   return b;
// }

// long lcm(long a, long b) { return a * b / gcd(a, b); }

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> as;
  for (int i = 0; i < N; ++i) {
    int tmp;
    cin >> tmp;
    as.push_back(tmp);
  }

  int f = 0;
  for (auto &e : as) {
    f += e - 1;
  }
  cout << f << endl;
  return 0;
}