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

int gcd(int a, int b) {
  if (a < b) {
    return gcd(b, a);
  }

  if (a % b == 0) {
    return b;
  }
  return gcd(b, a % b);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N, X;
  cin >> N >> X;
  vector<int> xs;
  for (int i = 0; i < N; ++i) {
    int xi;
    cin >> xi;
    xs.push_back(xi);
  }

  vector<int> diffs;
  for (auto &e : xs) {
    diffs.push_back(abs(X - e));
  }

  int ans = INT_MAX;
  int first = diffs[0];
  for (int i = 0; i < N; ++i) {
    ans = min(ans, gcd(first, diffs[i]));
  }

  cout << ans << endl;
  return 0;
}