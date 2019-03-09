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

// 部分点解法
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<long> xs(N + 1), ys(N + 1); // 1-indexed
  for (int i = 1; i <= N; ++i) {
    long xi, yi;
    cin >> xi >> yi;
    xs[i] = xi;
    ys[i] = yi;
  }

  bool ok = true;
  long maxd = abs(xs[1]) + abs(ys[1]);
  int parity = (abs(xs[1]) + abs(ys[1])) % 2;
  for (int i = 2; i <= N; ++i) {
    int parity2 = (abs(xs[i]) + abs(ys[i])) % 2;
    if (parity != parity2) {
      ok = false;
    }
    maxd = max(maxd, abs(xs[i]) + abs(ys[i]));
  }

  if (!ok) {
    cout << -1 << endl;
    return 0;
  }
  if (maxd > 40) {
    cout << -1 << endl;
    return 0;
  }

  cout << maxd << endl;
  for (int i = 1; i <= maxd; ++i) {
    cout << 1 << " ";
  }
  cout << endl;

  for (int i = 1; i <= N; ++i) {
    for (int j = 0; j < abs(xs[i]); ++j) {
      if (xs[i] > 0) {
        cout << "R";
      } else {
        cout << "L";
      }
    }

    for (int j = 0; j < abs(ys[i]); ++j) {
      if (ys[i] > 0) {
        cout << "U";
      } else {
        cout << "D";
      }
    }

    for (int j = 0; j + abs(xs[i]) + abs(ys[i]) < maxd; j += 2) {
      cout << "LR";
    }

    cout << endl;
  }

  return 0;
}