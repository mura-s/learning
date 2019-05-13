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
typedef long long ll;

// 約数列挙
vector<int> divisor(int n) {
  vector<int> res;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      res.push_back(i);
      if (i != n / i) {
        res.push_back(n / i);
      }
    }
  }
  return res;
}

int N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  N = 36;

  for (auto &e : divisor(N)) {
    cout << e << endl;
  }
  return 0;
}